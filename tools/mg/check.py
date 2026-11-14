#!/usr/bin/env python3
"""check.py <seg> <func> <draft.c> [-v]
Builds src/<seg>.c with <func>'s INCLUDE_ASM replaced by the draft and compares the
function's words against the original (asm/nonmatchings), ignoring only the fields a
relocation fills (low 16 bits for HI16/LO16, 26 for jumps). Prints OK or DIFF.
-v prints our disassembly. src/ is always restored.
A full `make` must still confirm a match (relocation addends are not checked)."""
import re, subprocess, sys
from swap import ROOT, swapped

def target_words(seg, func):
    s = open(f'{ROOT}/asm/nonmatchings/{seg}/{func}.s').read()
    return [int(w, 16) for w in re.findall(r'^\s+/\* [0-9A-F]+ [0-9A-F]+ ([0-9A-F]{8}) \*/', s, re.M)]

def object_words(obj, func):
    out = subprocess.run(['mips-linux-gnu-objdump', '-dr', '-z', f'--disassemble={func}', obj],
                         capture_output=True, text=True).stdout
    words = []
    for line in out.splitlines():
        m = re.search(r'R_MIPS_(\w+)', line)
        if m and words:
            w, _ = words[-1]
            words[-1] = (w, ~0x3FFFFFF & 0xFFFFFFFF if m.group(1) == '26' else 0xFFFF0000)
        elif re.match(r'^\s+[0-9a-f]+:\s+[0-9a-f]{8}\b', line):
            words.append((int(line.split()[1], 16), 0xFFFFFFFF))
    return words, out

def main():
    seg, func, draft = sys.argv[1:4]
    with swapped(seg, func, draft) as (obj, errs):
        if errs:
            print(f'{func} COMPILE ERROR'); print('\n'.join(errs[:5])); sys.exit(1)
        ours, dis = object_words(obj, func)
    tgt = target_words(seg, func)
    while tgt and tgt[-1] == 0 and len(tgt) > len(ours): tgt.pop()   # trailing alignment nops
    while ours and ours[-1][0] == 0 and len(ours) > len(tgt): ours.pop()
    if '-v' in sys.argv:
        print('\n'.join(l for l in dis.splitlines() if re.match(r'^\s+[0-9a-f]+:', l)))
    if len(tgt) != len(ours):
        print(f'{func} DIFF (length {len(ours)} vs {len(tgt)})'); return
    bad = [i for i, (t, (w, m)) in enumerate(zip(tgt, ours)) if (t & m) != (w & m)]
    print(f'{func} OK' if not bad else f'{func} DIFF ({len(bad)} words, first at {bad[0]})')

if __name__ == '__main__':
    main()
