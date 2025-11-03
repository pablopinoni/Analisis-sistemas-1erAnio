#include <iostream>
#include <string>
#include "alumnos.h"

//Constructor 
Alumno::Alumno():
 cedula(""),
nombre  (""),
nota_1 (0.0f),
nota_2(0.0f),
nota_3 (0.0f){
std::cout << "Ejecuto constructor de alumno e inicializamos sus atributos ."  << std::endl;
}


//Destructor
Alumno::~Alumno(){

std::cout << "Objeto Alumno destruido." << std::endl;

}
//Setters y getters

void Alumno::SetCedula(std::string ced){
this->cedula = ced;
} 
std::string Alumno::GetCedula()const{
 return this->cedula;
}
void Alumno::SetName(std::string nom){
 this->nombre =nom;
} 
std::string Alumno::GetName()const{
  return this->nombre;

}
void Alumno::SetNota1(float n1){
  this->nota_1=n1 ;
}
float Alumno::GetNota1()const{
    return this->nota_1;
}

void Alumno::SetNota2(float n2){
  this->nota_2=n2;;
}
float Alumno::GetNota2()const{
    return this->nota_2;
}

void Alumno::SetNota3(float n3){
  this->nota_3=n3 ; 
}
float Alumno::GetNota3()const{
    return this->nota_3;
}

//Nota final
float Alumno::NotaFinal()const{
return (this->nota_1 + this->nota_2 + this->nota_3)/3.0;

}


//Aprobado Desaprobado
std::string Alumno::AproRepro()const{
float prom = this->NotaFinal();
if (prom>=48) {
    return "Aprobado\n";

   }
else {
 
 return   "Desaprobado\n ";


   }

}






