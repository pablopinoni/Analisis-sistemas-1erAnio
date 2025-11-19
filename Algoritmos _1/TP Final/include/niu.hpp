// niu.hpp
#pragma once

#include "animal.hpp"
#include <string>

class Niu : public Animal {
private:
    std::string color;

public:
    Niu(std::string _nombre, std::string _corte, double _peso, std::string _color);

    void comer() override;
    void dormir() override;

    std::string getColor() const;
    void setColor(const std::string& _color);
};