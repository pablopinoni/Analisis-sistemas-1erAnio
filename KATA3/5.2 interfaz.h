#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
using namespace std;

struct SistemaEstudiantes {
private:
    int id[100];
    string nombre[100];
    int edad[100];
    string carrera[100];
    int cantidad = 0;
    static const int MAX;

    // Método auxiliar privado
    int buscarEstudiante(int buscado);

public:
    // Métodos públicos
    void altaEstudiante();
    void bajaEstudiante();
    void modificarEstudiante();
    void consultaEstudiante();
    void listarEstudiantes();
};

#endif // INTERFAZ_H
