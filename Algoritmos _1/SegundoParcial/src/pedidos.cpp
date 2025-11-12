#include <iostream>
#include "pedidos.h"
#include "clientes.h" // Necesario para Cliente::getName(), getCode()
#include "empleados.h" // Necesario para Empleado::getName(), getCode()

// Constructor
Pedido::Pedido(const std::string& code, Cliente* cliente, Empleado* empleado)
    : code(code), cliente(cliente), empleado(empleado), cantArticulos(0) {
}

// Destructor
Pedido::~Pedido() {
    // No necesita hacer nada si no hay memoria dinámica
}

// Getter de código
std::string Pedido::getCode() {
    return code;
}

// Método para agregar artículo (recibe puntero y cantidad)
void Pedido::add(Articulo* pArticulo, int cantidad) {
    if (cantArticulos < 256 && pArticulo != nullptr) {
        for (int i = 0; i < cantidad && cantArticulos < 256; i++) {
            // Copia el objeto Articulo en el array estático
            articulos[cantArticulos] = *pArticulo; 
            cantArticulos++;
        }
    }
}

// Método para mostrar el pedido
void Pedido::show() {
    std::cout << "Pedido: " << code << std::endl;
    if (cliente) {
        std::cout << "Cliente: " << cliente->getName() 
                  << " (Codigo: " << cliente->getCode() << ")" << std::endl;
    }
    if (empleado) {
        std::cout << "Atendido por: " << empleado->getName() 
                  << " (Codigo: " << empleado->getCode() << ")" << std::endl;
    }
    std::cout << "Articulos:" << std::endl;
    for (int i = 0; i < cantArticulos; i++) {
        std::cout << " - " << articulos[i].getName() 
                  << " (Codigo: " << articulos[i].getCode() 
                  << ", Precio: $" << articulos[i].getPrecio() << ")" << std::endl;
    }
    std::cout << "-----------------------------\n";
}