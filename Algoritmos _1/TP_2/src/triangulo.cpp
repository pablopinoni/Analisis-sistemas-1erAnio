// src/triangulo.cpp

#include "../include/triangulo.h"
#include <iostream>

void Triangulo::dibujar() const {
    std::cout << "[Triángulo] Dibujando '" << getNombre() << "' con vértices A("
              << verticeA_x << ", " << verticeA_y << ")..." << std::endl;
}

void Triangulo::borrar() const {
    std::cout << "[Triángulo] Borrando '" << getNombre() << "'." << std::endl;

}