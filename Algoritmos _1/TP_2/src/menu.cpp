// src/menu.cpp

#include "../include/menu.h"
#include "../include/circulo.h"
#include "../include/rectangulo.h"
#include "../include/triangulo.h"
#include <iostream>
#include <limits> // Necesario para std::numeric_limits
#include <string>

// --- Funciones Auxiliares para Limpieza de Entrada (C++) ---

// Función para limpiar el buffer de std::cin después de un error.
void limpiar_cin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Función auxiliar para leer un valor de punto flotante con manejo de errores
bool leer_double(double& valor, const std::string& mensaje_prompt) {
    std::cout << mensaje_prompt;
    if (!(std::cin >> valor)) {
        std::cout << "[ERROR] Valor inválido." << std::endl;
        limpiar_cin();
        return false;
    }
    return true;
}

// --- Implementación de Métodos de la Clase Menu ---

// Implementación del destructor (Composición/Liberación de memoria)
Menu::~Menu() {
    std::cout << "\n[MENU] Destruyendo el gestor y liberando la memoria de las figuras..." << std::endl;
    for (int i = 0; i < contador; ++i) {
        delete figuras[i]; // Llama al destructor virtual de la subclase
        figuras[i] = nullptr;
    }
    contador = 0;
}

// Implementación de loadFiguras() (Debe existir, aunque se mantiene mínima)
void Menu::loadFiguras() {
    std::cout << "[MENU] Inicialización de figuras (0 figuras)." << std::endl;
}

// Implementación del método de creación de figuras (Robusto contra errores de entrada)
void Menu::crearFigura() {
    if (contador >= MAX_ITEMS) {
        std::cout << "Lista de figuras llena. No se pueden añadir más." << std::endl;
        return;
    }

    int tipo;
    std::cout << "\n--- Crear Nueva Figura ---" << std::endl;
    std::cout << "1: Círculo" << std::endl;
    std::cout << "2: Rectángulo" << std::endl;
    std::cout << "3: Triángulo" << std::endl;
    std::cout << "Seleccione el tipo: ";

    if (!(std::cin >> tipo)) {
        std::cout << "[ERROR] Entrada de tipo inválida." << std::endl;
        limpiar_cin();
        return;
    }

    std::string nombre;
    double val1, val2, val3, val4, val5, val6;

    std::cout << "Ingrese el nombre de la figura: ";
    // Limpieza de buffer después de leer 'tipo'
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::getline(std::cin, nombre);

    Figura* nueva_figura = nullptr;

    switch (tipo) {
        case 1: // Círculo
            if (leer_double(val1, "Ingrese radio: ")) {
                if (val1 > 0) {
                    nueva_figura = new Circulo(val1, nombre);
                } else {
                    std::cout << "[ERROR] El radio debe ser positivo." << std::endl;
                }
            }
            break;

        case 2: // Rectángulo
            if (leer_double(val1, "Ingrese base: ") && leer_double(val2, "Ingrese altura: ")) {
                if (val1 > 0 && val2 > 0) {
                    nueva_figura = new Rectangulo(val1, val2, nombre);
                } else {
                    std::cout << "[ERROR] Base y altura deben ser positivas." << std::endl;
                }
            }
            break;

        case 3: // Triángulo
            std::cout << "Ingrese Vértice A (x y) [Ej: 2 3]: ";
            if (!(std::cin >> val1 >> val2)) { 
                std::cout << "[ERROR] Valores de Vértice A inválidos." << std::endl; limpiar_cin(); break; 
            }
            
            std::cout << "Ingrese Vértice B (x y) [Ej: 5 0]: ";
            if (!(std::cin >> val3 >> val4)) { 
                std::cout << "[ERROR] Valores de Vértice B inválidos." << std::endl; limpiar_cin(); break; 
            }
            
            std::cout << "Ingrese Vértice C (x y) [Ej: 2.5 5]: ";
            if (std::cin >> val5 >> val6) {
                nueva_figura = new Triangulo(val1, val2, val3, val4, val5, val6, nombre);
            } else {
                std::cout << "[ERROR] Valores de Vértice C inválidos." << std::endl;
                limpiar_cin();
            }
            break;

        default:
            std::cout << "[ERROR] Opción de figura no válida." << std::endl;
            break;
    }
    
    if (nueva_figura) {
        figuras[contador++] = nueva_figura;
        std::cout << "\nFigura '" << nombre << "' creada con éxito." << std::endl;
    }
}

// Implementación de dibujarTodas() (Polimorfismo)
void Menu::dibujarTodas() const {
    std::cout << "\n--- Ejecutando Dibujar Todas (Polimorfismo) ---" << std::endl;
    std::cout << "\t🐢✏️\n";
    if (contador == 0) {
        std::cout << "No hay figuras para dibujar." << std::endl;
        return;
    }
    for (int i = 0; i < contador; ++i) {
        figuras[i]->dibujar();
           
    }
}

// Implementación de showMenu()
void Menu::showMenu() const {
    std::cout << "\n=======================================" << std::endl;
    std::cout << "           GESTOR DE FIGURAS           " << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "Figuras actuales: " << contador << "/" << MAX_ITEMS << std::endl;
    std::cout << "1: Crear Nueva Figura" << std::endl; 
    std::cout << "2: Dibujar Todas las Figuras" << std::endl;
    std::cout << "3: Mover una Figura (Simulado)" << std::endl;
    std::cout << "0: Salir" << std::endl; // Opción 0 para salir
    std::cout << "=======================================" << std::endl;
}

// Implementación de ejecutar() (Bucle principal)
void Menu::ejecutar() {
    int opcion = -1;
    int indice_figura = -1;
    
    do {
        showMenu();
        std::cout << "Seleccione una opción: ";

        if (!(std::cin >> opcion)) { 
            std::cout << "[ERROR] Entrada inválida. Intente de nuevo." << std::endl;
            limpiar_cin();
            continue;
        }

        switch (opcion) {
            case 1:
                crearFigura();
                break;
            case 2:
                dibujarTodas();
                break;
            case 3:
                if (contador == 0) {
                    std::cout << "No hay figuras para mover." << std::endl;
                    break;
                }
                std::cout << "\n--- Figuras Disponibles ---" << std::endl;
                for(int i = 0; i < contador; ++i) {
                    std::cout << i << ": " << figuras[i]->getNombre() << std::endl;
                }
                std::cout << "Índice de figura a mover (0 a " << contador - 1 << "): ";
                
                if (std::cin >> indice_figura && indice_figura >= 0 && indice_figura < contador) {
                    figuras[indice_figura]->mover();
                } else {
                    std::cout << "[ERROR] Índice inválido." << std::endl;
                    limpiar_cin();
                }
                break;
            case 0: // Caso de salida
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "[ERROR] Opción no reconocida." << std::endl;
        }
    } while (opcion != 0); // Condición de salida: opcion == 0
}