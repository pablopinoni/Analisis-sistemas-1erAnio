#pragma once
#include <string>
#include "articulo.h"
#include "clientes.h"
#include "empleados.h"
#include "pedidos.h"

class Menu {
private:
    static const int MAX_ELEMENTS = 100;

    static Articulo* articulos[MAX_ELEMENTS];
    static int numArticulos;

    static Cliente* clientes[MAX_ELEMENTS];
    static int numClientes;

    static Empleado* empleados[MAX_ELEMENTS];
    static int numEmpleados;

    static Pedido* pedidos[MAX_ELEMENTS];
    static int numPedidos;
   
    static void inicializarEmpleados();
    static void inicializarClientes();  // 👈 Bien

public:
    static void ejecutar();

private:
    static int showMainMenu();
    static void cargarArticulos();
    static void cargarClientes();
    static void cargarPedidos();
    static void mostrarPedidos();
    static void mostrarEmpleados();

    static Cliente* buscarCliente(const std::string& code);
    static Articulo* buscarArticulo(const std::string& code);
    static Empleado* buscarEmpleado(const std::string& code);

    static std::string readString(const std::string& prompt);
    static float readFloat(const std::string& prompt);

    static void liberarMemoria();
};