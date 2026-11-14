#!/usr/bin/env python3
"""apply_pipeline.py <seg> [<seg> ...]
Install every function the pipeline matched (permuter/pipeline/<seg>/report.txt) whose
draft needs no m2c helper macros other than M2C_UNK (mapped to plain s8/s16/s32/s64).
Declarations are kept as written (identical duplicates are legal C; conflicts show up
in the build). Lists drafts that still use macros, for hand typing. No build is run."""
import os, re, sys
ROOT = os.popen(f'git -C {os.path.dirname(os.path.abspath(__file__))} rev-parse --show-toplevel').read().strip()
os.chdir(ROOT)
for seg in sys.argv[1:]:
    rep = f'permuter/pipeline/{seg}/report.txt'
    if not os.path.exists(rep): print(f'{seg}: no report'); continue
    p = f'src/{seg}.c'; s = open(p).read(); done, manual = [], []
    for line in open(rep):
        m = re.match(r'^(\w+)\s+\d+\s+.*?: MATCH', line)
        if not m: continue
        f = m.group(1); key = f'INCLUDE_ASM("asm/nonmatchings/{seg}", {f});'
        if key not in s: continue
        d = open(f'permuter/pipeline/{seg}/{f}.c').read()
        for n, t in (('8', 's8'), ('16', 's16'), ('32', 's32'), ('64', 's64')):
            d = d.replace(f'M2C_UNK{n}', t)
        d = d.replace('M2C_UNK', 's32')
        if 'M2C_' in d: manual.append(f); continue
        d = '\n'.join(re.sub(r'\s*/\* (extern|irregular) \*/\s*$', '', l) for l in d.splitlines())
        s = s.replace(key, d.strip('\n')); done.append(f)
    open(p, 'w').write(s)
    print(f'{seg}: applied {len(done)}' + (f'; needs hand typing: {" ".join(manual)}' if manual else ''))
