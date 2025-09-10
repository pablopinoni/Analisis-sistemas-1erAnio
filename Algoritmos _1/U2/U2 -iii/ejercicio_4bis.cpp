#include <iostream>
#include <string>
using namespace std;

// Prototipo de función 
float prom(float, int);  

int main() {
   //declaracion de variables
   int numero;
    int cantNumero = 0; // variable inncializada para llevar conteo de numeros validos ingresados
    float suma = 0;    // variable acumualdora inicializada , podria haber usado tipo int y dsps castear    
    string numerosConcatenados = "";  

    cout << "Ingresa números positivos (termina con 99):" << endl;
    cin >> numero;
  //FAlta añadir validacion de dato de entrada
    while (numero != 99) { //tengo q mejorar la validacion para q el programa no se rompa 
        cantNumero++; // conteo de la cantidad de numeros ingresados
        suma += numero; // generar una suma de lso numeros ingresados por el usario para ser usado en la funcion prom
        numerosConcatenados += to_string(numero) + " / "; // convierte un valor de int a una secuencia de caracteres
        
        cout << "Ingresa otro numero: " << endl;
        cin >> numero;
    }

    if (cantNumero > 0) { // si hay por lo menos un num ingresado validado, al poner 99 obtenemos la salida del programa
        cout << "Números ingresados: " << numerosConcatenados << endl;
        cout << "Cantidad de numeros ingresados: " << endl;
        cout << "El promedio de los números es: " << prom(suma, cantNumero) << endl;
    }

    return 0;
}

// Función corregida
float prom(float suma, int cantNumero) {
   
    return suma / cantNumero;
}
