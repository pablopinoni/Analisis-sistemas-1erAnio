#include <iostream>
#include "rectangulo.h"

int main(){

 Rectangulo Rectangulo1;



std::cout << "===================================\n"
          << "\tIngreso de datos\n"
          << "===================================\n";

std::cout << "Ingrese la altura del rectángulo: ";
float height;
std::cin >>height   ;
Rectangulo1.SetAltura(height);

std::cout << "Ingrese la base del rectágulo: ";
float bas;
std::cin >>bas;
Rectangulo1.SetBase(bas);


//Imprimir resultados//
 std::cout << "===================================\n"
          << "\tResultados\n"
          << "===================================\n"

          << "El área del rectangulos es " << Rectangulo1.Area() 
          << "\n El perímetro del rectangulos es " << Rectangulo1.Perimetro()
          << std::endl;
    
       return 0;
}