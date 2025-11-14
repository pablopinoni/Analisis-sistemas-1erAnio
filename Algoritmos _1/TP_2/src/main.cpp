// src/main.cpp

#include "../include/menu.h"
#include <iostream>

int main() {
    std::cout << "--- Inicio del Programa de Gestión de Figuras ---" << std::endl;
    
    // El objeto 'gestor' se crea y llama al constructor de Menu.
    Menu gestor; 

    // Ejecutar el menú interactivo
    gestor.ejecutar(); 

    // Al salir de main, el objeto 'gestor' se destruye,
    // lo que desencadena la limpieza de la memoria de todas las figuras (Composición).
    std::cout << "--- Fin del Programa ---" << std::endl;
    return 0;
}