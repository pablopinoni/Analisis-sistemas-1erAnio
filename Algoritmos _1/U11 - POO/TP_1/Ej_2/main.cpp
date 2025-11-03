#include <iostream>
#include <string>
#include "alumnos.h"

int main(){
    Alumno Alumno_1;
std::cout << "===================================\n"
          << "\tIngreso de datos\n"
          << "===================================\n";

   std::string ced;
   std::cout << "Ingrese cédula del alumno: ";
   std::getline(std::cin, ced);
   Alumno_1.SetCedula(ced);


   std::string nom;
   std::cout << "Ingrese nombre del alumno: ";
   std::getline(std::cin, nom);
   Alumno_1.SetName( nom);



std::cout << "Ingrese nota 1: ";
float no1;
std::cin >>no1;
Alumno_1.SetNota1(no1);

std::cout << "Ingrese nota 2: ";
float no2;
std::cin >>no2;
Alumno_1.SetNota2( no2);

std::cout << "Ingrese nota 3: ";
float no3;
std::cin >>no3;
Alumno_1.SetNota3( no3);

//Nota final

std::cout << "La notal final es: " << Alumno_1.NotaFinal();
std::cout << "\nEl alumno " << Alumno_1.GetName()
          << " ha " << Alumno_1.AproRepro();
}