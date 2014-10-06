#!/bin/bash
set -eu

make clean

for i in $(ls -d */)
do
    printf "\n$i\n"
    cd $i
    make test
    cd ..
done
