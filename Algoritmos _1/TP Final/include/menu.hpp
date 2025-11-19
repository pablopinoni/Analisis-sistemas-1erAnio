// menu.hpp
#pragma once
#include <string>
#include "manager.hpp"  // Necesitamos acceder a Manager para operaciones
#include <limits>
class Menu {
private:
    Manager* pManager;  // Puntero a manager para coordinación

public:
    Menu();
    ~Menu();

    // Métodos principales
    void showMainMenu();              // Muestra menú principal
    void runApp();                   // Punto de entrada principal
    void processOption(int option);   // Procesa opción seleccionada

    // Métodos de creación (para elección en tiempo de ejecución)
    Animal* createAnimal();           // Crea animal según elección del usuario
    Cliente* createCliente();         // Crea cliente
    Pedido* createPedido();           // Crea pedido

    // Métodos de visualización
    void showAnimals();               // Muestra animales usando pManager
    void showClientes();              // Muestra clientes usando pManager
    void showPedidos();               // Muestra pedidos usando pManager

    // Submenús
    void showAnimalMenu();            // Submenú específico para animales
    void showClienteMenu();           // Submenú específico para clientes
    void showPedidoMenu();            // Submenú específico para pedidos
    void menuConsultas();             // Menú de consultas

    // Métodos auxiliares
    void loadInitialData();          // Carga datos iniciales
};