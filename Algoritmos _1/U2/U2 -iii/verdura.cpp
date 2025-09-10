#include <iostream>
using namespace std;

int main() {
    // Declaración de variables
    int numero;
    int suma = 0;
    
    // Entrada de datos
    cout << "Ingrese un numero entero positivo: ";
    cin >> numero;
    
    // Validación
    if (numero <= 0) {
        cout << "El numero debe ser positivo." << endl;
        return 1;
    }
    
    // Cálculo de la suma
    for (int i = 1; i <= numero; i++) {
        suma += i;
    }
    
    // Salida del resultado
    cout << "La suma desde 1 hasta " << numero << " es: " << suma << endl;
    
    return 0;
}