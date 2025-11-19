#include "animal.hpp"
#include <iostream>

// Constructor
Animal::Animal(std::string _nombre, std::string _corte, double _peso)
    : nombre(_nombre), corte(_corte), peso(_peso) {
    // Inicialización de atributos en la lista de inicialización
}

// Destructor virtual: Necesita una definición, incluso si está vacío
//Animal::~Animal() {}

// Getters
std::string Animal::getNombre() const {
    return nombre;
}

std::string Animal::getCorte() const {
    return corte;
}

double Animal::getPeso() const {
    return peso;
}

// Setters
void Animal::setNombre(const std::string& _nombre) {
    nombre = _nombre;
}

void Animal::setCorte(const std::string& _corte) {
    corte = _corte;
}

void Animal::setPeso(double _peso) {
    peso = _peso;
}
// Los métodos virtuales puros (comer y dormir) se implementan en las clases derivadas.