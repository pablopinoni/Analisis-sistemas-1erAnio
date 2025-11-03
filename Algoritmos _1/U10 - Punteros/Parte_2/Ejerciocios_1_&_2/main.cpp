// main.cpp

#include "ej_1.h" // Incluye el prototipo y las definiciones
#include <iostream>

// Los datos de prueba se definen aquí, separados de la lógica de la función.
tArray arrayEj1{12, 13, 34, 22, 67, 87, 80, 31, 23, 6};

int main() {
    std::cout << "___________________________________" << std::endl;
    // La llamada modularizada
    showArrayXPunterosParesImpares(arrayEj1, sizeA); 
     std::cout << "___________________________________" << std::endl;
   //llamada ala segunda función
    std::cout << "El mínimo elemento del array es: " 
    << findMinElement(arrayEj1,  sizeA)
     <<std::endl;

    return 0;
}