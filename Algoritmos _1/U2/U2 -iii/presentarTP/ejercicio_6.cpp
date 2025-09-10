// Hacer un programa en C++ para Calcular la suma de los números pares e impares
//comprendidos entre 1 y n (n lo introduce el usuario).

#include <iostream>
#include <cmath>
using namespace std;


//Prototipos de Funciones
 int sumaNumerosPares(int, int);
 int sumaNumerosImpares(int, int);
 

int main() {
const int limiteInferior = 1;
int limiteSuperior;
int resultImp;
int resultPa;
int total = resultPa + resultImp;
 cout << " Ingrese un numero entero mayor a 1: " << endl;
 cin >> limiteSuperior; 
if ( limiteSuperior <= 0) { 

    cout << "Entrada no valida." << endl;
 return 1;
   }  
  else ( resultImp, resultPa); {

    // Llamar a las funciones
    int resultPa = sumaNumerosPares(limiteInferior, limiteSuperior);
    int resultImp = sumaNumerosImpares(limiteInferior, limiteSuperior);
    int total = resultPa + resultImp;

    //Salida de resultados 
    cout << "\n\t\t***RESULTADOS***" << endl;
    cout << "\nLa Suma de los Pares entre " << limiteInferior <<" y "<< limiteSuperior<< " es igual a: " << 
    resultPa  << "." << endl;

    cout << "\nLa Suma de los Impares entre " << limiteInferior <<" y "<< limiteSuperior<< " es igual a: " << 
    resultImp  << "." << endl;

    cout << "\nLa Suma de los Pares e Impares entre " << limiteInferior <<" y "<< limiteSuperior<< " es igual a: " << 
   total << ".\n" << endl;


}

  return 0;
}

//Declarar funciones 
int sumaNumerosPares( int limiteInferior, int limiteSupeior){
  int suma = 0;
for (int i= limiteInferior; i <= limiteSupeior; i++) {
    if ( i  % 2 == 0) //Validar que i sea par
    suma += i; 
        }
   return suma;

   }

int sumaNumerosImpares( int limiteInferior, int limiteSupeior){

    int suma = 0;
    for (int i= limiteInferior; i <= limiteSupeior; i++) {
        if (i  % 2 != 0) // Usar (!=) ojo con poner (=!) no volver a renegar
         suma += i; }
      
         return suma;
    
    }
    

