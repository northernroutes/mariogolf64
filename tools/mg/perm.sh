#!/bin/bash
# perm.sh start <seg> <func> <draft.c>   import the draft into permuter/<func>/ and run it in the background
# perm.sh status                         list running permuters with their best score so far
# perm.sh stop [func]                    stop one permuter (or all)
# Logs go to permuter/<func>.log; results to permuter/<func>/output-<score>-*/.
ROOT=$(git -C "$(dirname "$0")" rev-parse --show-toplevel); cd "$ROOT" || exit 1
case "$1" in
start)
    seg=$2; f=$3; d=$4
    [ -f "$d" ] || { echo "no draft $d"; exit 1; }
    bak=$(mktemp); cp "src/$seg.c" "$bak"
    python3 - "$seg" "$f" "$d" <<'PY'
import sys
seg, f, d = sys.argv[1:]
p = f'src/{seg}.c'; s = open(p).read(); k = f'INCLUDE_ASM("asm/nonmatchings/{seg}", {f});'
assert k in s, f'{k} not found'
open(p, 'w').write(s.replace(k, open(d).read()))
PY
    rm -rf "permuter/$f"; bash tools/permuter-import.sh "$seg" "$f" 2>&1 | tail -1
    cp "$bak" "src/$seg.c"; rm -f "$bak" "build/src/$seg.o"
    nohup ./venv/bin/python tools/decomp-permuter/permuter.py "permuter/$f" -j8 --stop-on-zero > "permuter/$f.log" 2>&1 &
    echo "started $f (pid $!)"
    ;;
status)
    found=0
    for pid in $(pgrep -f "decomp-permuter/permuter.py"); do
        f=$(ps -o args= -p "$pid" | grep -o 'permuter/[A-Za-z0-9_]*' | tail -1 | sed 's#permuter/##')
        base=$(tr '\r' '\n' < "permuter/$f.log" 2>/dev/null | grep 'base score' | grep -o '[0-9]*$')
        best=$(ls "permuter/$f" 2>/dev/null | grep '^output-' | sed 's/output-//; s/-.*//' | sort -n | head -1)
        echo "$f: running (pid $pid), base ${base:-?}, best ${best:-none}"; found=1
    done
    [ $found = 1 ] || echo "no permuters running"
    ;;
stop)
    if [ -n "$2" ]; then pkill -f "decomp-permuter/permuter.py permuter/$2 "; else pkill -f "decomp-permuter/permuter.py"; fi
    sleep 1; "$0" status
    ;;
*) sed -n '2,5p' "$0"; exit 1 ;;
esac
