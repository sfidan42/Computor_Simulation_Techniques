#!/bin/bash -e
cd "$(dirname "$0")"
[ ! -d alglib-cpp ] && unzip alglib-4.02.0.cpp.gpl.zip
cp Makefile alglib-cpp 
mv alglib-cpp ../
