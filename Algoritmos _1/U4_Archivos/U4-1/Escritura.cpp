#include <iostream>
#include <string>
using namespace std;
#include <fstream>

int main() 
{
   string DNI, producto;
   int unidades;
   double precio;
   char aux;
   ofstream archivo;
   
   archivo.open("output.txt"); // Apertura (creación)

   cout << "DNI del cliente (999 para terminar): ";
   cin >> DNI;
   while (DNI != "999") {
       cout << "DNI ->" << DNI << "***" << endl;
      // Queda pendiente el Intro anterxior...
      cin.get(aux); // Leemos el Intro
      cout << "Producto: ";
      getline(cin, producto);
      cout << "Unidades: ";
      cin >> unidades;
      cout << "Precio: ";
      cin >> precio;
      // Escribimos los datos en una línea del archivo...
      // Con un espacio de separación entre ellos
      archivo << DNI << " " << unidades << " "
         << precio << " " << producto << endl;
      cout << "DNI del cliente (999 para terminar ): ";
      cin.sync();
      cin >> DNI;
   }
// Escribimos el centinela final...
   archivo << "X";
   archivo.close(); // Cierre del archivo
   return 0;
}


