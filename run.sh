#!/usr/bin/env bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

BUILD_DIR="$SCRIPT_DIR/target"
OUTPUT="$BUILD_DIR/c1+rt"

"$OUTPUT"