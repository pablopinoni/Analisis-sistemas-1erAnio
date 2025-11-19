// ternera.cpp
#include "ternera.hpp"
#include <iostream>

// Constructor
Ternera::Ternera(std::string _nombre, std::string _corte, double _peso, std::string _raza)
    : Animal(_nombre, _corte, _peso), raza(_raza) {
    // Inicializa atributos de Animal y raza específica de Ternera
}

// Implementación de métodos abstractos (obligatorios)
void Ternera::comer() {
    std::cout << "La ternera " << nombre << " está comiendo pasto fresco." << std::endl;
}

void Ternera::dormir() {
    std::cout << "La ternera " << nombre << " está descansando en el prado." << std::endl;
}

// Métodos específicos de Ternera
std::string Ternera::getRaza() const {
    return raza;
}

void Ternera::setRaza(const std::string& _raza) {
    raza = _raza;
}