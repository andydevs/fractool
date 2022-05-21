#!/bin/bash
echo "Building boost..."
cd extern/boost
./bootstrap.sh
./b2 link=static
./b2 install --prefix=boost-install