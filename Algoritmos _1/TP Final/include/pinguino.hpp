// pinguino.hpp
#pragma once
#include "animal.hpp"
#include <string>

class Pinguino : public Animal {
private:
    std::string distribucion;  // Ej: "Tux", "Ubuntu", "Debian", "Fedora" (broma GNU/Linux)

public:
    Pinguino(std::string _nombre, std::string _corte, double _peso, std::string _distribucion);
    
    // Implementación de métodos abstractos
    void comer() override;
    void dormir() override;
    
    // Métodos específicos de Pinguino
    std::string getDistribucion() const;
    void setDistribucion(const std::string& _distribucion);
};