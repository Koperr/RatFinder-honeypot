#!/bin/sh

# pre-compile (optional)
cd build
make
cd ..

cd bin/Darwin/Debug  
# directory, where the executable file is located, may differ if compiling in Release mode 
# or Debug mode, also depends on OS
./RatFinder
cd ..
