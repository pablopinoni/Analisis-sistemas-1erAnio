#include <iostream>
#include "interfaz.h"
using namespace std;

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
