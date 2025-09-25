#!/bin/bash
# con -I./include incluyo el directorio include donde se encuentran los archivos .h o .hpp
# con ./src/*.cpp incluyo todos los archivos .cpp que se encuentran en el directorio ./src 
#(tener en cuenta que sean del proyecto sino hay que especificarlos uno a uno)
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -I./include ./src/*.cpp -o app.bin  

# para dar permisos de ejecucion al ejecutable
chmod +x app.bin    

# ejecuto el ejecutable
./app.bin
