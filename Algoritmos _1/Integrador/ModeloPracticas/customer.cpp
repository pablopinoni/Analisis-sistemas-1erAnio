#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Estructura que representa un cliente
struct Customer {
    int code;
    std::string name;
    std::string surname;
    std::string address;
};

// Constante global: máximo de clientes permitidos
const int MAX_CUSTOMERS = 100;

// Funciones auxiliares
void pauseConsole();
void clearConsole();

// Funciones del menú
void showMenu();
void create(Customer customers[], int& numCustomers);
void remove(Customer customers[], int& numCustomers);
void update(Customer customers[], int numCustomers);
void read(Customer customers[], int numCustomers);
void find(Customer customers[], int numCustomers);
void save(Customer customers[], int numCustomers);
int loadCustomersFromFile(Customer customers[]);

#endif