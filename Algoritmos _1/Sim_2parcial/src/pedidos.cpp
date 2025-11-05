#include <iostream>
#include "pedidos.h"
#include "constants.h" 
#include "clientes.h"  
#include "articulos.h" 

using namespace std;

// Constructor: Inicializa code, customer y los miembros de la estructura items
Order::Order(string _code, Customer* _customer)
    : code(_code), customer(_customer)
{
    // Inicializar el contador de artículos a 0
    this->items.numArticles = 0;
    
    // Inicializar todos los punteros del array a nullptr. 
    // Usamos la constante calificada y accedemos al array a través de items.
    // CRÍTICO: Usar MAX_ARTICLES para el tamaño del array de artículos.
    for (int i = 0; i < Constants::MAX_ARTICLES; i++) { 
        this->items.articles[i] = nullptr;
    }


//Order::~Order()

    // Liberar la memoria de CADA objeto Article apuntado
    for (int i = 0; i < this->items.numArticles; i++)
    {
        if (this->items.articles[i] != nullptr) { 
            delete this->items.articles[i];       
            this->items.articles[i] = nullptr; 
        }
    }
    cout << "Pedido destruido" << endl;
}

string Order::getCode() const
{
    return this->code;
}

void Order::addArticle(Article* _article) 
{
    // Usamos MAX_ARTICLES para chequear el límite del array interno.
    if (this->items.numArticles < Constants::MAX_ARTICLES) { 
        this->items.articles[this->items.numArticles++] = _article;
    } else {
        cout << "Error: No se pueden agregar más artículos. El pedido está lleno." << endl;
    }
}

void Order::show() const
{
    cout << "Pedido Nro: " << getCode() << endl;
    cout << "Cliente: " << customer->getName() << " " << customer->getSurname() << endl;
    cout << "Direccion: " << customer->getAddress() << endl;
    cout << "Articulos: " << endl;

    for(int i = 0; i < this->items.numArticles; i++)
    {
        cout << "  - " << this->items.articles[i]->getName() << " (" << this->items.articles[i]->getCode() << "): $" << this->items.articles[i]->getPrice() << endl;
    }

    cout << "-------------------------------------" << endl;
    cout << endl;
}