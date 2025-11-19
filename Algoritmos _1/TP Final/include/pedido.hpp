//pedido.hpp
#pragma once

#include <string>
#include "cliente.hpp"
#include "animal.hpp"
#include "constants.hpp"



class Pedido {
private:
    std::string code;
    Cliente* pCliente;
    Animal* pAnimales[Constants::MAX_ITEMS_PEDIDO];
    int cantidades[Constants::MAX_ITEMS_PEDIDO];
    int numAnimales;
    float monto;
    std::string date;

public:
    Pedido(std::string _code, Cliente* cliente, std::string _date);
    ~Pedido();

    std::string getCode();
    Cliente* getCustomer();
    std::string getDate();
    float getMonto();
    void attachAnimal(Animal* pAnimal, int cantidad);
    void detachAnimal(int indice);
    void calcularMonto();
    int getNumAnimales();
    Animal* getAnimal(int posPArray);
    int getCantidadXAnimal(int posPArray);


   
};
