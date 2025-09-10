#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
using namespace std;

// Enumeraciones
typedef enum  { empanada, ensalada_rusa, sopa } tPrimerPlato;
typedef enum pal { tallarines, asado,
     hamburguesaCompleta, pastelDePapa, milanesa }tPlatoPrinci;

typedef enum tre { helado, flan, torta }tPos;

// Prototipos de funciones
string getPrimerPlato(int opcion);
string getPlatoPrincipal(int opcion);
string getPostre(int opcion);

// Funciones auxiliares
void clearConsole();
void pauseConsole();

int main() {
    int mesa, hora, primerPlato, platoPrincipal, postre;
    string mozo, fecha;

    clearConsole();

    cout << "\t\tCOMANDAS";
    cout << "\n\t=====================\n" << endl;

    cout << "Ingrese numero de mesa: ";
    cin >> mesa;

    cin.ignore(); // Limpiar buffer para usar getline
    cout << "Ingrese nombre del mozo: ";
    getline(cin, mozo);

    cout << "Ingrese fecha (dd mm): ";
    getline(cin, fecha);

    cout << "Ingrese hora (hh mm): ";
    cin >> hora;

    cout << "Ingrese N° Primer Plato (1-Empanada, 2-Ensalada Rusa, 3-Sopa): ";
    cin >> primerPlato;

    cout << "Ingrese N° Plato Principal (1-Tallarines, 2-Asado, 3-Hamburguesa Completa, 4-Pastel de Papa, 5-Milanesa): ";
    cin >> platoPrincipal;

    cout << "Ingrese N° Postre (1-Helado, 2-Flan, 3-Torta): ";
    cin >> postre;

    // Mostrar comanda
    cout << "\n\t=== COMANDA ===" << endl;
    cout << "Numero de mesa: " << mesa << endl;
    cout << "Mozo: " << mozo << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Hora: " << hora << endl;
    cout << "Primer Plato: " << getPrimerPlato(primerPlato - 1) << endl;
    cout << "Plato Principal: " << getPlatoPrincipal(platoPrincipal - 1) << endl;
    cout << "Postre: " << getPostre(postre - 1) << endl;

    pauseConsole();
    return 0;
}

// Implementación de funciones
string getPrimerPlato(int opcion) {
    switch(opcion) {
        case empanada: return "Empanada";
        case ensalada_rusa: return "Ensalada Rusa";
        case sopa: return "Sopa";
        default: return "Desconocido";
    }
}

string getPlatoPrincipal(int opcion) {
    switch(opcion) {
        case tallarines: return "Tallarines";
        case asado: return "Asado";
        case hamburguesaCompleta: return "Hamburguesa Completa";
        case pastelDePapa: return "Pastel de Papa";
        case milanesa: return "Milanesa";
        default: return "Desconocido";
    }
}

string getPostre(int opcion) {
    switch(opcion) {
        case helado: return "Helado";
        case flan: return "Flan";
        case torta: return "Torta";
        default: return "Desconocido";
    }
}

void pauseConsole() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void clearConsole() {
#ifdef __unix__
    system("clear");
#elif __APPLE__
    system("clear");
#elif defined(_WIN32) || defined(WIN32) || defined(WIN64)
    system("cls");
#endif
}
