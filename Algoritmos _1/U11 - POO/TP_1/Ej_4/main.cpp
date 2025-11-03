#include <iostream>
#include "persona.h"

int main(){

 Persona Persona_1;
int dN, mN, aN, dA, mA, aA;


std::cout << "===================================\n"
          << "\tIngreso de datos\n"
          << "===================================\n";

std::string nom;
   std::cout << "Ingrese nombre de la persona: ";
   std::getline(std::cin, nom);
 Persona_1.SetNombre( nom);

 //Fecha de nacimiento
 std::cout << "Ingrese día de nacimiento: \n";
 std::cin>> dN;
 Persona_1.SetDia(dN);

std::cout << "Ingrese mes de nacimiento: \n";
 std::cin>> mN;
 Persona_1.SetMes(mN);

 std::cout<< "Ingrese año de nacimiento: \n";
 std::cin>> aN;
 Persona_1.SetAnio(aN);


 //Fecha actual 
std::cout << "Ingrese día actual: \n";
 std::cin>> dA;
 Persona_1.SetDiaAct(dA);

std::cout << "Ingrese mes actual: \n";
 std::cin>> mA;
 Persona_1.SetMesAct(mA);

 std::cout<< "Ingrese año actual:\n";
 std::cin>> aA;
 Persona_1.SetAnioAct(aA);


std::cout << "\n\n===================================\n"
          << "\tResultados\n"
          << "===================================\n";


     std:: cout << Persona_1.GetNombre() << " tiene "
                << Persona_1.CalcEdad() << " años."
                << std::endl;

     return 0;
}     