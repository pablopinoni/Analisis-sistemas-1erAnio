// ternera.hpp
#pragma once
#include "animal.hpp"
#include <string>

// ternera.hpp
#pragma once
#include "animal.hpp"
#include <string>

class Ternera : public Animal {
private:
    std::string raza;

public:
    Ternera(std::string _nombre, std::string _corte, double _peso, std::string _raza);
    
    void comer() override;
    void dormir() override;
    
    std::string getRaza() const;
    void setRaza(const std::string& _raza);
};