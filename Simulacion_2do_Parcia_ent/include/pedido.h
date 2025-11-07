#ifndef PEDIDO_H
#define PEDIDO_H //probar con #pragma once

#include <string>
#include "cliente.h"
#include "articulo.h"

const int MAX_ITEMS = 20;

class Pedido {
private:
    std::string code;
    Cliente* pCliente;
    Articulo* pArticles[MAX_ITEMS];
    int cantidades[MAX_ITEMS]; // 👈 NUEVO: arreglo de cantidades
    int numArticulos;

public:
    Pedido(std::string _code, Cliente* cliente);
    ~Pedido();

    std::string getCode();

    void add(Articulo* pArticulo, int cantidad); // 👈 NUEVO: recibe cantidad
    void show();
};

#endif
