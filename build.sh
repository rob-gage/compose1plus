#!/usr/bin/env bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

RUNTIME_DIR="$SCRIPT_DIR/runtime"
BUILD_DIR="$SCRIPT_DIR/target"
OUTPUT="$BUILD_DIR/c1+rt"

mkdir -p "$BUILD_DIR"
mapfile -t SOURCE_FILES < <(find "$RUNTIME_DIR" -name "*.c")
cc -std=c11 -O2 -Wall -Wextra \
   -I"$RUNTIME_DIR" \
   "${SOURCE_FILES[@]}" \
   -o "$OUTPUT"
