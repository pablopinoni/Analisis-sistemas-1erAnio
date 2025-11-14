// figura.h

#pragma once

#include <string>
#include <iostream>

class Figura {
private:
    std::string nombre;

public:
    // Constructor
    Figura(const std::string& nom) : nombre(nom) {}

    // ¡CRÍTICO! Destructor virtual puro. Asegura que se llame al destructor de la subclase
    // al eliminar un puntero Figura*.
    virtual ~Figura() {}

    // 1. Métodos virtuales puros (abstractos): obligan a la implementación en subclases.
    // La notación '= 0' indica que es pura.
    virtual void dibujar() const = 0;
    virtual void borrar() const = 0;

    // 2. Métodos concretos (Comunes)
    void mover() const {
        std::cout << "La figura " << nombre << " se está moviendo." << std::endl;
    }

    void rotar() const {
        std::cout << "La figura " << nombre << " está rotando." << std::endl;
    }

    // Getter
    const std::string& getNombre() const {
        return nombre;
    }
};