#pragma once
#include <string>

class Empleado {
private:
    std::string code;
    std::string name;
    float comisionPercent;

public:
    Empleado(const std::string& code, const std::string& name, float comisionPercent);

    std::string getCode() const;
    std::string getName() const;
    float getComisionPercent() const;
};