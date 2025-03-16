#!/bin/sh
set -xe
gcc -Wall -Wextra -o towerofhanoi_trad.out main.c stack.c
./towerofhanoi_trad.out
