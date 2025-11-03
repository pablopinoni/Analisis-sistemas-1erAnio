#include <iostream>
#include "articulos.h"

//Constructor 
Articulo::Articulo():costoBase(0.0f){


std::cout << "Ejecuto constructor de Artículo."  << std::endl;
}
//Destructor
Articulo::~Articulo(){

std::cout << "Articulo destruido." << std::endl;

}

void Articulo::SetCostoBase(float CB){

  // 2. Uso Explícito: Claramente referencia al miembro del objeto actual
    this->costoBase = CB;

}

float Articulo::GetCostoBase()const{
    
return this->costoBase;

}
float Articulo::PVPMayor()const{
    //Accedo con puntero al costo base e incremento 15%

    return this->costoBase *1.15;
}
float Articulo::PVPDetail()const{
//Incremento 30%
return this->costoBase *1.3;

};

