#include <iostream>
using namespace std;

bool esPrimo (int num ); // Protipo de funcion

int main()

{ 
    
    int num; // declaro variable

    cout << "======/ Determinar si un numero es primo /===== " <<endl;
    cout << "Ingrese un numero: " << endl; 
    cin  >> num;
  
     // Llamar a la funcion
     if ( esPrimo(num)) { 
        cout << "Es primo" << endl;
    }
    else {
        cout << "No es primo" << endl;
    }
    
    return 0;
}
    
bool esPrimo(int num) {
    if (num <= 1) return false;  
    if (num == 2) return true;    // 2 true
    if (num % 2 == 0) return false;  // resto d elso paresno es prino
    int divisor = 3;              // Empezamos a probar desde 3

    while (divisor * divisor <= num) {  
        if (num % divisor == 0) {
            return false;  
        }
        divisor += 2;     //  divisores impares
    }
    return true;  // Si no encontró divisores, es primo
    }
