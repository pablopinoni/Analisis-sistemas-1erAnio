
#include "articulo.h"
#include <iostream>
#include <string>
//Constructor
Articulo::Articulo(const std::string& code, const std::string& name, double precio):
code(code),
name(name),
precio(precio){


    std::cout  << "Artículo inicializado" << std::endl;
 }





std::string Articulo::getCode()const{

    return this->code;

}


std::string Articulo::getName()const{

return  this->name;

}

double Articulo::getPrecio()const{

return  this->precio;

}

