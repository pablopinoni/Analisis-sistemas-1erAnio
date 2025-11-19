// animal.hpp
#pragma once

#include <string>

class Animal {
protected:
    std::string nombre;
    std::string corte;
    double peso;

public:
    // Constructor
    Animal(std::string _nombre, std::string _corte, double _peso);
    
    // Destructor virtual (buena práctica con clases abstractas)
    virtual ~Animal() = default;

    // Getters
    std::string getNombre() const;
    std::string getCorte() const;
    double getPeso() const;

    // Setters
    void setNombre(const std::string& _nombre);
    void setCorte(const std::string& _corte);
    void setPeso(double _peso);

    // Métodos virtuales puros (abstractos)
    virtual void comer() = 0;
    virtual void dormir() = 0;
};