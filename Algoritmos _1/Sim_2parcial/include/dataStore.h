#pragma once

#include <string>
#include "articulos.h"
#include "clientes.h"
#include "pedidos.h"
#include "constants.h"

class DataStore
{
    public:
        DataStore();
        ~DataStore();

        // Arreglos de punteros raw y contadores
        Article* articles[Constants::MAX_ARTICLES];
        Customer* customers[Constants::MAX_CUSTOMERS];
        Order* orders[Constants::MAX_ITEMS]; // MAX_ITEMS se usa aquí como límite de pedidos
        
        int numArticles;
        int numCustomers;
        int numOrders;

        // Métodos CRUD básicos

        // Artículos
        bool addArticle(Article* article);
        Article* getArticle(const std::string& code) const;
        bool deleteArticle(const std::string& code);
        void listAllArticles() const;

        // Clientes
        bool addCustomer(Customer* customer);
        Customer* getCustomer(const std::string& code) const;
        bool deleteCustomer(const std::string& code);
        void listAllCustomers() const;

         // Pedidos
        bool addOrder(Order* order);
        Order* getOrder(const std::string& code) const;
        bool deleteOrder(const std::string& code);
        void listAllOrders() const;
        
        // Método para limpiar todos los punteros al final
        void cleanup();

    private:
        // Evitamos copias
        DataStore(const DataStore&) = delete;
        DataStore& operator=(const DataStore&) = delete;
};