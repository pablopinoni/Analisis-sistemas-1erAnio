#include "niu.hpp" // ¡Importante! Incluir el .hpp para conocer la clase
#include <iostream>

/**
 * @brief Constructor de Niu.
 * Llama al constructor de la clase base Animal para inicializar nombre, corte y peso.
 * Inicializa el atributo específico 'color'.
 */
Niu::Niu(std::string _nombre, std::string _corte, double _peso, std::string _color)
    : Animal(_nombre, _corte, _peso), color(_color) {
    std::cout << "Ñu creado: " << nombre << " (" << color << ")" << std::endl;
}

// Implementación del método virtual comer()
void Niu::comer() {
    std::cout << "El Ñu " << nombre << " de color " << color << " está rumiando pasto con calma." << std::endl;
}

// Implementación del método virtual dormir()
void Niu::dormir() {
    std::cout << "El Ñu " << nombre << " está durmiendo profundamente, listo para el día." << std::endl;
}

// Getter para el atributo específico 'color'
std::string Niu::getColor() const {
    return color;
}

// Setter para el atributo específico 'color'
void Niu::setColor(const std::string& _color) {
    color = _color;
}