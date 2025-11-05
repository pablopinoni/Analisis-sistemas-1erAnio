
#include "../include/application.h"
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

// Constructor
Application::Application() {}

// Bucle principal de la aplicación
void Application::run() {
    int choice;
    do {
        choice = Menu::showMainMenu();
        switch (choice) {
            case 1: handleArticleManagement(); break;
            case 2: handleCustomerManagement(); break;
            case 3: createOrder(); break;
            case 4: manageOrderItems(); break;
            case 5: showAllOrders(); break;
            case 0: 
                cout << "Saliendo de la aplicación. Liberando memoria. ¡Adiós!" << endl; 
                dataStore.cleanup(); // Llamada crítica a la limpieza de memoria
                break;
            default: cout << "Opción no válida. Intente de nuevo." << endl; break;
        }
    } while (choice != 0);
}

// ---------------------- 1. Gestión de Artículos ----------------------

void Application::handleArticleManagement() {
    int choice;
    do {cout << "========================================\n";
        cout << "\n--- GESTIÓN DE ARTÍCULOS ---" << endl;
        cout << "1. Cargar nuevo artículo" << endl;
        cout << "2. Borrar artículo" << endl;
        cout << "3. Actualizar artículo (ej: precio)" << endl;
        cout << "4. Listar todos los artículos" << endl;
        cout << "0. Volver al menú principal" << endl;
        
        choice = Menu::readFloat("Seleccione una opción: ");
        switch (choice) {
            case 1: createArticle(); break;
            case 2: deleteArticle(); break;
            case 3: updateArticle(); break;
            case 4: listArticles(); break;
            case 0: break;
            default: cout << "Opción no válida. Intente de nuevo." << endl; break;
        }
    } while (choice != 0);
}

void Application::createArticle() {
    string code = Menu::readString("Ingrese el código del artículo: ");
    if (dataStore.getArticle(code) != nullptr) {
        cout << "Error: Ya existe un artículo con ese código." << endl;
        return;
    }

    string name = Menu::readString("Ingrese el nombre del artículo: ");
    float price = Menu::readFloat("Ingrese el precio del artículo: ");

    Article* newArticle = new Article(code, name, price);
    if (!dataStore.addArticle(newArticle)) {
        // CRÍTICO: Si no se pudo añadir (ej. array lleno), liberamos la memoria
        delete newArticle; 
        cout << "Error: No se pudo añadir el artículo. Límite alcanzado." << endl;
    } else {
        cout << "Artículo creado y guardado con éxito." << endl;
    }
}

void Application::deleteArticle() {
    string code = Menu::readString("Ingrese el código del artículo a borrar: ");
    dataStore.deleteArticle(code);
}

void Application::updateArticle() {
    string code = Menu::readString("Ingrese el código del artículo a actualizar: ");
    Article* article = dataStore.getArticle(code);
    
    if (article == nullptr) {
        cout << "Error: Artículo no encontrado." << endl;
        return;
    }

    // Nota: Necesitas añadir un setter en Article.hpp/cpp para poder actualizar.
    // Por simplicidad en este nivel, solo mostramos el proceso.
    // float newPrice = Menu::readFloat("Ingrese el nuevo precio para el artículo: ");
    // article->setPrice(newPrice);
    
    cout << "Artículo encontrado. El código del curso no incluye setters para la actualización." << endl;
    cout << "  - Nombre: " << article->getName() << ", Precio actual: $" << article->getPrice() << endl;
}

void Application::listArticles() {
    dataStore.listAllArticles();
}

// ---------------------- 2. Gestión de Clientes ----------------------

