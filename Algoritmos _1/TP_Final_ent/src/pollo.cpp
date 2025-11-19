// pollo.cpp
#include "pollo.hpp"
#include <iostream>

// Constructor
Pollo::Pollo(std::string _nombre, std::string _corte, double _peso, std::string _tipoPollo)
    : Animal(_nombre, _corte, _peso), tipoPollo(_tipoPollo) {
    // Inicializa atributos de Animal y tipo específico de Pollo
}

// Implementación de métodos abstractos (obligatorios)
void Pollo::comer() {
    std::cout << "El pollo " << nombre << " está picoteando granos." << std::endl;
}

void Pollo::dormir() {
    std::cout << "El pollo " << nombre << " está durmiendo en el gallinero." << std::endl;
}

// Métodos específicos de Pollo
std::string Pollo::getTipoPollo() const {
    return tipoPollo;
}

void Pollo::setTipoPollo(const std::string& _tipoPollo) {
    tipoPollo = _tipoPollo;
}