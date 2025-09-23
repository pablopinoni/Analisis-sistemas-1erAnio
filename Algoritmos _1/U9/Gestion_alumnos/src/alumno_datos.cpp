#include "../include/alumno_datos.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>

// Sobrecarga de operadores
// Se implementan aquí, ya que su declaración está en el .h
bool operator>(const tAlumno& opIzq, const tAlumno& opDer) {
    if (opIzq.apellido != opDer.apellido) {
        return opIzq.apellido > opDer.apellido;
    }
    return opIzq.nombre > opDer.nombre;
}

bool operator<(const tAlumno& opIzq, const tAlumno& opDer) {
    if (opIzq.apellido != opDer.apellido) {
        return opIzq.apellido < opDer.apellido;
    }
    return opIzq.nombre < opDer.nombre;
}

// Implementación de las funciones auxiliares y principales
bool emptyList(const tGestionAlumnos& gestion) {
    return gestion.gestion.contador == 0;
}

void saveList(const tGestionAlumnos& gestion) {
    std::ofstream archivo(file);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
        return;
    }
    archivo << gestion.gestion.contador << std::endl;
    for (int i = 0; i < gestion.gestion.contador; ++i) {
        const tAlumno& a = gestion.gestion.alumnos[i];
        archivo << a.legajo << ","
                << a.apellido << ","
                << a.nombre << ","
                << a.direccion << std::endl;
    }
    archivo.close();
    std::cout << "Lista de alumnos guardada en " << file << std::endl;
}

void loadFromFile(tGestionAlumnos& gestion) {
    std::ifstream archivo(file);
    if (!archivo.is_open()) {
        std::cout << "Advertencia: No se encontró el archivo '" << file << "'. Se iniciará una lista vacía." << std::endl;
        gestion.gestion.contador = 0;
        return;
    }

    std::string linea;
    gestion.gestion.contador = 0;
    std::getline(archivo, linea);
    int numAlumnos = 0;
    try {
        numAlumnos = std::stoi(linea);
    } catch (...) {
        numAlumnos = 0;
    }

    for (int i = 0; i < numAlumnos && std::getline(archivo, linea); ++i) {
        if (gestion.gestion.contador >= MAX_ALUMNOS) break;
        std::stringstream ss(linea);
        std::string segment;
        tAlumno temp;

        if (std::getline(ss, segment, ',')) temp.legajo = std::stoi(segment);
        if (std::getline(ss, segment, ',')) temp.apellido = segment;
        if (std::getline(ss, segment, ',')) temp.nombre = segment;
        if (std::getline(ss, segment, ',')) temp.direccion = segment;
        
        gestion.gestion.alumnos[gestion.gestion.contador++] = temp;
    }
    archivo.close();
    std::cout << "Archivo cargado exitosamente: " << gestion.gestion.contador << " alumnos." << std::endl;
}

void insertAlumno(tGestionAlumnos& gestion) {
    if (gestion.gestion.contador >= MAX_ALUMNOS) {
        std::cout << "No se pueden agregar más alumnos. Se ha alcanzado el límite." << std::endl;
        return;
    }

    tAlumno nuevoAlumno;
    std::cout << "\n===== INSERTAR ALUMNO =====\n" << std::endl;
    std::cout << "Ingrese legajo del alumno: ";
    std::cin >> nuevoAlumno.legajo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, nuevoAlumno.nombre);
    std::cout << "Ingrese apellido: ";
    std::getline(std::cin, nuevoAlumno.apellido);
    std::cout << "Ingrese dirección: ";
    std::getline(std::cin, nuevoAlumno.direccion);
    gestion.gestion.alumnos[gestion.gestion.contador++] = nuevoAlumno;
    std::cout << "\nAlumno agregado con éxito.\n";
    saveList(gestion);
}

void deleteAlumno(tGestionAlumnos& gestion) {
    if (emptyList(gestion)) {
        std::cout << "No hay alumnos para eliminar." << std::endl;
        return;
    }
    int legajoBuscado = 0;
    std::cout << "Ingrese el legajo del alumno a eliminar: ";
    std::cin >> legajoBuscado;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int indice = -1;
    for (int i = 0; i < gestion.gestion.contador; ++i) {
        if (gestion.gestion.alumnos[i].legajo == legajoBuscado) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        std::cout << "Alumno con legajo " << legajoBuscado << " no encontrado." << std::endl;
        return;
    }
    for (int i = indice; i < gestion.gestion.contador - 1; ++i) {
        gestion.gestion.alumnos[i] = gestion.gestion.alumnos[i + 1];
    }
    gestion.gestion.contador--;
    std::cout << "Alumno con legajo " << legajoBuscado << " eliminado correctamente." << std::endl;
    saveList(gestion);
}

