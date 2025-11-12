#include <iostream>
#include <string>
#include "../include/menu.h"
// Incluimos headers de clases base para la inicialización estática
#include "../include/articulo.h" 
#include "../include/clientes.h"
#include "../include/empleados.h"
#include "../include/pedidos.h"


// Inicialización de variables estáticas
// Nota: MAX_ELEMENTS se define en menu.h
Articulo* Menu::articulos[100]; // Reemplaza MAX_ELEMENTS con 100 si no compila
int Menu::numArticulos = 0;

Cliente* Menu::clientes[100]; // Reemplaza MAX_ELEMENTS con 100 si no compila
int Menu::numClientes = 0;

Empleado* Menu::empleados[100]; // Reemplaza MAX_ELEMENTS con 100 si no compila
int Menu::numEmpleados = 0;

Pedido* Menu::pedidos[100]; // Reemplaza MAX_ELEMENTS con 100 si no compila
int Menu::numPedidos = 0;

void Menu::ejecutar() {
    inicializarEmpleados();  // Carga E001, E002, E003
    inicializarClientes();   // Carga C001, C002 (Añadido para testeo)

    int opcion;
    do {
        opcion = showMainMenu();
        switch (opcion) {
            case 1:
                cargarArticulos();
                break;
            case 2:
                cargarClientes();
                break;
            case 3:
                cargarPedidos();
                break;
            case 4:
                mostrarPedidos();
                break;
            case 5:
                mostrarEmpleados();
                break;
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    liberarMemoria();
}

int Menu::showMainMenu() {
    std::cout << "\n=== MENU ===\n";
    std::cout << "1. Cargar Articulos\n";
    std::cout << "2. Cargar Clientes\n";
    std::cout << "3. Cargar Pedidos\n";
    std::cout << "4. Mostrar pedidos de Clientes\n";
    std::cout << "5. Mostrar Empleados\n";
    std::cout << "0. Salir\n";
    std::cout << "Elija una opcion: ";

    int opcion;
    std::cin >> opcion;
    return opcion;
}

void Menu::cargarArticulos() {
    if (numArticulos >= MAX_ELEMENTS) {
        std::cout << "No se pueden cargar mas Articulos.\n";
        return;
    }

    std::string code = readString("Ingrese codigo del Articulo: ");
    std::string name = readString("Ingrese nombre del Articulo: ");
    float precio = readFloat("Ingrese precio del Articulo: ");

    articulos[numArticulos] = new Articulo(code, name, precio);
    numArticulos++;
    std::cout << "Articulo agregado.\n";
}

void Menu::cargarClientes() {
    if (numClientes >= MAX_ELEMENTS) {
        std::cout << "No se pueden cargar mas clientes.\n";
        return;
    }

    std::string code = readString("Ingrese codigo del cliente: ");
    std::string name = readString("Ingrese nombre del cliente: ");
    std::string address = readString("Ingrese direccion del cliente: ");

    clientes[numClientes] = new Cliente(code, name, address);
    numClientes++;
    std::cout << "Cliente agregado.\n";
}


   void Menu::cargarPedidos() {
    if (numPedidos >= MAX_ELEMENTS) {
        std::cout << "No se pueden cargar mas pedidos.\n";
        return;
    }

    if (numClientes == 0) {
        std::cout << "No hay clientes cargados.\n";
        return;
    }

    if (numEmpleados == 0) {
        std::cout << "No hay empleados disponibles.\n";
        return;
    }

    if (numArticulos == 0) {
        std::cout << "No hay artículos disponibles.\n";
        return;
    }

    std::string clienteCode = readString("Ingrese codigo del cliente: ");
    Cliente* cliente = buscarCliente(clienteCode);
    if (!cliente) {
        std::cout << "Cliente no encontrado.\n";
        return;
    }

    std::string empleadoCode = readString("Ingrese codigo del empleado: ");
    Empleado* empleado = buscarEmpleado(empleadoCode);
    if (!empleado) {
        std::cout << "Empleado no encontrado.\n";
        return;
    }

    std::string pedidoCode = readString("Ingrese codigo del pedido: ");
    pedidos[numPedidos] = new Pedido(pedidoCode, cliente, empleado);

    // Agregar artículos al pedido
    std::string continuar;
    do {
        std::string articuloCode = readString("Ingrese codigo del articulo: ");
        Articulo* articulo = buscarArticulo(articuloCode);
        if (!articulo) {
            std::cout << "Articulo no encontrado.\n";
        } else {
            int cantidad = (int)readFloat("Ingrese cantidad: ");
            pedidos[numPedidos]->add(articulo, cantidad);
            std::cout << "Articulo agregado al pedido.\n";
        }

        continuar = readString("¿Agregar otro articulo? (s/n): ");
    } while (continuar == "s" || continuar == "S");

    numPedidos++;
    std::cout << "Pedido agregado.\n";
}

void Menu::mostrarPedidos() {
    if (numPedidos == 0) {
        std::cout << "No hay pedidos.\n";
        return;
    }

    for (int i = 0; i < numPedidos; i++) {
        pedidos[i]->show();
    }
}

void Menu::mostrarEmpleados() {
    if (numEmpleados == 0) {
        std::cout << "No hay empleados.\n";
        return;
    }

    for (int i = 0; i < numEmpleados; i++) {
        std::cout << "Empleado: " << empleados[i]->getCode() 
                  << " - " << empleados[i]->getName() 
                  << " - Comision: " << empleados[i]->getComisionPercent() << "%\n";
    }
}

// IMPLEMENTACIÓN DE INICIALIZACIÓN DE EMPLEADOS
void Menu::inicializarEmpleados() {
    if (numEmpleados == 0 && MAX_ELEMENTS >= 3) {
        // Hardcodeamos 3 empleados
        empleados[0] = new Empleado("E001", "Ana Gómez", 5.0f);
        empleados[1] = new Empleado("E002", "Luis Pérez", 4.5f);
        empleados[2] = new Empleado("E003", "María López", 6.0f);
        numEmpleados = 3;
        std::cout << "Empleados hardcodeados cargados.\n";
    }
}

// NUEVA IMPLEMENTACIÓN DE INICIALIZACIÓN DE CLIENTES (PARA DEBUG)
void Menu::inicializarClientes() {
    if (numClientes == 0 && MAX_ELEMENTS >= 2) {
        clientes[0] = new Cliente("C001", "Pablo", "Calle Falsa 123");
        clientes[1] = new Cliente("C002", "Laura", "Avenida Siempre Viva 456");
        numClientes = 2;
        std::cout << "Clientes hardcodeados cargados.\n";
    }
}


Cliente* Menu::buscarCliente(const std::string& code) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i]->getCode() == code) {
            return clientes[i];
        }
    }
    return nullptr;
}

Articulo* Menu::buscarArticulo(const std::string& code) {
    for (int i = 0; i < numArticulos; i++) {
        if (articulos[i]->getCode() == code) {
            return articulos[i];
        }
    }
    return nullptr;
}

Empleado* Menu::buscarEmpleado(const std::string& code) {
    for (int i = 0; i < numEmpleados; i++) {
        // Nota: Asumiendo que getCode() es correcto y que numEmpleados es 3.
        if (empleados[i]->getCode() == code) {
            return empleados[i];
        }
    }
    return nullptr;
}

// Funciones de utilidad de lectura
std::string Menu::readString(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    // La línea de abajo resuelve el problema del buffer del ENTER/newline
    if (std::cin.peek() == '\n') std::cin.ignore(); 
    std::getline(std::cin, input);
    return input;
}

float Menu::readFloat(const std::string& prompt) {
    std::cout << prompt;
    float input;
    std::cin >> input;
    return input;
}

void Menu::liberarMemoria() {
    for (int i = 0; i < numArticulos; i++) delete articulos[i];
    for (int i = 0; i < numClientes; i++) delete clientes[i];
    for (int i = 0; i < numEmpleados; i++) delete empleados[i];
    for (int i = 0; i < numPedidos; i++) delete pedidos[i];
}