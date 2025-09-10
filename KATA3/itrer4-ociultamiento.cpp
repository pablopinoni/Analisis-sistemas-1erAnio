#include <iostream>
#include <string>
using namespace std;

// ------------------------------
// Definición del TDA con struct
// ------------------------------
struct SistemaEstudiantes {
private:
    // ==============================
    // Atributos privados
    // ==============================
    int id[100];
    string nombre[100];
    int edad[100];
    string carrera[100];
    int cantidad = 0;             // Cantidad actual de registros
    static const int MAX = 100;   // Capacidad máxima

    // Método auxiliar privado (solo lo usa el struct internamente)
    int buscarEstudiante(int buscado) {
        for (int i = 0; i < cantidad; i++) {
            if (id[i] == buscado) {
                return i;
            }
        }
        return -1;
    }

public:
    // ==============================
    // Métodos públicos
    // ==============================

    // Alta de estudiante
    void altaEstudiante() {
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

    // Baja de estudiante
    void bajaEstudiante() {
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

    // Modificar estudiante
    void modificarEstudiante() {
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

    // Consultar estudiante
    void consultaEstudiante() {
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

    // Listar todos los estudiantes
    void listarEstudiantes() {
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
