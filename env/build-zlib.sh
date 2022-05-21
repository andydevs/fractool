#!/bin/bash
cd extern/zlib
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=zlib-install
cmake --build build
cmake --install build