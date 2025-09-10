#include <iostream>
#include <iomanip>
using namespace std;

// Prototipos de función
float fahrenheitACentigrados(float fahrenheit);
float centigradosAFahrenheit(float centigrados);
void clearConsole();

// Bloque Principal del Programa
int main() 
{  
    clearConsole();
    
    int opcion;
    float temperatura, resultado;
    
    // Menú de opciones
    cout << "CONVERSOR DE TEMPERATURA" << endl;
    cout << "Seleccione una opcion:" << endl;
    cout << "(1) Convertir Grados Centígrados a Fahrenheit" << endl;
    cout << "(2) Convertir Grados Fahrenheit a Centígrados" << endl;
    
    cin >> opcion;

    // Validación de entrada
    while (opcion != 1 && opcion != 2) {
        cout << "Opcion no valida. Por favor ingrese 1 o 2: ";
        cin >> opcion;
    }

    // Procesamiento según opción
    if (opcion == 1) {
        cout << "Ingrese la temperatura en Centígrados: ";
        cin >> temperatura;
        resultado = centigradosAFahrenheit(temperatura);
        cout << temperatura << "grados C equivalen a " << resultado << " Grados F\n" << endl;
    } 
    else if (opcion == 2) {
        cout << "Ingrese la temperatura en Fahrenheit: ";
        cin >> temperatura;
        resultado = fahrenheitACentigrados(temperatura);
         cout << temperatura << " grados F equivalen a " << resultado << " Grados C\n" << endl;
    }

    return 0;
}

// Definición de funciones
void clearConsole()
{
    #ifdef _WIN32
        system("cls");
    #elif __unix__ || __APPLE__
        system("clear");
    #endif
}

float fahrenheitACentigrados(float fahrenheit) {
    return (5.0f / 9.0f) * (fahrenheit - 32);
}

float centigradosAFahrenheit(float centigrados) {
    return (centigrados * 9.0f / 5.0f) + 32;
}