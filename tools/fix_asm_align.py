#!/usr/bin/env python3
"""Insert `.align 2` after every `.section .text` in asm/nonmatchings/**.s.

KMC as 2.6 (tools/cc/as) occasionally 8-aligns the first label after a switch
from .rodata back to .text: its MIPS auto-alignment state is not reliably reset
across the section change, so the result varies from run to run (about 1 in 10
builds of 207E0.o put a nop before func_80047E9C). An explicit `.align 2`
resets it; it costs nothing because everything in .text is already 4-aligned.
Run after every splat extract (the Makefile's extract target does this)."""
import glob, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
n = 0
for path in glob.glob(f'{ROOT}/asm/nonmatchings/**/*.s', recursive=True):
    lines = open(path).read().split('\n')
    out = []
    changed = False
    for i, line in enumerate(lines):
        out.append(line)
        if line.strip() == '.section .text' and (i + 1 >= len(lines) or lines[i + 1].strip() != '.align 2'):
            out.append('.align 2')
            changed = True
    if changed:
        open(path, 'w').write('\n'.join(out))
        n += 1
print(f'fix_asm_align: patched {n} files')
