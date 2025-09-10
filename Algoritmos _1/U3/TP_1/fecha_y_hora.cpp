#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

// ============================
// ENUMERACIONES
// ============================

typedef enum { enero, febrero, marzo, abril, mayo,
    junio, julio, agosto, septiembre, octubre,
    noviembre, diciembre } tMes;

typedef enum { lunes, martes, miercoles, jueves,
    viernes, sabado, domingo } tDiaSemana;

// ============================
// PROTOTIPOS
// ============================

string cadMes(tMes mes);
string cadDia(tDiaSemana dia);

 int main() {

        tDiaSemana hoy = lunes;
        
        int dia = 04;
        
        tMes mes = junio;
        
        int anio = 2021;
        cout << "Hoy es: " << cadDia(hoy) << " " << dia << " de " << cadMes(mes) << " de " << anio

<< endl;
 }