void listAllAlumnos(const tGestionAlumnos& gestion) {
    if (emptyList(gestion)) {
        std::cout << "\nNo hay alumnos cargados.\n";
        return;
    }
    std::cout << "\n==== LISTA DE ALUMNOS ====\n";
    for (int i = 0; i < gestion.gestion.contador; ++i) {
        const tAlumno& a = gestion.gestion.alumnos[i];
        std::cout << "Legajo: " << a.legajo << "\n";
        std::cout << "Apellido: " << a.apellido << "\n";
        std::cout << "Nombre: " << a.nombre << "\n";
        std::cout << "Dirección: " << a.direccion << "\n";
        std::cout << "--------------------------\n";
    }
}

void searchAlumnoByLegajo(const tGestionAlumnos& gestion, int legajoBuscado) {
    bool encontrado = false;
    for (int i = 0; i < gestion.gestion.contador; ++i) {
        if (gestion.gestion.alumnos[i].legajo == legajoBuscado) {
            const tAlumno& a = gestion.gestion.alumnos[i];
            std::cout << "\nAlumno encontrado:\n";
            std::cout << "Legajo: " << a.legajo << "\n";
            std::cout << "Apellido: " << a.apellido << "\n";
            std::cout << "Nombre: " << a.nombre << "\n";
            std::cout << "Dirección: " << a.direccion << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Alumno con legajo " << legajoBuscado << " no encontrado.\n";
    }
}

void sortAlumnos(tGestionAlumnos& gestion) {
    if (emptyList(gestion)) {
        std::cout << "No hay alumnos para ordenar." << std::endl;
        return;
    }
    int sortOption = 0;
    std::cout << "\n===== MENÚ ORDENAMIENTO =====\n";
    std::cout << "1. Ordenar por Legajo\n";
    std::cout << "2. Ordenar por Apellido y Nombre\n";
    std::cout << "0. Volver al menú principal\n";
    std::cout << "Ingrese opción: ";
    std::cin >> sortOption;
    std::cin.ignore();
    if (sortOption == 0) return;
    char orderOption;
    std::cout << "¿Desea ordenar de forma ascendente (a) o descendente (d)?: ";
    std::cin >> orderOption;
    std::cin.ignore();
    if (orderOption == 'a' || orderOption == 'A') {
        sortAscending(gestion, sortOption);
        std::cout << "Lista ordenada de forma ascendente." << std::endl;
    } else if (orderOption == 'd' || orderOption == 'D') {
        sortDescending(gestion, sortOption);
        std::cout << "Lista ordenada de forma descendente." << std::endl;
    } else {
        std::cout << "Opción de ordenamiento inválida. No se aplicó ningún cambio." << std::endl;
    }
    listAllAlumnos(gestion);
}

void sortAscending(tGestionAlumnos& gestion, int campo) {
    int n = gestion.gestion.contador;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            bool shouldSwap = false;
            if (campo == 1) {
                if (gestion.gestion.alumnos[j].legajo > gestion.gestion.alumnos[j + 1].legajo) {
                    shouldSwap = true;
                }
            } else if (campo == 2) {
                if (gestion.gestion.alumnos[j] > gestion.gestion.alumnos[j + 1]) {
                    shouldSwap = true;
                }
            }
            if (shouldSwap) {
                swapAlumnos(gestion.gestion.alumnos[j], gestion.gestion.alumnos[j + 1]);
            }
        }
    }
}

void sortDescending(tGestionAlumnos& gestion, int campo) {
    int n = gestion.gestion.contador;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            bool shouldSwap = false;
            if (campo == 1) {
                if (gestion.gestion.alumnos[j].legajo < gestion.gestion.alumnos[j + 1].legajo) {
                    shouldSwap = true;
                }
            } else if (campo == 2) {
                if (gestion.gestion.alumnos[j] < gestion.gestion.alumnos[j + 1]) {
                    shouldSwap = true;
                }
            }
            if (shouldSwap) {
                swapAlumnos(gestion.gestion.alumnos[j], gestion.gestion.alumnos[j + 1]);
            }
        }
    }
}

void swapAlumnos(tAlumno& a, tAlumno& b) {
    tAlumno temp = a;
    a = b;
    b = temp;
}