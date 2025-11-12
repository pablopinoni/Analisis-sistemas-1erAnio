#pragma once
#include "../include/articulo.h"
#include "clientes.h"
#include <string>


class Cliente; 
class Empleado; 

// Articulo se usa por valor dentro del array articulos[], así que NO se puede declarar adelante.
//#include "articulo.h" 

class Pedido {
private:
    static const int MAX_ARTICULOS = 256; // Se define en pedidos.cpp pero es mejor tenerlo aquí
    std::string code;
    Cliente* cliente;
    Empleado* empleado;
    Articulo articulos[MAX_ARTICULOS]; // Articulo se usa por VALOR (no puntero)
    int cantArticulos;

public:
    Pedido(const std::string& code, Cliente* cliente, Empleado* empleado);
    ~Pedido(); 
    std::string getCode();
    void add(Articulo* pArticulo, int cantidad);
    void show();
};