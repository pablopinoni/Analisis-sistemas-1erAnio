// cliente.hpp
#pragma once
#include <string>

class Cliente {
private:
    std::string code;
    std::string name;
    std::string address;
    std::string phone;  // ← Añadido: teléfono como en tu UML

public:
    // Constructor
    Cliente(const std::string& _code, const std::string& _name, 
            const std::string& _address, const std::string& _phone);
    
    // Destructor (comentado como indicaste)
    // ~Cliente(); // No necesitamos memoria dinámica

    // Getters
    std::string getCode() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhone() const;  // ← Añadido

    // Setters (opcionales, como en tu UML original)
    void setCode(const std::string& _code);
    void setName(const std::string& _name);
    void setAddress(const std::string& _address);
    void setPhone(const std::string& _phone);
};