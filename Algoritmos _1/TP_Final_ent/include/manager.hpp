// include/manager.hpp
#pragma once
#include <string>
#include "animal.hpp"
#include "cliente.hpp"
#include "pedido.hpp"
#include "constants.hpp"

class Manager {
private:
    // Arrays de punteros para las colecciones
    Animal* pAnimales[Constants::MAX_ANIMALES];
    Cliente* pClientes[Constants::MAX_CLIENTES];
    Pedido* pPedidos[Constants::MAX_PEDIDOS];
    
    // Contadores reales (cantidad actual en cada array)
    int numAnimales;
    int numClientes;
    int numPedidos;

public:
    // Constructor y destructor
    Manager();
    ~Manager();

    // Métodos para animales
    bool agregarAnimal(Animal* animal);
    Animal* getAnimal(int posPArray);
    int getNumAnimales();
    void ejecutarPolimorfismo();
    void feedAnimals();
    void sleepAnimals();
    void showAnimals();

    // Métodos para clientes
    bool agregarCliente(Cliente* cliente);
    Cliente* getCliente(int posPArray);
    int getNumClientes();
    void showClientes();

    // Métodos para pedidos
    bool agregarPedido(Pedido* pedido);
    Pedido* getPedido(int posPArray);
    int getNumPedidos();
    void showPedidos();
    bool eliminarPedido(int indice);  // ← Nuevo método

    // Métodos auxiliares
    void initData();
    void showData();
    void cleanup();
};