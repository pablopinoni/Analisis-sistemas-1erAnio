// manager.hpp
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
    void ejecutarPolimorfismo();      // Llama comer()/dormir() a todos los animales
    void feedAnimals();               // Llama comer() a todos los animales
    void sleepAnimals();              // Llama dormir() a todos los animales
    void showAnimals();               // Muestra todos los animales

    // Métodos para clientes
    bool agregarCliente(Cliente* cliente);
    Cliente* getCliente(int posPArray);
    int getNumClientes();
    void showClientes();              // Muestra todos los clientes

    // Métodos para pedidos
    bool agregarPedido(Pedido* pedido);
    Pedido* getPedido(int posPArray);
    int getNumPedidos();
    void showPedidos();               // Muestra todos los pedidos

    // Métodos auxiliares
    void initData();                  // Carga datos iniciales (5 animales, 3 clientes, 2 pedidos)
    void showData();                  // Muestra todos los datos
    void cleanup();                   // Limpia memoria (si usas new)
};