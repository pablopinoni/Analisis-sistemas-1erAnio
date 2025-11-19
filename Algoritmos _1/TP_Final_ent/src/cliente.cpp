// cliente.cpp
#include "cliente.hpp"

// Constructor
Cliente::Cliente(const std::string& _code, const std::string& _name, 
                 const std::string& _address, const std::string& _phone)
    : code(_code), name(_name), address(_address), phone(_phone) {
    // Inicialización de atributos en la lista de inicialización
}

// Getters
std::string Cliente::getCode() const {
    return code;
}

std::string Cliente::getName() const {
    return name;
}

std::string Cliente::getAddress() const {
    return address;
}

std::string Cliente::getPhone() const {
    return phone;
}

// Setters
void Cliente::setCode(const std::string& _code) {
    code = _code;
}

void Cliente::setName(const std::string& _name) {
    name = _name;
}

void Cliente::setAddress(const std::string& _address) {
    address = _address;
}

void Cliente::setPhone(const std::string& _phone) {
    phone = _phone;
}

// Destructor (implícito, no es necesario definirlo explícitamente
// ya que no usamos memoria dinámica)
// ~Cliente() = default;  // Opcional, el compilador lo genera automáticamente