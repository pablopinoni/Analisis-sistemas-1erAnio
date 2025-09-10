#include <iostream>
#include <string>
using namespace std;

// ------------------------------
// Definición del TDA con struct
// ------------------------------
struct SistemaEstudiantes {
    // Atributos
    struct Estudiante {
        int id;
        string nombre;
        int edad;
        string carrera;
    };

    static const int MAX = 100;
    Estudiante estudiantes[MAX];
    int cantidad = 0;

    // ------------------------------
    // Alta de estudiante
    // ------------------------------
    void altaEstudiante() {
        if (cantidad < MAX) {
            Estudiante nuevo;
            cout << "\nIngrese ID: ";
            cin >> nuevo.id;
            cin.ignore();

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
    // Buscar estudiante por ID
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
    // Baja de estudiante
    // ------------------------------
    void bajaEstudiante() {
        int id;
        cout << "\nIngrese ID del estudiante a eliminar: ";
        cin >> id;

        int pos = buscarEstudiante(id);
        if (pos != -1) {
            estudiantes[pos] = estudiantes[cantidad - 1];
            cantidad--;
            cout << "\n🗑️ Estudiante eliminado con éxito.\n";
        } else {
            cout << "\n❌ No se encontró el estudiante con ese ID.\n";
        }
    }

    // ------------------------------
    // Modificar estudiante
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
    // Consultar estudiante
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
    // Listar todos los estudiantes
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
};

// ------------------------------
// Función principal con menú
// ------------------------------
int main() {
    SistemaEstudiantes sistema;
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
            case 1: sistema.altaEstudiante(); break;
            case 2: sistema.bajaEstudiante(); break;
            case 3: sistema.modificarEstudiante(); break;
            case 4: sistema.consultaEstudiante(); break;
            case 5: sistema.listarEstudiantes(); break;
            case 0: cout << "\n👋 Saliendo del programa...\n"; break;
            default: cout << "\n⚠️ Opción inválida.\n"; break;
        }
    } while (opcion != 0);

    return 0;
}
