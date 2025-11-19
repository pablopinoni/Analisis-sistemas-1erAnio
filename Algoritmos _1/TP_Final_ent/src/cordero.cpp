// cordero.cpp
#include "cordero.hpp"
#include <iostream>

// Constructor
Cordero::Cordero(std::string _nombre, std::string _corte, double _peso, std::string _tipo)
    : Animal(_nombre, _corte, _peso), tipo(_tipo) {
    // Inicializa atributos de Animal y tipo específico de Cordero
}

// Implementación de métodos abstractos (obligatorios)
void Cordero::comer() {
    std::cout << "El cordero " << nombre << " está comiendo hierba." << std::endl;
}

void Cordero::dormir() {
    std::cout << "El cordero " << nombre << " está descansando en el corral." << std::endl;
}

// Métodos específicos de Cordero
std::string Cordero::getTipo() const {
    return tipo;
}

void Cordero::setTipo(const std::string& _tipo) {
    tipo = _tipo;
}