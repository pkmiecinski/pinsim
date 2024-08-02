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
* hint: expand your terminal horizontally since app uses 160 columns

