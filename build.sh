#!/bin/bash

gcc -o output pointers.c -L/usr/lib/libc.so -lm

./output
