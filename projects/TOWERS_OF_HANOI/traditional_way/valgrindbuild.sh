#!/bin/sh
set -xe
gcc -g -Og main.c stack.c -o towerofhanoi_trad.out 
valgrind ./towerofhanoi_trad.out
