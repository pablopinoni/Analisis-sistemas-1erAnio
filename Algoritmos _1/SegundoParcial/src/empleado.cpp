#include "../include/empleados.h"

// Constructor
Empleado::Empleado(const std::string& code, const std::string& name, float comisionPercent)
    : code(code), name(name), comisionPercent(comisionPercent) {
}

// Getters
std::string Empleado::getCode() const {
    return code;
}

std::string Empleado::getName() const {
    return name;
}

float Empleado::getComisionPercent() const {
    return comisionPercent;
}