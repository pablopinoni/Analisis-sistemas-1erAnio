// rectangulo.h

#pragma once

#include "figura.h"

class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    // Constructor
    Rectangulo(double b, double h, const std::string& nom) : Figura(nom), base(b), altura(h) {}

    // Destructor
    ~Rectangulo() override {}

    // Implementación de métodos virtuales
    void dibujar() const override;
    void borrar() const override;

    // Método propio
    double calcularArea() const {
        return base * altura;
    }
};