#!/bin/sh
set -xe
gcc -g -w -o main.out main.c tree.c queue.c
./main.out
