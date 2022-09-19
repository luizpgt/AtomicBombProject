#!/bin/sh
set -xe
gcc -g -Og main.c queue.c -o queue_valgrind.out
valgrind ./queue_valgrind.out
