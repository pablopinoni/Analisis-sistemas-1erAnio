/*Un Verdulería nos pide que armemos el pedido para el mayorista para lo cual
deberemos pedir al usuario el código proveedor, razón social, fecha de
solicitud y fecha de entrega. Las frutas estarán enumeradas (tomar solo 6 a
modo de ejemplo), mostrando los datos x pantalla.*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

// ============================
// ENUMERACIONES
// ============================

typedef enum { manzana, banana, pera, uva, melon, sandia } tFrutas;

typedef enum { enero, febrero, marzo, abril, mayo,
    junio, julio, agosto, septiembre, octubre,
    noviembre, diciembre } tMes;

// ============================
// PROTOTIPOS
// ============================
// Funciones
string cadFruta();
string cadMes();
string fechaSolicitud();
string fechaPedido();

//Funciiones Auxiliares

void mostrarMenuSolicitud();
void mostrarMenuEntrega();
void mostrarMenuFrutas();
void mostrarMenuMes();
void clearConsole();


int main() {





string proveedor;
string razonSocial;
string cadMes;
int case;
string tFrutas a;
    cout << "\n\t\t#==============#"  << endl;
    cout << "\t\t     PEDIDOS" << endl;  
    cout << "\t\t#==============#"  << endl;

    
// Pedido de carga de datos al usuario


 
 // proveedor

    cout << "Ingrese codigo de proveedor: " << endl;
    cin.ignore ();
    getline(cin,proveedor);
        


    //  Razon social
    cout << "\nIngrese Razon Social: " << endl;
    cin.ignore ();
    getline(cin, razonSocial);



    do {
        cout << "Seleccione fruta: (0-6): ";
        mostrarMenuFrutas();
        cin >> opcion;

        
        
        } else {
            cout << "Error: Opción inválida. Intente nuevamente.\n";
        }
    } while (!verdadero);

}


//Declaracion Funciones Principales



void mostrarMenuFrutas() {
    string getClase(tClase_boleto a) {
        switch(a) {
            case primera: return "Primera Clase";
            case business: return "Business";
            case economica: return "Económica";
            default: return "Desconocida";
        }
    }
    


}








//Declaracion Funciones auxiliares
void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear"); //Mac o Linux
    #endif
    }