void Application::handleCustomerManagement() {
    int choice;
    do {
        cout << "\n--- GESTIÓN DE CLIENTES ---" << endl;
        cout << "1. Cargar nuevo cliente" << endl;
        cout << "2. Borrar cliente" << endl;
        cout << "3. Actualizar cliente (A IMPLEMENTAR)" << endl;
        cout << "4. Listar todos los clientes" << endl;
        cout << "0. Volver al menú principal" << endl;
        
        choice = Menu::readFloat("Seleccione una opción: ");
        switch (choice) {
            case 1: createCustomer(); break;
            case 2: deleteCustomer(); break;
            case 3: updateCustomer(); break;
            case 4: listCustomers(); break;
            case 0: break;
            default: cout << "Opción no válida. Intente de nuevo." << endl; break;
        }
    } while (choice != 0);
}

void Application::createCustomer() {
    string code = Menu::readString("Ingrese el código del cliente: ");
    if (dataStore.getCustomer(code) != nullptr) {
        cout << "Error: Ya existe un cliente con ese código." << endl;
        return;
    }

    string name = Menu::readString("Ingrese el nombre del cliente: ");
    string surname = Menu::readString("Ingrese el apellido del cliente: ");
    string address = Menu::readString("Ingrese la dirección del cliente: ");

    Customer* newCustomer = new Customer(code, name, surname, address);
    if (!dataStore.addCustomer(newCustomer)) {
        delete newCustomer; 
        cout << "Error: No se pudo añadir el cliente. Límite alcanzado." << endl;
    } else {
        cout << "Cliente creado y guardado con éxito." << endl;
    }
}

void Application::deleteCustomer() {
    string code = Menu::readString("Ingrese el código del cliente a borrar: ");
    // En un sistema real, no se puede borrar un cliente con pedidos activos.
    dataStore.deleteCustomer(code);
}

void Application::updateCustomer() {
    cout << "Funcionalidad de Actualizar Cliente no implementada aún." << endl;
}

void Application::listCustomers() {
    dataStore.listAllCustomers();
}

// ---------------------- 3, 4, 5. Gestión de Pedidos ----------------------

void Application::createOrder() {
    string orderCode = Menu::readString("Ingrese el código del nuevo pedido: ");
    if (dataStore.getOrder(orderCode) != nullptr) {
        cout << "Error: Ya existe un pedido con ese código." << endl;
        return;
    }

    string customerCode = Menu::readString("Ingrese el código del cliente para este pedido: ");
    Customer* customer = dataStore.getCustomer(customerCode);
    
    if (customer == nullptr) {
        cout << "Error: Cliente no encontrado. No se puede crear el pedido." << endl;
        return;
    }
    
    Order* newOrder = new Order(orderCode, customer);

    // Agregar artículos al pedido recién creado
    char addMore;
    do {
        string articleCode = Menu::readString("Ingrese el código del artículo a añadir (o 'f' para finalizar): ");
        if (articleCode == "f" || articleCode == "F") break;

        Article* article = dataStore.getArticle(articleCode);
        if (article == nullptr) {
            cout << "Advertencia: Artículo no encontrado. Intente de nuevo." << endl;
        } else {
            newOrder->addArticle(article);
            cout << "Artículo '" << article->getName() << "' añadido al pedido." << endl;
        }
        addMore = Menu::readString("¿Desea añadir otro artículo? (s/n): ")[0];
    } while (addMore == 's' || addMore == 'S');

    if (dataStore.addOrder(newOrder)) {
        cout << "Pedido " << orderCode << " creado y guardado con éxito." << endl;
    } else {
        delete newOrder;
        cout << "Error: No se pudo guardar el pedido. Límite alcanzado." << endl;
    }
}

void Application::manageOrderItems() {
    cout << "Funcionalidad de Desasignar/Gestionar Artículos de Pedidos no implementada aún." << endl;
}

void Application::showAllOrders() {
    dataStore.listAllOrders();
}

void Application::handleOrderManagement() {
    // Este método podría ser usado para borrar pedidos, etc., pero por ahora se redirige desde run().
    // Lo dejamos para cumplir con la declaración en Application.hpp.
    // Las opciones 3, 4, 5 del main menu llaman directamente a las funciones específicas.
}
