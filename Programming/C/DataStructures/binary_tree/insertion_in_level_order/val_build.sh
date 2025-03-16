#!/bin/sh
set -xe
gcc -Wall -Wextra -g -Og -o main.out main.c tree.c queue.c
./main.out
