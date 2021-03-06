#!/bin/bash

cd "$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

if [ -d build ]; then
   rm -rf build
fi

mkdir build

cd src
make main
cd ..

if [ ! -f build/main.out ]; then
    echo 'compile failed'
    exit
fi

for i in {1..10}; do
  build/main.out graph/crazy.txt -q
done
