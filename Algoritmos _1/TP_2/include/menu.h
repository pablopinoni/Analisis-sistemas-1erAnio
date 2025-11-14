// include/menu.h

#pragma once

#include "figura.h" 
#include <iostream>

#define MAX_ITEMS 10

class Menu {
private:
    Figura* figuras[MAX_ITEMS];
    int contador;

    // Se mantiene la firma pero no se usa en el constructor
    void loadFiguras(); 
    
    // ¡NUEVO MÉTODO! Lógica para interactuar con el usuario y crear objetos.
    void crearFigura(); 

public:
    // Constructor (Definido INLINE en el .h, sin llamar a loadFiguras())
    Menu() : contador(0) {
        for (int i = 0; i < MAX_ITEMS; ++i) {
            figuras[i] = nullptr;
        }
    }

    // ¡CRÍTICO! Destructor. La implementación va en el .cpp
    ~Menu(); 

    // Métodos públicos
    void showMenu() const;
    void ejecutar(); // Contiene el bucle principal (loop)
    void dibujarTodas() const;

};