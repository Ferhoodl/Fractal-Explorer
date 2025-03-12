#!/bin/sh

BASEDIR="$(dirname "$0")"
CFLAGS="-O3 -g -std=c99 -Wall -Werror"
LDFLAGS="-lm"
DEST="$BASEDIR/../src/main.c"
OUT="$BASEDIR/../bin/main"

gcc $DEST -o $OUT $CFLAGS $LDFLAGS
