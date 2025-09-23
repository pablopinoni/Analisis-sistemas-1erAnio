#include "../include/menu.h"
#include <iostream>

// Implementación de las funciones
void showTitle(bool encendido) {
    if (encendido) {
        std::cout << "\033[1;33m";
        std::cout << "\033[40m";
    } else {
        std::cout << "\033[30m";
        std::cout << "\033[40m";
    }
    std::cout << "\n";
    std::cout << "##################################################\n";
    std::cout << "##################################################\n";
    std::cout << "##################################################\n";
    std::cout << "          GESTIÓN DE ALUMNOS                      \n";
    std::cout << "##################################################\n";
    std::cout << "##################################################\n";
    std::cout << "\033[0m";
}

void blinkTitle(int veces, int milisegundos) {
    for (int i = 0; i < veces; ++i) {
        clearConsole();
        showTitle(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
        
        clearConsole();
        showTitle(false);
        std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
    }
}

void showMainMenu(tGestionAlumnos& gestion) {
    int mainOption;
    do {
        mainOption = showOptionsMenu();
        switch (mainOption) {
            case 1: {
                int managementOption;
                do {
                    managementOption = showSubMenuManagement();
                    switch (managementOption) {
                        case 1: insertAlumno(gestion); break;
                        case 2: deleteAlumno(gestion); break;
                        case 0: std::cout << "Volviendo al menú principal..." << std::endl; break;
                        default: std::cout << "Opción inválida." << std::endl;
                    }
                } while (managementOption != 0);
                break;
            }
            case 2: {
                int listOption;
                do {
                    listOption = showSubMenuListing();
                    switch (listOption) {
                        case 1: listAllAlumnos(gestion); break;
                        case 2: {
                            int legajo = validarInt("Ingrese legajo del alumno a buscar: ");
                            searchAlumnoByLegajo(gestion, legajo);
                            break;
                        }
                        case 0: std::cout << "Volviendo al menú principal..." << std::endl; break;
                        default: std::cout << "Opción inválida." << std::endl;
                    }
                } while (listOption != 0);
                break;
            }
            case 3: sortAlumnos(gestion); break;
            case 0:
                std::cout << "Guardando datos y saliendo..." << std::endl;
                saveList(gestion);
                break;
            default: std::cout << "Opción inválida. Intente nuevamente." << std::endl;
        }
    } while (mainOption != 0);
}

int showOptionsMenu() {
    int option;
    do {
        std::cout << "\n===== MENÚ PRINCIPAL =====\n";
        std::cout << "1. Gestión de Alumnos\n";
        std::cout << "2. Listar y Buscar Alumnos\n";
        std::cout << "3. Ordenar Alumnos\n";
        std::cout << "0. Salir\n";
        option = validarInt("Ingrese opción: ");
        if (option < 0 || option > 3) {
            std::cout << "Opción inválida. Por favor ingrese un número válido." << std::endl;
        }
    } while (option < 0 || option > 3);
    return option;
}

int showSubMenuManagement() {
    int option;
    do {
        std::cout << "\n===== MENÚ GESTIÓN =====\n";
        std::cout << "1. Insertar un Alumno\n";
        std::cout << "2. Eliminar un Alumno\n";
        std::cout << "0. Volver al menú principal\n";
        option = validarInt("Ingrese opción: ");
        if (option < 0 || option > 2) {
            std::cout << "Opción inválida. Por favor ingrese un número válido." << std::endl;
        }
    } while (option < 0 || option > 2);
    return option;
}

int showSubMenuListing() {
    int option;
    do {
        std::cout << "\n===== MENÚ LISTAR =====\n";
        std::cout << "1. Listar todos los alumnos\n";
        std::cout << "2. Buscar alumno por legajo\n";
        std::cout << "0. Volver al menú principal\n";
        option = validarInt("Ingrese opción: ");
        if (option < 0 || option > 2) {
            std::cout << "Opción inválida. Por favor ingrese un número válido." << std::endl;
        }
    } while (option < 0 || option > 2);
    return option;
}

int showSubMenuSorting() {
    int option;
    do {
        std::cout << "\n===== MENÚ ORDENAMIENTO =====\n";
        std::cout << "1. Ordenar por Legajo\n";
        std::cout << "2. Ordenar por Apellido y Nombre\n";
        std::cout << "0. Volver al menú principal\n";
        option = validarInt("Ingrese opción: ");
        if (option < 0 || option > 2) {
            std::cout << "Opción inválida. Por favor ingrese un número válido." << std::endl;
        }
    } while (option < 0 || option > 2);
    return option;
}