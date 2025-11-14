// src/rectangulo.cpp

#include "../include/rectangulo.h"
#include <iostream>

void Rectangulo::dibujar() const {
    std::cout << "[Rectángulo] Dibujando '" << getNombre() << "' (B:" << base << ", A:" << altura << ")." << std::endl;
}

void Rectangulo::borrar() const {
    std::cout << "[Rectángulo] Borrando '" << getNombre() << "'." << std::endl;

}