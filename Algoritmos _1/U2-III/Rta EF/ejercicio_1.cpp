//Crear un programa por consola que convierta Grados Centígrados en Fahrenheit y
//viceversa, el programa debe preguntar qué operación desea hacer el usuario.
#include <iostream>
using namespace std;
#include <cmath>

//Prototipo de funcion

float fahrenheitACentigrados (float);
float centigradosAFahrenheit (float);

//Bloque Convertidor temperatura
int main() 
{
int  opcion;
float  temperatura;
float resultado;   
 


cout << "Seleccione una opcion" << endl;
cout << "(1) Conertir Grados Centígrados en Fahrenheit " << endl;
cout << "(2) Conertir Grados Fahrenheit en Centígrados  " << endl; 
cin >>  opcion;

if (opcion == 1) {
    cout << "Ingrese la temperatura en Centígrados: ";
    cin >> temperatura;
    resultado = centigradosAFahrenheit(temperatura);
    cout << temperatura << " Grados C equivalen a " << resultado << "Grados F" << endl;
} 
else if (opcion == 2) {
    cout << "Ingrese la temperatura en Fahrenheit: ";
    cin >> temperatura;
    resultado = fahrenheitACentigrados(temperatura);
    cout << temperatura << "Grados F equivalen a " << resultado << "Grados C" << endl;
} 
else {
    cout << "Opcion no valida." << endl;
}
}

// Definición de funciones
float fahrenheitACentigrados(float fahrenheit) 
{
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float centigradosAFahrenheit(float centigrados) {
    return (centigrados * 9.0 / 5.0) + 32;
}



