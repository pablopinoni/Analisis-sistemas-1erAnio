#include "articulo.h"
#include <iostream>
#include <string>

// Implementación del Constructor por defecto (NECESARIA PARA Pedido)
Articulo::Articulo() :
code(""),
name(""),
precio(0.0)
{
    // Deja el cuerpo vacío o con un comentario
}

// Implementación del Constructor con parámetros (el original)
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