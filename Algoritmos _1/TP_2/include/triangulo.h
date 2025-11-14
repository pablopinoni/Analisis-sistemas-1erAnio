// triangulo.h

#pragma once

#include "figura.h"

class Triangulo : public Figura {
private:
    // Atributos basados en el UML
    double verticeA_x, verticeA_y;
    double verticeB_x, verticeB_y;
    double verticeC_x, verticeC_y;

public:
    // Constructor
    Triangulo(double ax, double ay, double bx, double by, double cx, double cy, const std::string& nom)
        : Figura(nom),
          verticeA_x(ax), verticeA_y(ay),
          verticeB_x(bx), verticeB_y(by),
          verticeC_x(cx), verticeC_y(cy) {}

    // Destructor
    ~Triangulo() override {}

    // Implementación de métodos virtuales
    void dibujar() const override;
    void borrar() const override;
    
    // Aquí podrías agregar un método para calcular el área del triángulo si lo necesitas.
};