// pollo.hpp
#pragma once
#include "animal.hpp"
#include <string>

class Pollo : public Animal {
private:
    std::string tipoPollo;  // Ej: "broiler", "parrillero", "criollo"

public:
    Pollo(std::string _nombre, std::string _corte, double _peso, std::string _tipoPollo);
    
    // Implementación de métodos abstractos
    void comer() override;
    void dormir() override;
    
    // Métodos específicos de Pollo
    std::string getTipoPollo() const;
    void setTipoPollo(const std::string& _tipoPollo);
};