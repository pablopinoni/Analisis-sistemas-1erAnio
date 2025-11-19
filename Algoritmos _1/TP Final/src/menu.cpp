// menu.cpp
#include "menu.hpp"        // Esta incluye manager.hpp automáticamente
#include <iostream>
#include <limits>          
#include "ternera.hpp"     // ← Necesario para new Ternera()
#include "cordero.hpp"     // ← Necesario para new Cordero()
#include "pollo.hpp"       // ← Necesario para new Pollo()
#include "pinguino.hpp"    // ← Necesario para new Pinguino()
#include "niu.hpp"         // ← Necesario para new Niu()

// Constructor
Menu::Menu() {
    pManager = new Manager();  // Crea instancia de Manager
    std::cout << "\n=== Configuración Inicial ===" << std::endl;
    std::cout << "¿Cargar datos iniciales? (s/n): ";
    
    char respuesta;
    std::cin >> respuesta;
    
    if(respuesta == 's' || respuesta == 'S' || respuesta == 'Y' || respuesta == 'y') {
        loadInitialData();
    } else if (respuesta == 'n' || respuesta == 'N') {
        std::cout << "Omitiendo carga de datos iniciales." << std::endl;
    } else {
        std::cout << "Opción no válida. Omitiendo carga de datos iniciales." << std::endl;
    }
}

// Destructor
Menu::~Menu() {
    delete pManager;  // Libera memoria del Manager
    pManager = nullptr;
}

// Función auxiliar para leer un número entero con validación
int leerEntero(const std::string& mensaje) {
    int valor;
    std::cout << mensaje;
    
    while (!(std::cin >> valor)) {
        std::cin.clear(); // Limpia el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia buffer
        std::cout << "Entrada inválida. " << mensaje;
    }
    return valor;
}

// Función auxiliar para leer un string
std::string leerString(const std::string& mensaje) {
    std::string valor;
    std::cout << mensaje;
    std::cin >> valor;
    return valor;
}

// Métodos principales
void Menu::showMainMenu() {
    std::cout << "\n============================" << std::endl;
    std::cout << "\n=== Menú Principal ===" << std::endl;
    std::cout << "1. Crear Animal" << std::endl;
    std::cout << "2. Crear Cliente" << std::endl;
    std::cout << "3. Crear Pedido" << std::endl;
    std::cout << "4. Mostrar Animales" << std::endl;
    std::cout << "5. Mostrar Clientes" << std::endl;
    std::cout << "6. Mostrar Pedidos" << std::endl;
    std::cout << "7. Submenú Animales" << std::endl;
    std::cout << "8. Submenú Clientes" << std::endl;
    std::cout << "9. Submenú Pedidos" << std::endl;
    std::cout << "10. Menú Consultas" << std::endl;
    std::cout << "11. Polimorfismo (Ejecutar)" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese opción: ";
}

