#pragma once

#include <iostream>
#include <memory>
#include "dataStore.h"
#include "menu.h"

using namespace std;

class Application
{
    public:
        Application();
        void run();

    private:
        DataStore dataStore;
        
        // Implementaciones de las funcionalidades
        void handleArticleManagement();
        void handleCustomerManagement();
        void handleOrderManagement();

        // Lógica interna para Artículos
        void createArticle();
        void deleteArticle();
        void updateArticle();
        void listArticles();

        // Lógica interna para Clientes
        void createCustomer();
        void deleteCustomer();
        void updateCustomer();
        void listCustomers();

        // Lógica interna para Pedidos
        void createOrder();
        void manageOrderItems(); 
        void showAllOrders();
};