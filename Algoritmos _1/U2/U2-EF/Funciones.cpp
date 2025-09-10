//funciones en C++
//Bibliotetas, Espacios de Nombres y Directivas de Procesador. 
//55
#include <iostream>
using namespace std;
#include <cmath>

// Prototipos de las funciones (excepto main())
//Acas pones solo la Definicion (Interface) de las Funciones 
bool par(int num);
bool letra(char car);
int suma(int num);
double formula(int x, int y);

//Bloque Principal del Programa
//Solo Acceso a las Interfaces
int main() {
   //SetConsoleOutputCP( 65001 );
   system("clear");
   int numero, x=2, y=6;
   char caracter;

   cout << "\n Entero: ";
   cin >> numero;
   if (par( numero)) {
      cout << "Par";
   }
else {
      cout << "Impar";
   }
   cout  << endl;
   if (numero > 1) {
      cout << "Sumatorio de 1 a " << numero << ": " 
           << suma(numero) << endl;
   }
   cout << "Carácter: ";
   cin.sync();
   cin >> caracter;
   if (!letra(caracter)) {
      cout << "no ";
   }
   cout << "es una letra" << endl;
   cout << "f(x, y) = " << formula(x, y) << endl;
   // Los argumentos pueden llamarse igual o no que los parámetros

   return 0;
}

// Implementación de las funciones propias
//Modularización por Funciones (subprogramas)
bool par(int num) {
   bool esPar;

   if (num % 2 == 0) {
      esPar = true;
   }
   else {
      esPar = false;
   }

   return esPar;
}
bool letra(char car) {
   bool esLetra;
   if (((car >= 'a') && (car <= 'z')) || ((car >= 'A') && (car <= 'Z'))) {
      esLetra = true;
   }
   else {
      esLetra = false;
   }
   return esLetra;
}
int suma(int num) {
   int sum = 0, i = 1;
   while (i < num) {
      sum = sum + i;
      i++;
   }
   return sum;
}
double formula(int x, int y) {
   double f;

   f = 2 * pow(x, 5) + sqrt(pow(x, 3) / pow(y, 2)) 
         / abs(x * y) - cos(y);

   return f;
}
