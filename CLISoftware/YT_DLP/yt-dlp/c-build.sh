#!/bin/sh
set -xe
gcc -Wall -O0 -g -Wextra -o main.out main.c
./main.out
