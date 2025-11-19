// src/pedido.cpp
#include "pedido.hpp"
#include <iostream>

// Constructor
Pedido::Pedido(std::string _code, Cliente* cliente, std::string _date)
    : code(_code), pCliente(cliente), numAnimales(0), monto(0.0f), date(_date) {
    // Inicializa arrays a valores por defecto
    for (int i = 0; i < Constants::MAX_ITEMS_PEDIDO; ++i) {
        pAnimales[i] = nullptr;
        cantidades[i] = 0;
    }
}

// Destructor
Pedido::~Pedido() {
    // No eliminamos pCliente ni animales aquí (no los creamos con new en esta clase)
}

// Getters
std::string Pedido::getCode() {
    return code;
}

Cliente* Pedido::getCustomer() {
    return pCliente;
}

std::string Pedido::getDate() {
    return date;
}

float Pedido::getMonto() {
    return monto;
}

int Pedido::getNumAnimales() {
    return numAnimales;
}

Animal* Pedido::getAnimal(int posPArray) {
    if (posPArray >= 0 && posPArray < numAnimales) {
        return pAnimales[posPArray];
    }
    return nullptr;  // Índice fuera de rango
}

int Pedido::getCantidadXAnimal(int posPArray) {
    if (posPArray >= 0 && posPArray < numAnimales) {
        return cantidades[posPArray];
    }
    return 0;  // Índice fuera de rango
}

// Métodos de gestión
void Pedido::attachAnimal(Animal* pAnimal, int cantidad) {
    if (numAnimales < Constants::MAX_ITEMS_PEDIDO && pAnimal != nullptr && cantidad > 0) {
        pAnimales[numAnimales] = pAnimal;
        cantidades[numAnimales] = cantidad;
        numAnimales++;
        calcularMonto();  // Recalcula monto después de añadir animal
    }
}

void Pedido::detachAnimal(int indice) {
    if (indice >= 0 && indice < numAnimales) {
        // Mueve todos los elementos después de indice una posición hacia atrás
        for (int i = indice; i < numAnimales - 1; ++i) {
            pAnimales[i] = pAnimales[i + 1];
            cantidades[i] = cantidades[i + 1];
        }
        numAnimales--;
        pAnimales[numAnimales] = nullptr;  // Limpia la última posición
        cantidades[numAnimales] = 0;
        calcularMonto();  // Recalcula monto después de eliminar animal
    }
}

void Pedido::calcularMonto() {
    monto = 0.0f;
    // Cálculo simple basado en peso y cantidad
    for (int i = 0; i < numAnimales; ++i) {
        if (pAnimales[i] != nullptr) {
            float precioPorKg = 1000.0f;  // Precio base
            monto += pAnimales[i]->getPeso() * cantidades[i] * precioPorKg;
        }
    }
}
void Pedido::agregarAnimal(Animal* animal, int cantidad) {
    if (numAnimales < Constants::MAX_ITEMS_PEDIDO && animal != nullptr && cantidad > 0) {
        pAnimales[numAnimales] = animal;
        cantidades[numAnimales] = cantidad;
        numAnimales++;
        calcularMonto();
    }
}

void Pedido::eliminarAnimal(int indice) {
    if (indice >= 0 && indice < numAnimales) {
        for (int i = indice; i < numAnimales - 1; ++i) {
            pAnimales[i] = pAnimales[i + 1];
            cantidades[i] = cantidades[i + 1];
        }
        numAnimales--;
        pAnimales[numAnimales] = nullptr;
        cantidades[numAnimales] = 0;
        calcularMonto();
    }
}

int Pedido::getCantidadAnimales() const {
    return numAnimales;
}

Animal* Pedido::getAnimal(int indice) const {
    if (indice >= 0 && indice < numAnimales) {
        return pAnimales[indice];
    }
    return nullptr;
}

int Pedido::getCantidadPorIndice(int indice) const {
    if (indice >= 0 && indice < numAnimales) {
        return cantidades[indice];
    }
    return 0;
}