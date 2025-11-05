#include "dataStore.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

// Constructor inicializa contadores y punteros
DataStore::DataStore() : numArticles(0), numCustomers(0), numOrders(0) {
    // Inicializar los arrays de punteros
    std::fill(this->articles, this->articles + Constants::MAX_ARTICLES, nullptr);
    std::fill(this->customers, this->customers + Constants::MAX_CUSTOMERS, nullptr);
    std::fill(this->orders, this->orders + Constants::MAX_ITEMS, nullptr);
}
    
// Destructor (se mantiene como estaba, el llamado se hace en main)
DataStore::~DataStore() {
    this->cleanup(); 
}

// Función auxiliar de búsqueda lineal (ineficiente, pero simple para primer año)
int findArticleIndex(Article* arr[], int count, const std::string& code) {
    for (int i = 0; i < count; ++i) {
        if (arr[i] != nullptr && arr[i]->getCode() == code) {
            return i;
        }
    }
    return -1;
}

// ---------------------- Métodos para Artículos ----------------------

bool DataStore::addArticle(Article* article) {
    if (this->numArticles >= Constants::MAX_ARTICLES) {
        std::cout << "Error: Límite de artículos alcanzado." << std::endl;
        return false;
    }
    // CORRECCIÓN 2: Usar article->getCode() para verificar si ya existe
    if (getArticle(article->getCode()) != nullptr) {
        std::cout << "Error: Artículo con código " << article->getCode() << " ya existe." << std::endl;
        return false;
    }
    this->articles[this->numArticles++] = article;
    return true;
}

Article* DataStore::getArticle(const std::string& code) const {
    for (int i = 0; i < this->numArticles; ++i) { // Usar this->numArticles es más explícito
        if (this->articles[i] != nullptr && this->articles[i]->getCode() == code) {
            return this->articles[i]; // CORRECCIÓN 1: Eliminar 'flis' y usar this->
        }
    }
    return nullptr;
}

bool DataStore::deleteArticle(const std::string& code) {
    // CORRECCIÓN 3: Calificar los miembros de la clase
    int index = findArticleIndex(this->articles, this->numArticles, code); 
    if (index == -1) {
        std::cout << "Error: Artículo con código " << code << " no encontrado." << std::endl;
        return false;
    }
    
    delete this->articles[index]; // CORRECCIÓN 3: Calificar
    
    // Mover los elementos para llenar el hueco
    for (int i = index; i < this->numArticles - 1; ++i) { // CORRECCIÓN 3: Calificar numArticles
        this->articles[i] = this->articles[i + 1]; // CORRECCIÓN 3: Calificar articles
    }
    this->articles[--this->numArticles] = nullptr; // Reducir contador y poner el último a nullptr
    std::cout << "Artículo " << code << " eliminado y memoria liberada." << std::endl;
    return true;
}

void DataStore::listAllArticles() const {
    if (this->numArticles == 0) { // CORRECCIÓN 3: Calificar numArticles
        std::cout << "No hay artículos cargados." << std::endl;
        return;
    }
    std::cout << "\n--- LISTADO DE ARTÍCULOS (" << this->numArticles << " Total) ---" << std::endl;
    for (int i = 0; i < this->numArticles; ++i) { // CORRECCIÓN 3: Calificar numArticles
        std::cout << this->articles[i]->getCode() << ": " << this->articles[i]->getName() // Calificar ambos
                  << " ($" << this->articles[i]->getPrice() << ")" << std::endl; // Calificar ambos
    }
}

// ---------------------- Métodos de Limpieza Final ----------------------

void DataStore::cleanup() {
    std::cout << "\n--- Limpiando Memoria ---" << std::endl;
    // La limpieza ya estaba bien, usando this->
    for (int i = 0; i < this->numOrders; ++i) {
        std::cout << "Destruyendo Pedido: " << this->orders[i]->getCode() << std::endl;
        delete this->orders[i];
        this->orders[i] = nullptr;
    }
    
    for (int i = 0; i < this->numArticles; ++i) { // Calificar numArticles
        if (this->articles[i] != nullptr) {
            std::cout << "Destruyendo Artículo: " << this->articles[i]->getCode() << std::endl;
            delete this-> articles[i];
           this->articles[i] = nullptr;
        }
    }
    for (int i = 0; i < this->numCustomers; ++i) { // Calificar numCustomers
        if (this->customers[i] != nullptr) {
            std::cout << "Destruyendo Cliente: " << this->customers[i]->getCode() << std::endl;
            delete this->customers[i];
            this->customers[i] = nullptr;
        }
    }
    this->numArticles = 0;
    this->numCustomers = 0;
    this->numOrders = 0;
    std::cout << "Memoria liberada completamente." << std::endl;
}

// Función auxiliar para búsqueda de Customer (similar a findArticleIndex)
int findCustomerIndex(Customer* arr[], int count, const std::string& code) {
    for (int i = 0; i < count; ++i) {
        if (arr[i] != nullptr && arr[i]->getCode() == code) {
            return i;
        }
    }
    return -1;
}

