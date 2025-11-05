
#include "menu.h"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

int Menu::showMainMenu() {
    float choice = -1;
    cout << "\n======================================" << endl;
    cout << "           MENÚ PRINCIPAL" << endl;
    cout << "======================================" << endl;
    cout << "1. Gestión de Artículos" << endl;
    cout << "2. Gestión de Clientes" << endl;
    cout << "3. Cargar nuevo Pedido" << endl;
    cout << "4. Gestionar Ítems/Desasignación de Pedidos (A IMPLEMENTAR)" << endl;
    cout << "5. Mostrar todos los pedidos" << endl;
    cout << "0. Salir" << endl;
    
    // Reutilizamos readFloat para leer la opción del menú
    choice = readFloat("Seleccione una opción: "); 
    return (int)choice;
}

string Menu::readString(const string& prompt) {
    string input;
    cout << prompt;
    // Limpiar el buffer de entrada para asegurar que getline funcione correctamente
    if (cin.peek() == '\n') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, input);
    return input;
}

float Menu::readFloat(const string& prompt) {
    float value;
    cout << prompt;
    
    // Loop de manejo de errores para floats (o ints en el caso de las opciones de menú)
    while (!(cin >> value)) {
        cout << "Entrada inválida. Por favor, ingrese un número: ";
        cin.clear(); // Limpiar el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar el resto de la línea
    }
    // Dejar un '\n' pendiente para la próxima llamada a readString
    return value;
}
