#include <iostream>
#include "rectangulo.h"

//Constructor
Rectangulo::Rectangulo():
h(0.0f),
b(0.0f)
{
std::cout << "Recatngulo inicializado." << std::endl;

}

//Destructor//Destructor
Rectangulo::~Rectangulo(){

std::cout << "Objeto Rectángulo destruido." << std::endl;

}

void Rectangulo::SetAltura(float h1){
    this->h=h1;
}
float Rectangulo::GetAltura()const{
   return this->h;

}
void Rectangulo::SetBase(float b1){
    this->b=b1;
}
float Rectangulo::GetBase ()const{
    return this->b;
}
float Rectangulo::Area()const{
float base = this->b;
float alt = this->h;
    return alt*base;
}
float Rectangulo::Perimetro()const{
   return (2.0f * this->h) + (2.0f * this->b);
}