#!/bin/sh
set -xe
gcc -Wall -Wextra main.c queue.c -o main.out
./main.out
