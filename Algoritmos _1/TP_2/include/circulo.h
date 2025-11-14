// circulo.h

#pragma once

#include "figura.h"

class Circulo : public Figura {
private:
    double radio;

public:
    // Constructor: llama al constructor base (Figura::Figura)
    Circulo(double r, const std::string& nom) : Figura(nom), radio(r) {}

    // Destructor: la palabra 'override' es opcional, pero buena práctica.
    ~Circulo() override {}

    // Implementación de los métodos virtuales
    void dibujar() const override;
    void borrar() const override;

    // Método propio
    double calcularArea() const {
        return 3.1415926535 * radio * radio;
    }
};