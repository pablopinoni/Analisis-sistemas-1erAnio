//Escribe un programa en C++ que lea del teclado un número (real) de grados
//Fahrenheit y lo convierta a Celsius mostrando el resultado en la pantalla. ºC =
//5 / 9 x (ºF ‐ 32)

#include <iostream>
using namespace std;

int main()

{
     double gradosF;
     double gradosCelsius;

     cout << "Introduzca la cantidad de Grados Farenheit: " << endl;
     cin >> gradosF;

    // Formula  ºC = 5 / 9 x (ºF ‐ 32)
    double result = 5.0 / 9.0 * ( gradosF - 32 );



 cout << " Equivalen a:  " << result << "Grados Celsius."  << endl;

 return 0;
}
