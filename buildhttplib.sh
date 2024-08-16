cd lib httpserver
./bootstrap
mkdir build
cd build
../configure
make
make install # (optionally to install on the system)

brew install libmicrohttpd # MacOS
sudo apt insall libmicfohttpd # Linux