// ---------------------- Métodos para Clientes ----------------------

bool DataStore::addCustomer(Customer* customer) {
    // Los usos de this-> y Constants:: ya estaban bien aquí.
    if (this->numCustomers >= Constants::MAX_CUSTOMERS) {
        std::cout << "Error: Límite de clientes alcanzado." << std::endl;
        return false;
    }
    if (getCustomer(customer->getCode()) != nullptr) {
        std::cout << "Error: Cliente con código " << customer->getCode() << " ya existe." << std::endl;
        return false;
    }
    this->customers[this->numCustomers++] = customer;
    return true;
}

Customer* DataStore::getCustomer(const std::string& code) const {
    for (int i = 0; i < this->numCustomers; ++i) { // Calificar numCustomers
        if (this->customers[i] != nullptr && this->customers[i]->getCode() == code) { // CORRECCIÓN 3: Calificar
            return this->customers[i]; // CORRECCIÓN 3: Calificar
        }
    }
    return nullptr;
}

bool DataStore::deleteCustomer(const std::string& code) {
    // CORRECCIÓN 3: Calificar los miembros de la clase
    int index = findCustomerIndex(this->customers, this->numCustomers, code); 
    if (index == -1) {
        std::cout << "Error: Cliente con código " << code << " no encontrado." << std::endl;
        return false;
    }
    
    delete this->customers[index]; // CORRECCIÓN 3: Calificar
    
    // Mover los elementos para llenar el hueco
    for (int i = index; i < this->numCustomers - 1; ++i) { // CORRECCIÓN 3: Calificar numCustomers
        this->customers[i] = this->customers[i + 1]; // CORRECCIÓN 3: Calificar customers
    }
    this->customers[--this->numCustomers] = nullptr; // Reducir contador y poner el último a nullptr
    std::cout << "Cliente " << code << " eliminado y memoria liberada." << std::endl;
    return true;
}

void DataStore::listAllCustomers() const {
    if (this->numCustomers == 0) { // Calificar numCustomers
        std::cout << "No hay clientes cargados." << std::endl;
        return;
    }
    std::cout << "\n--- LISTADO DE CLIENTES (" << this->numCustomers << " Total) ---" << std::endl;
    for (int i = 0; i < this->numCustomers; ++i) { // Calificar numCustomers
        std::cout << this->customers[i]->getCode() << ": " << this->customers[i]->getName() << " " // Calificar
                  << this->customers[i]->getSurname() << ", Dirección: " << this->customers[i]->getAddress() << std::endl; // Calificar
    }
}

// Función auxiliar para búsqueda de Order
int findOrderIndex(Order* arr[], int count, const std::string& code) {
    for (int i = 0; i < count; ++i) {
        if (arr[i] != nullptr && arr[i]->getCode() == code) {
            return i;
        }
    }
    return -1;
}

// ---------------------- Métodos para Pedidos ----------------------

bool DataStore::addOrder(Order* order) {
    // Ya estaba correcto
    if (this->numOrders >= Constants::MAX_ITEMS) { 
        std::cout << "Error: Límite de pedidos alcanzado." << std::endl;
        return false;
    }
    if (getOrder(order->getCode()) != nullptr) {
        std::cout << "Error: Pedido con código " << order->getCode() << " ya existe." << std::endl;
        return false;
    }
    this->orders[this->numOrders++] = order;
    return true;
}

Order* DataStore::getOrder(const std::string& code) const {
    for (int i = 0; i < this->numOrders; ++i) { // Calificar numOrders
        if (this->orders[i]->getCode() == code) { // Calificar orders
            return this->orders[i]; // Calificar orders
        }
    }
    return nullptr;
}

bool DataStore::deleteOrder(const std::string& code) {
    // CORRECCIÓN 3: Calificar los miembros de la clase
    int index = findOrderIndex(this->orders, this->numOrders, code);
    if (index == -1) {
        std::cout << "Error: Pedido con código " << code << " no encontrado." << std::endl;
        return false;
    }
    
    delete this->orders[index]; // CORRECCIÓN 3: Calificar
    
    // Mover los elementos para llenar el hueco
    for (int i = index; i < this->numOrders - 1; ++i) { // CORRECCIÓN 3: Calificar numOrders
        this->orders[i] = this->orders[i + 1]; // CORRECCIÓN 3: Calificar orders
    }
    this->orders[--this->numOrders] = nullptr; // CORRECCIÓN 3: Calificar
    std::cout << "Pedido " << code << " eliminado y memoria liberada." << std::endl;
    return true;
}

void DataStore::listAllOrders() const {
    if (this->numOrders == 0) { // Calificar numOrders
        std::cout << "No hay pedidos cargados." << std::endl;
        return;
    }
    std::cout << "\n--- LISTADO DE PEDIDOS (" << this->numOrders << " Total) ---" << std::endl;
    for (int i = 0; i < this->numOrders; ++i) { // Calificar numOrders
        this->orders[i]->show(); // Calificar orders
    }
}