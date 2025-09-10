g++ \
-std=c++17 \
-Wall \
-ldl \
-I./include \
-I./include/vendors/fltk/include \
-I./lib/windows/FL \
-L./include/vendors/fltk/lib/windows \
./src/* \
-o ./bin/windows/fltkButtonApp.exe \
-lfltk \
-lpthread