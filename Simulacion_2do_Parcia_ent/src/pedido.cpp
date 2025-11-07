#include "pedido.h"
#include <iostream>
using namespace std;

Pedido::Pedido(string _code, Cliente* cliente)
    : code(_code), pCliente(cliente), numArticulos(0)
{
    for (int i = 0; i < MAX_ITEMS; i++) {
        pArticles[i] = nullptr;
        cantidades[i] = 0;
    }
}

Pedido::~Pedido()
{
    cout << "Pedido destruido" << endl;
}

string Pedido::getCode()
{
    return this->code;
}

void Pedido::add(Articulo* pArticulo, int cantidad)
{
    if (numArticulos < MAX_ITEMS) {
        pArticles[numArticulos] = pArticulo;
        cantidades[numArticulos] = cantidad;
        numArticulos++;
    } else {
        cout << "Error: No se pueden agregar más artículos. El pedido está lleno." << endl;
    }
}

void Pedido::show()
{
    cout << "-------------------------------------" << endl;
    cout << "Pedido Nro: " << getCode() << endl;
    cout << "Cliente: " << pCliente->getName() << endl;
    cout << "Direccion: " << pCliente->getAddress() << endl;
    cout << "Artículos:" << endl;

    double total = 0.0;

    for (int i = 0; i < numArticulos; i++) {
        double subtotal = pArticles[i]->getPrecio() * cantidades[i];
        total += subtotal;

        cout << "  - " << pArticles[i]->getName()
             << " x" << cantidades[i]
             << " ($" << pArticles[i]->getPrecio()
             << ") = $" << subtotal << endl;
    }

    cout << "TOTAL PEDIDO: $" << total << endl;
    cout << "-------------------------------------" << endl << endl;
}
