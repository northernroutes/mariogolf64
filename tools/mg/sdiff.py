#!/usr/bin/env python3
"""sdiff.py <seg> <func> <draft.c>
Unified diff of the original (disassembled from baserom.z64) against our build of the
draft. Branch targets are shown as instruction indices from the function start (so a
branch to a different place shows up); jal targets, %hi values and load/store offsets
are normalised away. src/ is always restored."""
import re, subprocess, sys, difflib
from swap import ROOT, swapped

def parse(text):
    rows = []
    for l in text.splitlines():
        m = re.match(r'^\s+([0-9a-f]+):\t[0-9a-f ]+\t(.*)$', l)
        if m: rows.append((int(m.group(1), 16), m.group(2)))
    return rows

def norm(rows, jbase=None):
    """jbase: address that `j` targets are relative to (ROM: function vram & 0x0FFFFFFF)."""
    if not rows: return []
    base = rows[0][0]; out = []
    for addr, ins in rows:
        ins = re.sub(r'\s*<.*>', '', ins).replace('\t', ' ').strip()
        m = re.match(r'^(b\w*|j)\s+(.*?)(?:0x)?([0-9a-f]+)$', ins)
        if m and not ins.startswith(('jal', 'jr')):
            b = jbase if (m.group(1) == 'j' and jbase is not None) else base
            ins = f'{m.group(1)} {m.group(2)}@{(int(m.group(3), 16) - b) // 4}'
        if ins.startswith('jal '): ins = 'jal'
        ins = re.sub(r'^(lui \w+,)0x[0-9a-f]+$', r'\1HI', ins)
        if re.match(r'^(l|s)[bhwd]', ins) or ins.startswith(('lwc1', 'swc1', 'ldc1', 'sdc1')):
            ins = re.sub(r',-?\d+\((\w+)\)$', r',OFF(\1)', ins)
        out.append(ins)
    return out

def main():
    seg, func, draft = sys.argv[1:4]
    s = open(f'{ROOT}/asm/nonmatchings/{seg}/{func}.s').read()
    offs = re.findall(r'^\s+/\* ([0-9A-F]+) ([0-9A-F]+) [0-9A-F]{8} \*/', s, re.M)
    rom0 = int(offs[0][0], 16); vram0 = int(offs[0][1], 16); n = len(offs)
    A = norm(parse(subprocess.run(['mips-linux-gnu-objdump', '-D', '-z', '-b', 'binary', '-m', 'mips', '-EB',
        f'--start-address={rom0}', f'--stop-address={rom0 + 4 * n}', f'{ROOT}/baserom.z64'],
        capture_output=True, text=True).stdout), jbase=vram0 & 0x0FFFFFFF)
    with swapped(seg, func, draft) as (obj, errs):
        if errs:
            print('COMPILE ERROR'); print('\n'.join(errs[:5])); sys.exit(1)
        B = norm(parse(subprocess.run(['mips-linux-gnu-objdump', '-d', '-z', f'--disassemble={func}', obj],
                                      capture_output=True, text=True).stdout))
    print(f'original {len(A)} vs ours {len(B)}')
    for x in difflib.unified_diff(A, B, lineterm='', n=0):
        if not x.startswith(('---', '+++')): print(x)

if __name__ == '__main__':
    main()
