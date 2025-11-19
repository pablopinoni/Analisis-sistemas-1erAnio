// pinguino.cpp
#include "pinguino.hpp"
#include <iostream>

// Constructor
Pinguino::Pinguino(std::string _nombre, std::string _corte, double _peso, std::string _distribucion)
    : Animal(_nombre, _corte, _peso), distribucion(_distribucion) {
    // Inicializa atributos de Animal y distribución específica de Pinguino
}

// Implementación de métodos abstractos (obligatorios)
void Pinguino::comer() {
    std::cout << "El pingüino " << nombre << " está comiendo pescado fresco (como Tux)." << std::endl;
}

void Pinguino::dormir() {
    std::cout << "El pingüino " << nombre << " está durmiendo en su hábitat (sin necesidad de Windows)." << std::endl;
}

// Métodos específicos de Pinguino
std::string Pinguino::getDistribucion() const {
    return distribucion;
}

void Pinguino::setDistribucion(const std::string& _distribucion) {
    distribucion = _distribucion;
}