#!/bin/sh
set -xe
gcc -Wall -Wextra -o main.out main.c tree.c queue.c
./main.out