void Menu::runApp() {
    int opcion;
    do {
        try {
            showMainMenu();
            opcion = leerEntero("Ingrese opción: ");
            processOption(opcion);
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (opcion != 0);
}

void Menu::processOption(int option) {
    switch (option) {
        case 1:
            {
                Animal* animal = createAnimal();
                if (animal != nullptr) {
                    if (!pManager->agregarAnimal(animal)) {
                        std::cout << "No se pudo agregar animal: array lleno." << std::endl;
                        delete animal; // Libera memoria si no se agregó
                    } else {
                        std::cout << "Animal agregado exitosamente." << std::endl;
                    }
                } else {
                    std::cout << "No se creó el animal." << std::endl;
                }
            }
            break;
        case 2:
            {
                Cliente* cliente = createCliente();
                if (cliente != nullptr) {
                    if (!pManager->agregarCliente(cliente)) {
                        std::cout << "No se pudo agregar cliente: array lleno." << std::endl;
                        delete cliente; // Libera memoria si no se agregó
                    } else {
                        std::cout << "Cliente agregado exitosamente." << std::endl;
                    }
                } else {
                    std::cout << "No se creó el cliente." << std::endl;
                }
            }
            break;
        case 3:
            {
                Pedido* pedido = createPedido();
                if (pedido != nullptr) {
                    if (!pManager->agregarPedido(pedido)) {
                        std::cout << "No se pudo agregar pedido: array lleno." << std::endl;
                        delete pedido; // Libera memoria si no se agregó
                    } else {
                        std::cout << "Pedido agregado exitosamente." << std::endl;
                    }
                } else {
                    std::cout << "No se creó el pedido." << std::endl;
                }
            }
            break;
        case 4:
            showAnimals();
            break;
        case 5:
            showClientes();
            break;
        case 6:
            showPedidos();
            break;
        case 7:
            showAnimalMenu();
            break;
        case 8:
            showClienteMenu();
            break;
        case 9:
            showPedidoMenu();
            break;
        case 10:
            menuConsultas();
            break;
        case 11:
            pManager->ejecutarPolimorfismo();
            break;
        case 0:
            std::cout << "Saliendo del sistema..." << std::endl;
            break;
        default:
            std::cout << "Opción no válida. Ingrese un número entre 0 y 11." << std::endl;
            break;
    }
}

// Métodos de creación
Animal* Menu::createAnimal() {
    std::cout << "\n--- Crear Animal ---" << std::endl;
    std::cout << "Tipos de animales:" << std::endl;
    std::cout << "1. Ternera" << std::endl;
    std::cout << "2. Cordero" << std::endl;
    std::cout << "3. Pollo" << std::endl;
    std::cout << "4. Pinguino" << std::endl;
    std::cout << "5. Ñu" << std::endl;
    
    int tipo = leerEntero("Seleccione tipo (1-5): ");
    
    if (tipo < 1 || tipo > 5) {
        std::cout << "Tipo de animal no válido." << std::endl;
        return nullptr;
    }
    
    std::string nombre = leerString("Ingrese nombre: ");
    std::string corte = leerString("Ingrese corte: ");
    double peso = leerEntero("Ingrese peso: ");
    std::string extra;
    
    switch (tipo) {
        case 1:  // Ternera
            extra = leerString("Ingrese raza: ");
            return new Ternera(nombre, corte, peso, extra);
            
        case 2:  // Cordero
            extra = leerString("Ingrese tipo: ");
            return new Cordero(nombre, corte, peso, extra);
            
        case 3:  // Pollo
            extra = leerString("Ingrese tipo de pollo: ");
            return new Pollo(nombre, corte, peso, extra);
            
        case 4:  // Pinguino
            extra = leerString("Ingrese distro: ");
            return new Pinguino(nombre, corte, peso, extra);
            
        case 5:  // Niu(Ñu)
            extra = leerString("Ingrese tipo de ñu: ");
            return new Niu(nombre, corte, peso, extra);
            
        default:
            return nullptr; // Nunca debería llegar aquí
    }
}

Cliente* Menu::createCliente() {
    std::cout << "\n--- Crear Cliente ---" << std::endl;
    
    std::string codigo;
    std::cout << "Ingrese código: ";
    std::cin >> codigo;
    if (codigo.empty()) {
        std::cout << "Código no válido." << std::endl;
        return nullptr;
    }
    
    std::string nombre;
    std::cout << "Ingrese nombre: ";
    std::cin >> nombre;
    if (nombre.empty()) {
        std::cout << "Nombre no válido." << std::endl;
        return nullptr;
    }
    
    std::string direccion;
    std::cout << "Ingrese dirección: ";
    std::cin >> direccion;
    if (direccion.empty()) {
        std::cout << "Dirección no válida." << std::endl;
        return nullptr;
    }
    
    std::string telefono;
    std::cout << "Ingrese teléfono: ";
    std::cin >> telefono;
    if (telefono.empty()) {
        std::cout << "Teléfono no válido." << std::endl;
        return nullptr;
    }
    
    return new Cliente(codigo, nombre, direccion, telefono);
}

Pedido* Menu::createPedido() {
    std::cout << "\n--- Crear Pedido ---" << std::endl;
    
    std::string codigo;
    std::cout << "Ingrese código del pedido: ";
    std::cin >> codigo;
    
    // Validar que el código no esté vacío
    if (codigo.empty()) {
        std::cout << "Código no válido." << std::endl;
        return nullptr;
    }
    
    std::string fecha;
    std::cout << "Ingrese fecha (AAAA-MM-DD): ";
    std::cin >> fecha;
    
    // Validar que la fecha no esté vacía
    if (fecha.empty()) {
        std::cout << "Fecha no válida." << std::endl;
        return nullptr;
    }
    
    // Aquí deberías seleccionar un cliente existente
    Cliente* cliente = createCliente();  // O seleccionar uno existente
    if (cliente != nullptr) {
        try {
            Pedido* pedido = new Pedido(codigo, cliente, fecha);
            return pedido;
        } catch (const std::exception& e) {
            std::cout << "Error al crear pedido: " << e.what() << std::endl;
            delete cliente; // Libera cliente si no se creó pedido
            return nullptr;
        }
    }
    return nullptr;
}

// Métodos de visualización
void Menu::showAnimals() {
    pManager->showAnimals();
}

void Menu::showClientes() {
    pManager->showClientes();
}

void Menu::showPedidos() {
    pManager->showPedidos();
}

// Submenús
void Menu::showAnimalMenu() {
    std::cout << "\n--- Submenú Animales ---" << std::endl;
    std::cout << "1. Alimentar a todos los animales" << std::endl;
    std::cout << "2. Hacer dormir a todos los animales" << std::endl;
    std::cout << "3. Volver al menú principal" << std::endl;
    
    int opcion = leerEntero("Seleccione opción: ");
    
    switch (opcion) {
        case 1:
            pManager->feedAnimals();
            break;
        case 2:
            pManager->sleepAnimals();
            break;
        case 3:
            // Volver al menú principal
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
    }
}

void Menu::showClienteMenu() {
    std::cout << "\n--- Submenú Clientes ---" << std::endl;
    std::cout << "Opciones para clientes..." << std::endl;
    // Implementar según necesidades
}

void Menu::showPedidoMenu() {
    std::cout << "\n--- Submenú Pedidos ---" << std::endl;
    std::cout << "Opciones para pedidos..." << std::endl;
    // Implementar según necesidades
}

void Menu::menuConsultas() {
    std::cout << "\n--- Menú Consultas ---" << std::endl;
    std::cout << "1. Mostrar todos los datos" << std::endl;
    std::cout << "2. Volver al menú principal" << std::endl;
    
    int opcion = leerEntero("Seleccione opción: ");
    
    switch (opcion) {
        case 1:
            pManager->showData();
            break;
        case 2:
            // Volver al menú principal
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
    }
}

// Métodos auxiliares
void Menu::loadInitialData() {
    // Carga los 5 animales, 3 clientes y 2 pedidos como pide el enunciado
    std::cout << "Cargando datos iniciales..." << std::endl;
    
    // Ejemplo de creación de animales
    pManager->agregarAnimal(new Ternera("Ternera1", "Bife", 2.5, "Angus"));
    pManager->agregarAnimal(new Cordero("Cordero1", "Chuleta", 1.2, "Lechal"));
    pManager->agregarAnimal(new Pollo("Pollo1", "Pechuga", 0.8, "Broiler"));
    pManager->agregarAnimal(new Pinguino("Tux1", "Filete", 1.0, "Tuquito"));
    pManager->agregarAnimal(new Niu("GNU1", "Asado", 3.0, "HURD"));
    
    // Ejemplo de creación de clientes
    pManager->agregarCliente(new Cliente("C001", "Juan Pérez", "Calle 123", "123456789"));
    pManager->agregarCliente(new Cliente("C002", "María López", "Avenida 456", "987654321"));
    pManager->agregarCliente(new Cliente("C003", "Carlos García", "Boulevard 789", "456789123"));
    
    std::cout << "Datos iniciales cargados." << std::endl;
}