#include "../include/consola_utils.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <cstdlib>

// Implementación de las funciones
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseConsole() {
#ifdef _WIN32
    system("pause");
#else
    std::cout << "Presione ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
}

int validarInt(const std::string& mensaje) {
    std::string entrada;
    int valor;
    while (true) {
        std::cout << mensaje;
        std::getline(std::cin, entrada);
        std::stringstream ss(entrada);
        if (ss >> valor && ss.eof()) {
            return valor;
        } else {
            std::cout << "Entrada inválida. Ingrese un número entero válido.\n";
        }
    }
}