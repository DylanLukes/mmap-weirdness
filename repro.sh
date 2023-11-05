#!/bin/bash

cc -o mmap-test mmap-test.c
cc -o dummy dummy.c

# Fails with EPERM from mmap.
echo -e "Running mmap-test without running dummy."
./mmap-test

# Succeeds ???
echo -e "\nRunning mmap-test after running dummy."
./dummy
./mmap-test