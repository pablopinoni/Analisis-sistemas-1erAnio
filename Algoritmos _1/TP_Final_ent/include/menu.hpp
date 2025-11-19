// menu.hpp
#pragma once
#include <string>
#include <limits>
#include "manager.hpp"  // Necesitamos acceder a Manager para operaciones

class Menu {
private:
    Manager* pManager;  // Puntero a manager para coordinación
    
    // Funciones auxiliares
    int leerEntero(const std::string& mensaje);
    std::string leerStringValidado(const std::string& mensaje, const std::string& campo);
    
    // Submenús
    void showDatosMenu();
    void gestionarDatosMenu();
    void gestionarPedidosMenu();  // ← Nueva declaración
    void polimorfismoMenu();

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

    // Métodos auxiliares
    void loadInitialData();          // Carga datos iniciales
};