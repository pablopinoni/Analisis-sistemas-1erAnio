#pragma once
#include <string>

class Articulo{
    //Atributos
    private:
    std::string code;
    std::string name;
    double precio;

    //Metodos 
    public:
    // Constructor por defecto
    Articulo(); 
    // Constructor con parámetros
    Articulo(const std::string& code, const std::string& name, double precio);

    //Getters (SOLO LAS FIRMAS AQUÍ)
    std::string getCode()const;
    std::string getName()const; // <-- SIN CUERPO
    double getPrecio() const;

};