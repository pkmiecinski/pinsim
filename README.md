# pinsim

<i>Pinsim is small terminal application for testing RPI-compatibile GPIO interactions.</i>



## Build instructions:
~~~bash
mkdir build
cd build
cmake ..
make -j
~~~

## Run instructions:
~~~bash
cd build
./pinsim
~~~

## Dependencies:

* FTXUI </br> 
https://github.com/ArthurSonzogni/FTXUI
* Nlohmann JSON </br>
 https://github.com/nlohmann/json 

All dependencies are resolved by cmake fetch contnent. 

## Usage instructions:
 
* for setting pin high press 'q'
* for setting pin low press 'w'
* for exit app press 'e'
* hint: expand your terminal horizontally since app uses 160 columns


## Tested on:

* compilers: clang-1500.3.9.4, gcc-9.4.0 
* OS: MacOS Sonoma, Ubuntu 20.04.3 LTS
* architecture: aarch64