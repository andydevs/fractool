ROOT_PATH=$(pwd)
export PATH="$PATH:$ROOT_PATH/build/test-install/bin"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$ROOT_PATH/build/test-install/lib"
alias configure="cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$ROOT_PATH/build/test-install"
alias build="cmake --build build"
alias install="cmake --install build"