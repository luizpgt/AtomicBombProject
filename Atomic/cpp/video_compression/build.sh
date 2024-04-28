#!/bin/sh
set -xe
gcc -Wall -o main.out main.c
./main.out
rm main.out
