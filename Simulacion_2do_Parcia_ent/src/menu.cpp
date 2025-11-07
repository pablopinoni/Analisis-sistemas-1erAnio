#include "menu.h"
using namespace std;

// Inicialización de arrays estáticos
Articulo* Menu::articulos[MAX_ELEMENTS];
Cliente* Menu::clientes[MAX_ELEMENTS];
Pedido* Menu::pedidos[MAX_ELEMENTS];
int Menu::numArticulos = 0;
int Menu::numClientes = 0;
int Menu::numPedidos = 0;

// ========================
// FUNCIONES DE LECTURA
// ========================
string Menu::readString(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

float Menu::readFloat(const string& prompt) {
    float value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Entrada inválida. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(); // limpiar salto de línea
    return value;
}

// ========================
// CRUD BÁSICO
// ========================
void Menu::cargarArticulos() {
    cout << "\n--- Alta de Artículo ---\n";
    string code = readString("Código: ");
    string name = readString("Nombre: ");
    float precio = readFloat("Precio: ");
    articulos[numArticulos++] = new Articulo(code, name, precio);
}

void Menu::cargarClientes() {
    cout << "\n--- Alta de Cliente ---\n";
    string code = readString("Código: ");
    string name = readString("Nombre: ");
    string address = readString("Dirección: ");
    clientes[numClientes++] = new Cliente(code, name, address);
}

void Menu::cargarPedidos() {
    cout << "\n--- Alta de Pedido ---\n";
    string codigoPedido = readString("Código de Pedido: ");
    string codigoCliente = readString("Código de Cliente: ");
    Cliente* cli = buscarCliente(codigoCliente);
    if (!cli) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    Pedido* pedido = new Pedido(codigoPedido, cli);

    char opcion;
    do {
        string codigoArticulo = readString("Código de Artículo: ");
        Articulo* art = buscarArticulo(codigoArticulo);
        if (!art) {
            cout << "Artículo no encontrado.\n";
        } else {
            int cantidad;
            cout << "Cantidad: ";
            cin >> cantidad;
            cin.ignore();
            pedido->add(art, cantidad);
        }
        cout << "¿Agregar otro artículo? (s/n): ";
        cin >> opcion;
        cin.ignore();
    } while (tolower(opcion) == 's');

    pedidos[numPedidos++] = pedido;
}

// ========================
// MOSTRAR DATOS
// ========================
void Menu::mostrarArticulos() {
    cout << "\n--- Lista de Artículos ---\n";
    for (int i = 0; i < numArticulos; i++) {
        cout << articulos[i]->getCode() << " - "
             << articulos[i]->getName() << " - $"
             << articulos[i]->getPrecio() << endl;
    }
}

void Menu::mostrarClientes() {
    cout << "\n--- Lista de Clientes ---\n";
    for (int i = 0; i < numClientes; i++) {
        cout << clientes[i]->getCode() << " - "
             << clientes[i]->getName() << " - "
             << clientes[i]->getAddress() << endl;
    }
}

void Menu::mostrarPedidos() {
    cout << "\n--- Lista de Pedidos ---\n";
    for (int i = 0; i < numPedidos; i++) {
        pedidos[i]->show();
    }
}

// ========================
// AUXILIARES
// ========================
Cliente* Menu::buscarCliente(const string& code) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i]->getCode() == code)
            return clientes[i];
    }
    return nullptr;
}

Articulo* Menu::buscarArticulo(const string& code) {
    for (int i = 0; i < numArticulos; i++) {
        if (articulos[i]->getCode() == code)
            return articulos[i];
    }
    return nullptr;
}

void Menu::liberarMemoria() {
    for (int i = 0; i < numArticulos; i++) delete articulos[i];
    for (int i = 0; i < numClientes; i++) delete clientes[i];
    for (int i = 0; i < numPedidos; i++) delete pedidos[i];
}

// ========================
// INTERFAZ
// ========================
int Menu::showMainMenu() {
    cout << "\n===== MENÚ PRINCIPAL =====\n";
    cout << "1. Alta de Artículo\n";
    cout << "2. Alta de Cliente\n";
    cout << "3. Alta de Pedido\n";
    cout << "4. Mostrar Artículos\n";
    cout << "5. Mostrar Clientes\n";
    cout << "6. Mostrar Pedidos\n";
    cout << "0. Salir\n";
    cout << "Opción: ";

    int option;
    cin >> option;
    cin.ignore();
    return option;
}

void Menu::ejecutar() {
    int op;
    do {
        op = showMainMenu();
        switch (op) {
            case 1: cargarArticulos(); break;
            case 2: cargarClientes(); break;
            case 3: cargarPedidos(); break;
            case 4: mostrarArticulos(); break;
            case 5: mostrarClientes(); break;
            case 6: mostrarPedidos(); break;
            case 0: liberarMemoria(); cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (op != 0);
}
