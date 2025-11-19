// cordero.hpp
#pragma once
#include "animal.hpp"
#include <string>

class Cordero : public Animal {
private:
    std::string tipo;  // Ej: "lechal", "novillo", "pastoreado"

public:
    Cordero(std::string _nombre, std::string _corte, double _peso, std::string _tipo);
    
    // Implementación de métodos abstractos
    void comer() override;
    void dormir() override;
    
    // Métodos específicos de Cordero
    std::string getTipo() const;
    void setTipo(const std::string& _tipo);
};