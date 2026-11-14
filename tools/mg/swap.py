#!/usr/bin/env python3
"""Shared helper: temporarily replace a function's INCLUDE_ASM in src/<seg>.c
with a draft, build only that object, run a callback, then restore."""
import os, shutil, subprocess, tempfile, contextlib

ROOT = subprocess.run(['git', 'rev-parse', '--show-toplevel'], capture_output=True, text=True,
                      cwd=os.path.dirname(os.path.abspath(__file__))).stdout.strip()


@contextlib.contextmanager
def swapped(seg, func, draft_path):
    """Context manager: src/<seg>.c has the draft in place and build/src/<seg>.o is built.
    Yields (object_path, build_errors). Always restores the source and removes the object."""
    src = os.path.join(ROOT, 'src', f'{seg}.c')
    obj = os.path.join(ROOT, 'build', 'src', f'{seg}.o')
    fd, bak = tempfile.mkstemp(suffix='.c'); os.close(fd)
    shutil.copy(src, bak)
    try:
        text = open(src).read()
        key = f'INCLUDE_ASM("asm/nonmatchings/{seg}", {func});'
        if key in text:
            open(src, 'w').write(text.replace(key, open(draft_path).read()))
        if os.path.exists(obj): os.remove(obj)
        r = subprocess.run(['make', f'build/src/{seg}.o'], cwd=ROOT, capture_output=True, text=True)
        errs = [l for l in (r.stdout + r.stderr).splitlines() if ' error' in l.lower() or 'conflicting' in l]
        yield obj, errs
    finally:
        shutil.copy(bak, src); os.remove(bak)
        if os.path.exists(obj): os.remove(obj)
