### Clone this repo:

``` gh repo clone Cashtann/CMake-Template ```

# To run this, u need to install microhttpd (for httpserverlib), libpcap and tcdump
### On MacOS using homebrew
``` brew install microhttpd ```
``` brew install libcap ```
``` brew install tcdump```
### On Linux
``` sudo apt-get install libmicrohttpd-dev ```
``` sudo apt-get install libcap-dev ```
``` sudo apt install tcpdump ```

# if sth isnt working with PcapPlusPlus, go to libs/PcapPlusPlus and type
``` cmake -S . -B build ```
` cd build `
` make `



