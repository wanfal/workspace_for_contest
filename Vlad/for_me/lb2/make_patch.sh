#!/bin/bash

if [ -z "$1" ]; then
    echo "Path is not provided"
    exit 1
fi

tmp_dir=$(mktemp -d)

diff -ruN "$tmp_dir" "$1" > src.patch

rm -r "$tmp_dir"