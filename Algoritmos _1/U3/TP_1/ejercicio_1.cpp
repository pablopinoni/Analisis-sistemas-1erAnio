//Una aplicación para un restaurante que tiene: primer plato, plato principal y
//poste, toma pedidos de los mozos. Estos envían la comanda codificada por
//numero para cada plato. El cocinero recibe el pedido en formato de texto con
//el nro de mesa, nombre mozo, fecha, hora, primer plato, plato principal y
//poste. Se pide desarrollar una APP que pida la comanda y muestre por
//pantalla la Info solicitada.


#include <iostream>
#include <string>
#include <cstdlib>
#include<limits>
#include <iomanip>
using namespace std;


// Enumeraciones

typedef enum { empanada, ensalada_rusa, sopa} tPrimerPlato;

typedef enum  { tallarines, asado, hamburguesaCompleta, pastelDePapa, milanesa} tPlatoPrincipal;

typedef enum {helado, flan, budinDePan } tPostre;

typedef enum { enero, febrero, marzo, abril, mayo,
    junio, julio, agosto, septiembre, octubre,
    noviembre, diciembre } tMes;

typedef enum { lunes, martes, miercoles, jueves,
    viernes, sabado, domingo } tDiaSemana;


//Prototipos de Fun
string getPrimerPlato(int opcion);
string getPlatoPrincipal(int opcion);
string getPostre(int opcion);

//Funciones Auxiliares
void clearConsole();
void pauseConsole();

int main()
{
    int mesa, hora, primerPlato, platoPrincipal, postre;
    string mozo, fecha;
    int opcion;
     
   clearConsole();

    cout << "\t\tCOMANDAS"; // Salida
    cout << "\n\t=====================\n" << endl;
    // Pedido de carga de datos al usuario, mozo, de manera codificada

    cout << "Ingrese numero de mesa: " << endl;
    cin >> mesa;

    cout << "Ingrese nombre: " << endl;
    //cin.ignore(); // Limpia  buffer
    cin >> mozo;

    cout << "Ingrese fecha (mes día): " << endl;
    cin >> fecha;

    cout << "Ingrese hora (hh : mm): " << endl;
    cin >> hora; 

    
    cout << "Ingrese N Primer Plato (1-3): " << endl;
    cin >> primerPlato;
    
    cout << "Ingrese N Plato Principal (1-5): " << endl;
    cin >> platoPrincipal;
    
    cout << "Ingrese N Postre (1-3): " << endl;
    cin >> postre;
    
   
    // Salida = mostar comanda

   cout << "\n\t=====================\n" << endl;
   cout << "Numero de mesa: " << mesa << endl;
   cout << "Mozo : " << mozo << endl;
   cout << "Fecha: " << fecha << endl;
   cout << "Hora: " << hora << endl;
   cout << "Primer Plato: " << getPrimerPlato(opcion) << endl;
   cout << "Plato Principal:" << getPlatoPrincipal(opcion) << endl;
   cout << "Postre: " << getPostre(opcion)  << endl;
   cout << "\n\n\t\t======================================\t\t\n"; 

}


// string enumerados

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
        case milanesa: return "Suprema a la Maryland";
        default: return "Desconocido";
    }
}

string getPostre(int opcion) {
    switch(opcion) {
        case helado: return "Helado";
        case flan: return "Flan";
        case budinDePan: return "Torta";
        default: return "Desconocido";
    }
}

// Fumciones auxiliares
void pauseConsole()
{
    cin.ignore();
    cin.get();
}

void clearConsole()
{
    #ifdef __unix__
        system("clear");
    #elif __APPLE__   
        system("clear");    
    #elif defined(_WIN32)  ||  defined(WIN32) ||  defined(WIN64) 
        system("cls"); 
    #endif //Defined
    }
