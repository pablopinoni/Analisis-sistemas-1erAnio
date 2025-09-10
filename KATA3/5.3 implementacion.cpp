#include <iostream>
#include "interfaz.h"
using namespace std;

// Inicialización del atributo estático
const int SistemaEstudiantes::MAX = 100;

// ------------------------------
// Método auxiliar privado
// ------------------------------
int SistemaEstudiantes::buscarEstudiante(int buscado) {
    for (int i = 0; i < cantidad; i++) {
        if (id[i] == buscado) {
            return i;
        }
    }
    return -1;
}

// ------------------------------
// Métodos públicos
// ------------------------------
void SistemaEstudiantes::altaEstudiante() {
    if (cantidad < MAX) {
        cout << "\nIngrese ID: ";
        cin >> id[cantidad];
        cin.ignore();

        cout << "Ingrese Nombre: ";
        getline(cin, nombre[cantidad]);

        cout << "Ingrese Edad: ";
        cin >> edad[cantidad];
        cin.ignore();

        cout << "Ingrese Carrera: ";
        getline(cin, carrera[cantidad]);

        cantidad++;
        cout << "\n✅ Estudiante agregado con éxito.\n";
    } else {
        cout << "\n⚠️ No hay espacio para más estudiantes.\n";
    }
}

void SistemaEstudiantes::bajaEstudiante() {
    int buscado;
    cout << "\nIngrese ID del estudiante a eliminar: ";
    cin >> buscado;

    int pos = buscarEstudiante(buscado);
    if (pos != -1) {
        id[pos] = id[cantidad - 1];
        nombre[pos] = nombre[cantidad - 1];
        edad[pos] = edad[cantidad - 1];
        carrera[pos] = carrera[cantidad - 1];
        cantidad--;

        cout << "\n🗑️ Estudiante eliminado con éxito.\n";
    } else {
        cout << "\n❌ No se encontró el estudiante con ese ID.\n";
    }
}

void SistemaEstudiantes::modificarEstudiante() {
    int buscado;
    cout << "\nIngrese ID del estudiante a modificar: ";
    cin >> buscado;
    cin.ignore();

    int pos = buscarEstudiante(buscado);
    if (pos != -1) {
        cout << "\nIngrese nuevo Nombre: ";
        getline(cin, nombre[pos]);

        cout << "Ingrese nueva Edad: ";
        cin >> edad[pos];
        cin.ignore();

        cout << "Ingrese nueva Carrera: ";
        getline(cin, carrera[pos]);

        cout << "\n✏️ Datos modificados con éxito.\n";
    } else {
        cout << "\n❌ No se encontró el estudiante con ese ID.\n";
    }
}

void SistemaEstudiantes::consultaEstudiante() {
    int buscado;
    cout << "\nIngrese ID del estudiante a consultar: ";
    cin >> buscado;

    int pos = buscarEstudiante(buscado);
    if (pos != -1) {
        cout << "\n📌 Datos del estudiante:\n";
        cout << "ID: " << id[pos] << endl;
        cout << "Nombre: " << nombre[pos] << endl;
        cout << "Edad: " << edad[pos] << endl;
        cout << "Carrera: " << carrera[pos] << endl;
    } else {
        cout << "\n❌ No se encontró el estudiante con ese ID.\n";
    }
}

void SistemaEstudiantes::listarEstudiantes() {
    if (cantidad == 0) {
        cout << "\n📭 No hay estudiantes registrados.\n";
    } else {
        cout << "\n📋 Listado de estudiantes:\n";
        for (int i = 0; i < cantidad; i++) {
            cout << "ID: " << id[i]
                 << " | Nombre: " << nombre[i]
                 << " | Edad: " << edad[i]
                 << " | Carrera: " << carrera[i]
                 << endl;
        }
    }
}
