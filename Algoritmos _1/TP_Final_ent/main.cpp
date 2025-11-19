// main.cpp
#include "caratula.hpp"
#include "menu.hpp"
#include <iostream>
int main() {
    // Mostrar carátula con pollo de costado tocando ukelele antes del menú
    Caratula caratula;
    caratula.mostrarCaratulaConPollo(4, 800);  // 2 veces, 800ms cada parpadeo
    caratula.mostrarBienvenida();
    
    // Crear y ejecutar el menú
    Menu menu;
    menu.runApp();
    
    std::cout << "\n¡Gracias por usar el sistema!" << std:: endl;
    return 0;
}