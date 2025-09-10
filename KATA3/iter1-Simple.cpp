#include <iostream>
#include <string>
using namespace std;

// ------------------------------
// Definición del TDA con struct
// ------------------------------
struct Estudiante {
    int id;
    string nombre;
    int edad;
    string carrera;
};

// ------------------------------
// Variables globales
// ------------------------------
const int MAX = 100;            // Capacidad máxima del arreglo
Estudiante estudiantes[MAX];    // Arreglo de estudiantes
int cantidad = 0;                // Cantidad actual de registros

// ------------------------------
// Función para agregar un estudiante
// ------------------------------
void altaEstudiante() {
    if (cantidad < MAX) {
        Estudiante nuevo;
        cout << "\nIngrese ID: ";
        cin >> nuevo.id;
        cin.ignore(); // limpiar buffer para getline

        cout << "Ingrese Nombre: ";
        getline(cin, nuevo.nombre);

        cout << "Ingrese Edad: ";
        cin >> nuevo.edad;
        cin.ignore();

        cout << "Ingrese Carrera: ";
        getline(cin, nuevo.carrera);

        estudiantes[cantidad] = nuevo;
        cantidad++;
        cout << "\n✅ Estudiante agregado con éxito.\n";
    } else {
        cout << "\n⚠️ No hay espacio para más estudiantes.\n";
    }
}

// ------------------------------
// Función para buscar un estudiante por ID
// Retorna el índice o -1 si no existe
// ------------------------------
int buscarEstudiante(int id) {
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].id == id) {
            return i;
        }
    }
    return -1; // no encontrado
}

// ------------------------------
// Función para eliminar un estudiante
// ------------------------------
void bajaEstudiante() {
    int id;
    cout << "\nIngrese ID del estudiante a eliminar: ";
    cin >> id;

    int pos = buscarEstudiante(id);
    if (pos != -1) {
        // Sobreescribir el eliminado con el último
        estudiantes[pos] = estudiantes[cantidad - 1];
        cantidad--;
        cout << "\n🗑️ Estudiante eliminado con éxito.\n";
    } else {
        cout << "\n❌ No se encontró el estudiante con ese ID.\n";
    }
}

// ------------------------------
// Función para modificar datos de un estudiante
// ------------------------------
void modificarEstudiante() {
    int id;
    cout << "\nIngrese ID del estudiante a modificar: ";
    cin >> id;
    cin.ignore();

    int pos = buscarEstudiante(id);
    if (pos != -1) {
        cout << "\nIngrese nuevo Nombre: ";
        getline(cin, estudiantes[pos].nombre);

        cout << "Ingrese nueva Edad: ";
        cin >> estudiantes[pos].edad;
        cin.ignore();

        cout << "Ingrese nueva Carrera: ";
        getline(cin, estudiantes[pos].carrera);

        cout << "\n✏️ Datos modificados con éxito.\n";
    } else {
        cout << "\n❌ No se encontró el estudiante con ese ID.\n";
    }
}

// ------------------------------
// Función para consultar un estudiante por ID
// ------------------------------
void consultaEstudiante() {
    int id;
    cout << "\nIngrese ID del estudiante a consultar: ";
    cin >> id;

    int pos = buscarEstudiante(id);
    if (pos != -1) {
        cout << "\n📌 Datos del estudiante:\n";
        cout << "ID: " << estudiantes[pos].id << endl;
        cout << "Nombre: " << estudiantes[pos].nombre << endl;
        cout << "Edad: " << estudiantes[pos].edad << endl;
        cout << "Carrera: " << estudiantes[pos].carrera << endl;
    } else {
        cout << "\n❌ No se encontró el estudiante con ese ID.\n";
    }
}

// ------------------------------
// Función para listar todos los estudiantes
// ------------------------------
void listarEstudiantes() {
    if (cantidad == 0) {
        cout << "\n📭 No hay estudiantes registrados.\n";
    } else {
        cout << "\n📋 Listado de estudiantes:\n";
        for (int i = 0; i < cantidad; i++) {
            cout << "ID: " << estudiantes[i].id
                 << " | Nombre: " << estudiantes[i].nombre
                 << " | Edad: " << estudiantes[i].edad
                 << " | Carrera: " << estudiantes[i].carrera
                 << endl;
        }
    }
}

// ------------------------------
// Función principal con menú
// ------------------------------
int main() {
    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Alta Estudiante\n";
        cout << "2. Baja Estudiante\n";
        cout << "3. Modificar Estudiante\n";
        cout << "4. Consultar Estudiante\n";
        cout << "5. Listar Estudiantes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: altaEstudiante(); break;
            case 2: bajaEstudiante(); break;
            case 3: modificarEstudiante(); break;
            case 4: consultaEstudiante(); break;
            case 5: listarEstudiantes(); break;
            case 0: cout << "\n👋 Saliendo del programa...\n"; break;
            default: cout << "\n⚠️ Opción inválida.\n"; break;
        }
    } while (opcion != 0);

    return 0;
}
