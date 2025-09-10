#!/bin/bash

g++ \
-std=c++17 \
-Wall \
-ldl \
-I./include \
-I./include/vendors/fltk/include \
-I./lib/FL \
-L./include/vendors/fltk/lib/ \
./src/* \
-o ./bin/fltkButtonApp \
-lfltk \
-lpthread
