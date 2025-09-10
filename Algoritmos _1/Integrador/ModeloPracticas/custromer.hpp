/*Para separar la implementación (.cpp) de la especificación (.hpp),
 primero debemos organizar el código en dos archivos distintos: un archivo de encabezado 
 (.hpp) que contendrá las declaraciones de las funciones, estructuras y constantes, y un archivo de implementación (.cpp) que contendrá las definiciones de las funciones.
Paso 1: Crear el archivo de encabezado (customer.hpp)
*/
 // CUSTOMER_HPP

//Paso 2: Crear el archivo de implementación (customer.cpp)
#include "customer.hpp"

// Funciones auxiliares
void pauseConsole() {
    std::cout << "Presione una tecla para continuar..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void clearConsole() {
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN32) || defined(WIN64)
        system("cls");
    #endif
}

// Función para mostrar el menú
void showMenu() {
    std::cout << "----- MENÚ -----" << std::endl;
    std::cout << "1. Dar de alta un cliente" << std::endl;
    std::cout << "2. Dar de baja un cliente" << std::endl;
    std::cout << "3. Modificar un cliente" << std::endl;
    std::cout << "4. Listar todos los clientes" << std::endl;
    std::cout << "5. Buscar un cliente por código" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Ingrese una opción: ";
}

// Función para dar de alta un cliente
void create(Customer customers[], int& numCustomers) {
    clearConsole();
    if (numCustomers >= MAX_CUSTOMERS) {
        std::cout << "No se pueden agregar más clientes." << std::endl;
        return;
    }

    Customer newCustomer;
    std::ifstream file("customers.csv");
    if (file.is_open()) {
        newCustomer.code = customers[numCustomers-1].code + 1;
    } else {
        newCustomer.code = (numCustomers + 1) + 99;
    }

    std::cout << "Ingrese el nombre del cliente: ";
    std::cin >> newCustomer.name;
    std::cout << "Ingrese el apellido del cliente: ";
    std::cin >> newCustomer.surname;
    std::cout << "Ingrese la dirección del cliente: ";
    std::cin.ignore();
    std::getline(std::cin, newCustomer.address);

    customers[numCustomers] = newCustomer;
    numCustomers++;
    std::cout << "Cliente agregado correctamente." << std::endl;
}

// Resto de las funciones (remove, update, read, find, save, loadCustomersFromFile)...
// [Aquí irían las implementaciones de las funciones restantes]

int main() {
    Customer customers[MAX_CUSTOMERS];
    int numCustomers = loadCustomersFromFile(customers);
    std::cout << numCustomers << std::endl;

    int option;
    do {
        showMenu();
        std::cin >> option;

        switch (option) {
            case 1: create(customers, numCustomers); clearConsole(); break;
            case 2: remove(customers, numCustomers); break;
            case 3: update(customers, numCustomers); break;
            case 4: read(customers, numCustomers); break;
            case 5: find(customers, numCustomers); break;
            case 6: save(customers, numCustomers); std::cout << "Saliendo..." << std::endl; break;
            default: std::cout << "Opción inválida. Intente nuevamente." << std::endl; break;
        }
        std::cout << std::endl;
    } while (option != 6);

    return 0;
}

/*Paso 3: Compilar los archivos separados
Para compilar los archivos separados, puedes usar el siguiente comando en la terminal:
g++ customer.cpp -o customer_program

Este comando compila el archivo customer.cpp que incluye la implementación de las funciones y genera un ejecutable llamado customer_program.
Paso 4: Ejecutar el programa
Después de compilar, puedes ejecutar el programa con:
./customer_program

Explicación

customer.hpp: Este archivo contiene las declaraciones de las estructuras, constantes y funciones. Es el archivo de encabezado que se incluye en el archivo de implementación.
customer.cpp: Este archivo contiene las definiciones de las funciones declaradas en el archivo de encabezado y la función main().
Compilación: El comando g++ customer.cpp -o customer_program compila el archivo de implementación y genera un ejecutable.

Este enfoque separa la interfaz (declaraciones) de la implementación, lo que es una buena práctica en la programación en C++.
CopyCopy HTML*/