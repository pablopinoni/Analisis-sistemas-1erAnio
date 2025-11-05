// Archivo: src/main.cpp

#include "application.h"
#include <iostream>

int main() {
    // 1. Instanciar la clase principal de la lógica de negocio
    Application app; 
    
    // 2. Ejecutar el ciclo principal de la aplicación
    std::cout << "Iniciando Sistema de Ventas..." << std::endl;
    app.run();
    std::cout << "Sistema finalizado." << std::endl;
    
    return 0;
}