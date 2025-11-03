#include <iostream>
#include "articulos.h"

int main(){

Articulo Articulo_1;
//Agregar if
std::cout << "Articulo_1 creado correctamente\n"
          << "Ingrese el costo base: \n";
float costoIngresaso;
std::cin >> costoIngresaso;
Articulo_1.SetCostoBase(costoIngresaso);

//Impresión de resultados
std::cout << "El costo de base del artículo es: "
          << Articulo_1.GetCostoBase() <<std::endl;

std::cout << "El costo por mayor del artículo es: "
          << Articulo_1.PVPMayor() <<std::endl;

std::cout << "El costo por menor del artículo es: "
          << Articulo_1.PVPDetail() <<std::endl;

return 0;
}