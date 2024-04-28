#!/bin/sh
set -xe
g++ -Wall -o code.out code.cpp
./code.out
rm code.out
