#!/usr/bin/env python3
"""rodata_ranges.py [seg ...]
For every unmigrated rodata blob (asm/data/*.rodata.s), list each data label with the
code segments that reference it (asm/nonmatchings/<seg>/*.s, src/<seg>.c, and .data
tables), then print the contiguous run of labels each requested segment owns as a
ROM range -- the bounds for a [rom, .rodata, <seg>] yaml subsegment.

Labels nobody references are shown as '?'; a run is only reported as clean if the
labels just outside it belong to other segments (check '?' neighbours by hand)."""
import glob, os, re, sys
from collections import defaultdict
from swap import ROOT

def refs():
    users = defaultdict(set)
    for f in glob.glob(f'{ROOT}/asm/nonmatchings/*/*.s'):
        seg = os.path.basename(os.path.dirname(f))
        text = open(f).read()
        text = text[text.rfind('.section .text'):] if '.section .text' in text else text
        for sym in set(re.findall(r'\b(D_[0-9A-F]{8}|jtbl_[0-9A-F]{8})\b', text)):
            users[sym].add(seg)
    for f in glob.glob(f'{ROOT}/src/*.c'):
        seg = os.path.basename(f)[:-2]
        for sym in set(re.findall(r'\b(D_[0-9A-F]{8}|jtbl_[0-9A-F]{8})\b', open(f).read())):
            users[sym].add(seg)
    for f in glob.glob(f'{ROOT}/asm/data/*.data.s'):
        for sym in set(re.findall(r'\.word (D_[0-9A-F]{8})', open(f).read())):
            users[sym].add('(data)')
    return users

def labels():
    out = []
    for f in sorted(glob.glob(f'{ROOT}/asm/data/*.rodata.s')):
        cur = None
        for line in open(f):
            m = re.match(r'dlabel (\w+)', line)
            if m:
                cur = m.group(1)
                continue
            m = re.match(r'\s+/\* ([0-9A-F]+) ([0-9A-F]+) ', line)
            if m and cur:
                out.append((int(m.group(1), 16), int(m.group(2), 16), cur))
                cur = None
    return out

def main():
    users = refs()
    labs = labels()
    want = set(sys.argv[1:])
    owner = []
    for rom, vram, lab in labs:
        segs = users.get(lab, set())
        owner.append((rom, vram, lab, ','.join(sorted(segs)) or '?'))
    for seg in sorted(want):
        idx = [i for i, o in enumerate(owner) if seg in o[3].split(',')]
        if not idx:
            print(f'{seg}: no labels in unmigrated rodata'); continue
        lo, hi = idx[0], idx[-1]
        mixed = [o for o in owner[lo:hi + 1] if seg not in o[3].split(',')]
        nxt = owner[hi + 1] if hi + 1 < len(owner) else None
        prev = owner[lo - 1] if lo > 0 else None
        fmt = lambda o: f'{o[2]}[{o[3]}]' if o else '(start)'
        end = f'0x{nxt[0]:X}' if nxt else '(end of blobs)'
        print(f'{seg}: rom 0x{owner[lo][0]:X}-{end} (vram 0x{owner[lo][1]:X})'
              f'  prev={fmt(prev)} next={fmt(nxt)}')
        for o in mixed:
            print(f'    inside but not {seg}: {o[2]} [{o[3]}]')

if __name__ == '__main__':
    main()
