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
    //Cosntructor
    Articulo(const std::string& code, const std::string& name, double precio);
    //Destructor
   // ~Articulo(); no usamos memoria dinámica en esta versión comparar con version de nico

    //Getters
    std::string getCode()const;
    std::string getName()const;
    double getPrecio() const;

};


