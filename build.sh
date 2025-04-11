#!/bin/bash
mkdir build
cd build || exit
cmake .. && make
echo Processo Terminato!
