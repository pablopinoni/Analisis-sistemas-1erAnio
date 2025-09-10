#include <iostream>
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
string cadFruta(tFrutas fruta);
string cadMes(tMes mes);
void mostrarMenuFrutas();
void mostrarMenuMes();
void clearConsole();

int main() {
    string proveedor;
    string razonSocial;
    int diaSolicitud, mesSolicitud, anioSolicitud;
    int diaEntrega, mesEntrega, anioEntrega;
    tFrutas frutaSeleccionada;
    int opcionFruta;
    bool seleccionValida = false;

    cout << "\n\t\t#==============#" << endl;
    cout << "\t\t     PEDIDOS" << endl;  
    cout << "\t\t#==============#\n" << endl;

    // Pedido de carga de datos al usuario
    cout << "Ingrese codigo de proveedor: ";
    cin.ignore();
    getline(cin, proveedor);

    cout << "\nIngrese Razon Social: ";
    getline(cin, razonSocial);

    // Selección de fruta
    do {
        mostrarMenuFrutas();
        cout << "Seleccione fruta (0-5): ";
        cin >> opcionFruta;

        if (opcionFruta >= 0 && opcionFruta <= 5) {
            frutaSeleccionada = static_cast<tFrutas>(opcionFruta);
            seleccionValida = true;
        } else {
            cout << "Error: Opción inválida. Intente nuevamente.\n";
        }
    } while (!seleccionValida);

    // Fecha de solicitud
    cout << "\nFecha de solicitud (dd mm aaaa): ";
    cin >> diaSolicitud >> mesSolicitud >> anioSolicitud;

    // Fecha de entrega
    cout << "\nFecha de entrega (dd mm aaaa): ";
    cin >> diaEntrega >> mesEntrega >> anioEntrega;

    // Mostrar resumen del pedido
    clearConsole();
    cout << "\n\t\t#===================#" << endl;
    cout << "\t\t   RESUMEN PEDIDO" << endl;
    cout << "\t\t#===================#\n\n" << endl;
    cout << "\tProveedor: " << proveedor << endl;
    cout << "\tRazón Social: " << razonSocial << endl;
    cout << "\tFruta seleccionada: " << cadFruta(frutaSeleccionada) << endl;
    cout << "\tFecha de solicitud: " << diaSolicitud << "/" << mesSolicitud << "/" << anioSolicitud << endl;
    cout << "\tFecha de entrega: " << diaEntrega << "/" << mesEntrega << "/" << anioEntrega << endl;
    cout <<  "\n#==================------=================#\t\t\n" << endl;
    return 0;
}

// Implementación de funciones
string cadFruta(tFrutas fruta) {
    switch(fruta) {
        case manzana: return "Manzana";
        case banana: return "Banana";
        case pera: return "Pera";
        case uva: return "Uva";
        case melon: return "Melon";
        case sandia: return "Sandia";
        default: return "Desconocida";
    }
}

string cadMes(tMes mes) {
    switch(mes) {
        case enero: return "Enero";
        case febrero: return "Febrero";
        case marzo: return "Marzo";
        case abril: return "Abril";
        case mayo: return "Mayo";
        case junio: return "Junio";
        case julio: return "Julio";
        case agosto: return "Agosto";
        case septiembre: return "Septiembre";
        case octubre: return "Octubre";
        case noviembre: return "Noviembre";
        case diciembre: return "Diciembre";
        default: return "Desconocido";
    }
}

void mostrarMenuFrutas() {
    cout << "\nOpciones de frutas:" << endl;
    cout << "0 - Manzana" << endl;
    cout << "1 - Banana" << endl;
    cout << "2 - Pera" << endl;
    cout << "3 - Uva" << endl;
    cout << "4 - Melón" << endl;
    cout << "5 - Sandía" << endl;
}

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear"); //Mac o Linux
    #endif
}