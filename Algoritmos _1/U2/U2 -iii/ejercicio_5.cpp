//Hacer un programa en C++ que pida un número y calcule la suma desde 1 hasta ese
//número , en incrementos de uno.
#include <iostream>
using namespace std;

int main (){
//Declaracion de variables
int numero;
int suma= 0;
//Entrada de dato por consola
cout << " Ingrese un numero entero positivo: " << endl;
cin >> numero;

// Validación de entrada
if (numero <= 0) {
    cout << "El numero debe ser positivo." << endl;
    return 0;
   }
for (int i = 1; i <= numero; i++) {//(inicializacion; condicion; iteracion)

    suma += i;
    cout << " La suma de 1 hasta " << numero << " es igual a " << suma << "." << endl;
7
   }







return 0;

}