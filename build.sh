#!/usr/bin/env bash

if [ -e build ]; then
  rm -rf build
  mkdir build
else
  mkdir build
fi

cd build
cmake ..
make
