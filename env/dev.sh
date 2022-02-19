ROOT_PATH=$(pwd)
export PATH="$PATH:$ROOT_PATH/build/test-install/bin"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$ROOT_PATH/build/test-install/lib"
alias configure="cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$ROOT_PATH/build/test-install"