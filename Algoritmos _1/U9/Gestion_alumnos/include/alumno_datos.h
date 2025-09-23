#pragma once

#include <string>

// 1. Definición de la estructura de un Alumno
//    Esto debe ir primero.
typedef struct {
    int legajo;
    std::string apellido;
    std::string nombre;
    std::string direccion;
} tAlumno;

// 2. Sobrecarga de operadores
//    Ahora que tAlumno está completamente definido, los prototipos de los operadores
//    no tendrán problemas. Ya no es necesaria la palabra `struct` en la firma.
bool operator>(const tAlumno& opIzq, const tAlumno& opDer);
bool operator<(const tAlumno& opIzq, const tAlumno& opDer);

// 3. Definiciones de otras estructuras
//    Estas también dependen de la definición completa de tAlumno.
typedef struct {
    tAlumno alumnos[100];
    int contador;
} tListaAlumnos;

typedef struct {
    tListaAlumnos gestion;
} tGestionAlumnos;

// 4. Constantes globales
//    Pueden ir en cualquier lugar, pero es buena práctica tenerlas cerca de las estructuras.
const int MAX_ALUMNOS = 100;
const std::string file = "alumnos.txt";

// 5. Prototipos de funciones
//    Finalmente, los prototipos de las funciones que usan las estructuras.
bool emptyList(const tGestionAlumnos& gestion);
void saveList(const tGestionAlumnos& gestion);
void loadFromFile(tGestionAlumnos& gestion);
void insertAlumno(tGestionAlumnos& gestion);
void deleteAlumno(tGestionAlumnos& gestion);
void listAllAlumnos(const tGestionAlumnos& gestion);
void searchAlumnoByLegajo(const tGestionAlumnos& gestion, int legajoBuscado);
void sortAlumnos(tGestionAlumnos& gestion);
void swapAlumnos(tAlumno& a, tAlumno& b);
void sortAscending(tGestionAlumnos& gestion, int campo);
void sortDescending(tGestionAlumnos& gestion, int campo);