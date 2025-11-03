#include <iostream>
#include <string>
#include "persona.h"

//Constructor
Persona::Persona():
nombre(""),
dia(0),
 mes(0),
 anio (0),
 diaAct(0),
 mesAct(0),
 anioAct(0){


    std::cout  << "Objeto persona inicializado" << std::endl;
 }

 Persona::~Persona(){

     std::cout  << "Objeto persona destriodo." << std::endl;


 }


void Persona::SetNombre(std::string nom){
    this->nombre=nom;
}
std::string Persona::GetNombre()const{

    return this->nombre;

}

void Persona::SetDia(int d){
this->dia=d;

}
int Persona::GetDia()const{

return  this->dia;

}

void Persona::SetMes(int m){
    this->mes=m;
}
int Persona::GetMes()const{

    return this->mes;
}

void Persona::SetAnio(int a){

    this->anio=a;
}
int Persona::GetAnio()const{

    return this->anio;
}
int Persona::CalcEdad()const{

if (this->mes < this->mesAct) {
return this->anioAct - this->anio;
}
else if (this->mes == this->mesAct && this->dia <= this->diaAct){

 return this->anioAct - this->anio;   
}
else {
    return this->anioAct - this->anio -1;   
}

}

void Persona::SetDiaAct(int d){
    this->diaAct=d;
}
int Persona::GetDiaAct()const{

    return this->diaAct;
}
void Persona::SetMesAct(int m){
this->mesAct=m;
}
int Persona::GetMesAct()const{
    return this->mesAct;
}
void Persona::SetAnioAct(int a){
    this->anioAct=a;
}
int Persona::GetAnioAct()const{

    return this->anioAct;
}


