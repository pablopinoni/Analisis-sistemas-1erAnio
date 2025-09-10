/**
 * @file main.cpp
 * @brief Punto de entrada principal para la aplicación.
 */
#include "FltkButtonApp.h"
#include <FL/Fl.H>

/**
 * @brief Punto de entrada principal de la aplicación.
 *
 * Crea una instancia de la clase FltkButtonApp, muestra su ventana
 * y comienza el bucle de eventos de FLTK.
 * @return int El código de salida del programa.
 */
int main(int argc, char** argv) 
{
    // Crea una instancia de la aplicación.
    FltkButtonApp app;
    
    // Muestra la ventana de la aplicación.
    app.show();
    
    // Inicia el bucle de eventos de FLTK y espera a que el usuario cierre la ventana.
    return Fl::run();
}
