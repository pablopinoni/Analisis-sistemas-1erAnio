// src/circulo.cpp

#include "../include/circulo.h"
#include <iostream>

void Circulo::dibujar() const {
    std::cout << "[Círculo] Dibujando '" << getNombre() << "' con radio: " << radio << "." << std::endl; 
   
}
void Circulo::borrar() const {
    std::cout << "[Círculo] Borrando '" << getNombre() << "'." << std::endl;
}