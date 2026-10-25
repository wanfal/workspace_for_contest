#!/bin/bash
CHECK=./files/check_linux
SOL=./main
for t in tests/*; do
    case "$t" in *.a|*.ans) continue ;; esac
    ans="$t.a"; [ -f "$ans" ] || ans="$t.ans"
    "$SOL" < "$t" > /tmp/out.txt
    "$CHECK" "$t" /tmp/out.txt "$ans"
done
