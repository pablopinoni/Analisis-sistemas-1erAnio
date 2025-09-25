#include <iostream>
#include "Order.hpp"
using namespace std;

Order::Order(string _code, Customer* _customer)
    : code(_code), customer(_customer), numArticles(0)
{
    // Inicializamos todos los punteros a nullptr
    for (int i = 0; i < MAX_ITEMS; i++) {
        articles[i] = nullptr;
    }
}

Order::~Order()   // solo a modo de prueba
{
    cout << "Pedido destruido" << endl;
}

string Order::getCode()
{
    return this->code;
}

void Order::add(Article* _article)
{
    if (numArticles < MAX_ITEMS) {
        articles[numArticles++] = _article;
    } else {
        cout << "Error: No se pueden agregar más artículos. El pedido está lleno." << endl;
    }
}

void Order::show()
{
    cout << "Pedido Nro: " << getCode() << endl;
    cout << "Cliente: " << customer->getName() << " " << customer->getSurname() << endl;
    cout << "Direccion: " << customer->getAddress() << endl;
    cout << "Articulos: " << endl;

    for(int i = 0; i < numArticles; i++)
    {
        cout << "  - " << articles[i]->getName() << " (" << articles[i]->getCode() << "): $" << articles[i]->getPrice() << endl;
    }

    cout << "-------------------------------------" << endl;
    cout << endl;
}