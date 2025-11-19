// menu.cpp
#include "menu.hpp"
#include <iostream>
#include <limits>
#include "ternera.hpp"
#include "cordero.hpp"
#include "pollo.hpp"
#include "pinguino.hpp"
#include "niu.hpp"

Menu::Menu() {
    pManager = new Manager();
    
    std::cout << "\n=== Configuración Inicial ===" << std::endl;
    std::cout << "¿Cargar datos iniciales? (s/n): ";
    
    char respuesta;
    std::cin >> respuesta;
    
    if(respuesta == 's' || respuesta == 'S') {
        loadInitialData();
    }
}

Menu::~Menu() {
    delete pManager;
}

// Función auxiliar para leer un número entero con validación
int Menu::leerEntero(const std::string& mensaje) {
    int valor;
    std::cout << mensaje;
    
    while (!(std::cin >> valor)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. " << mensaje;
    }
    return valor;
}

// Función auxiliar para leer un string con validación
std::string Menu::leerStringValidado(const std::string& mensaje, const std::string& campo) {
    std::string valor;
    std::cout << mensaje;
    std::cin >> valor;
    
    while (valor.empty()) {
        std::cout << campo << " no puede estar vacío. " << mensaje;
        std::cin >> valor;
    }
    return valor;
}

void Menu::runApp() {
    int opcion;
    do {
        showMainMenu();
        opcion = leerEntero("Ingrese opción: ");
        processOption(opcion);
    } while (opcion != 0);
}

void Menu::showMainMenu() {
    std::cout << "\n============================" << std::endl;
    std::cout << "\n   === Menú Principal ===" << std::endl;
     std::cout << "\n============================" << std::endl;
    std::cout << "  1. Mostrar Datos" << std::endl;
    std::cout << "  2. Gestionar Datos" << std::endl;
    std::cout << "  3. Polimorfismo" << std::endl;
    std::cout << "  0. Salir" << std::endl;
    std::cout << "==============================\n" << std::endl;
    std::cout << "Ingrese opción: ";
}

void Menu::processOption(int option) {
    switch (option) {
        case 1:
            showDatosMenu();
            break;
        case 2:
            gestionarDatosMenu();
            break;
        case 3:
            polimorfismoMenu();
            break;
        case 0:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
    }
}

void Menu::showDatosMenu() {
    int opcion;
    do {
        std::cout << "\n--- Mostrar Datos ---" << std::endl;
        std::cout << "1. Mostrar Animales" << std::endl;
        std::cout << "2. Mostrar Clientes" << std::endl;
        std::cout << "3. Mostrar Pedidos" << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "Ingrese opción: ";
        
        opcion = leerEntero("");
        
        switch (opcion) {
            case 1:
                pManager->showAnimals();
                break;
            case 2:
                pManager->showClientes();
                break;
            case 3:
                pManager->showPedidos();
                break;
            case 0:
                // Volver al menú principal
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    } while (opcion != 0);
}

void Menu::gestionarDatosMenu() {
    int opcion;
    do {
        std::cout << "\n--- Gestionar Datos ---" << std::endl;
        std::cout << "1. Crear Animal" << std::endl;
        std::cout << "2. Crear Cliente" << std::endl;
        std::cout << "3. Gestionar Pedidos" << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "Ingrese opción: ";
        
        opcion = leerEntero("");
        
        switch (opcion) {
            case 1:
                {
                    Animal* animal = createAnimal();
                    if (animal && pManager->agregarAnimal(animal)) {
                        std::cout << "Animal agregado exitosamente." << std::endl;
                    } else {
                        std::cout << "No se pudo agregar animal." << std::endl;
                    }
                }
                break;
            case 2:
                {
                    Cliente* cliente = createCliente();
                    if (cliente && pManager->agregarCliente(cliente)) {
                        std::cout << "Cliente agregado exitosamente." << std::endl;
                    } else {
                        std::cout << "No se pudo agregar cliente." << std::endl;
                    }
                }
                break;
            case 3:
                gestionarPedidosMenu();
                break;
            case 0:
                // Volver
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    } while (opcion != 0);
}

void Menu::gestionarPedidosMenu() {
    int opcion;
    do {
        std::cout << "\n--- Gestionar Pedidos ---" << std::endl;
        std::cout << "1. Crear Pedido" << std::endl;
        std::cout << "2. Eliminar Pedido" << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "Ingrese opción: ";
        
        opcion = leerEntero("");
        
        switch (opcion) {
            case 1:
                {
                    Pedido* pedido = createPedido();
                    if (pedido && pManager->agregarPedido(pedido)) {
                        std::cout << "Pedido agregado exitosamente." << std::endl;
                    } else {
                        std::cout << "No se pudo agregar pedido." << std::endl;
                    }
                }
                break;
            case 2:
                {
                    if (pManager->getNumPedidos() == 0) {
                        std::cout << "No hay pedidos para eliminar." << std::endl;
                    } else {
                        pManager->showPedidos();  // Mostrar pedidos disponibles
                        int indice = leerEntero("Seleccione pedido a eliminar (0-" + 
                                              std::to_string(pManager->getNumPedidos()-1) + "): ");
                        pManager->eliminarPedido(indice);
                    }
                }
                break;
            case 0:
                // Volver
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    } while (opcion != 0);
}

void Menu::polimorfismoMenu() {
    int opcion;
    do {
        std::cout << "\n--- Polimorfismo ---" << std::endl;
        std::cout << "1. Alimentar a todos los animales" << std::endl;
        std::cout << "2. Hacer dormir a todos los animales" << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "Ingrese opción: ";
        
        opcion = leerEntero("");
        
        switch (opcion) {
            case 1:
                pManager->feedAnimals();
                break;
            case 2:
                pManager->sleepAnimals();
                break;
            case 0:
                // Volver
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    } while (opcion != 0);
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
    
    std::string nombre = leerStringValidado("Ingrese nombre: ", "Nombre");
    std::string corte = leerStringValidado("Ingrese corte: ", "Corte");
    double peso = leerEntero("Ingrese peso: ");
    std::string extra = leerStringValidado("Ingrese raza/tipo/distro: ", "Raza");
    
    switch (tipo) {
        case 1:
            return new Ternera(nombre, corte, peso, extra);
        case 2:
            return new Cordero(nombre, corte, peso, extra);
        case 3:
            return new Pollo(nombre, corte, peso, extra);
        case 4:
            return new Pinguino(nombre, corte, peso, extra);
        case 5:
            return new Niu(nombre, corte, peso, extra);
        default:
            return nullptr;
    }
}

Cliente* Menu::createCliente() {
    std::cout << "\n--- Crear Cliente ---" << std::endl;
    std::string codigo = leerStringValidado("Ingrese código: ", "Código");
    std::string nombre = leerStringValidado("Ingrese nombre: ", "Nombre");
    std::string direccion = leerStringValidado("Ingrese dirección: ", "Dirección");
    std::string telefono = leerStringValidado("Ingrese teléfono: ", "Teléfono");
    
    return new Cliente(codigo, nombre, direccion, telefono);
}

Pedido* Menu::createPedido() {
    std::cout << "\n--- Crear Pedido ---" << std::endl;
    
    std::string codigo = leerStringValidado("Ingrese código del pedido: ", "Código");
    std::string fecha = leerStringValidado("Ingrese fecha (AAAA-MM-DD): ", "Fecha");
    
    // Mostrar clientes existentes para seleccionar
    if (pManager->getNumClientes() == 0) {
        std::cout << "No hay clientes registrados. Cree un cliente primero." << std::endl;
        Cliente* cliente = createCliente();
        if (!cliente) return nullptr;
        
        if (!pManager->agregarCliente(cliente)) {
            std::cout << "No se pudo agregar cliente." << std::endl;
            delete cliente;
            return nullptr;
        }
        
        Pedido* pedido = new Pedido(codigo, cliente, fecha);
        std::cout << "Pedido creado con cliente nuevo." << std::endl;
        return pedido;
    } else {
        std::cout << "\nClientes disponibles:" << std::endl;
        pManager->showClientes();
        
        int clienteIndex = leerEntero("Seleccione cliente por índice (0-" + 
                                    std::to_string(pManager->getNumClientes()-1) + "): ");
        
        if (clienteIndex < 0 || clienteIndex >= pManager->getNumClientes()) {
            std::cout << "Índice de cliente inválido." << std::endl;
            return nullptr;
        }
        
        Cliente* cliente = pManager->getCliente(clienteIndex);
        if (!cliente) {
            std::cout << "Cliente no encontrado." << std::endl;
            return nullptr;
        }
        
        // Crear pedido con cliente seleccionado
        Pedido* pedido = new Pedido(codigo, cliente, fecha);
        
        // Permitir añadir animales al pedido
        std::cout << "\nAnimales disponibles:" << std::endl;
        pManager->showAnimals();
        
        char continuar = 's';
        while (continuar == 's' || continuar == 'S') {
            if (pManager->getNumAnimales() == 0) {
                std::cout << "No hay animales disponibles." << std::endl;
                break;
            }
            
            int animalIndex = leerEntero("Seleccione animal por índice: ");
            if (animalIndex < 0 || animalIndex >= pManager->getNumAnimales()) {
                std::cout << "Índice de animal inválido." << std::endl;
                continue;
            }
            
            int cantidad = leerEntero("Ingrese cantidad: ");
            if (cantidad <= 0) {
                std::cout << "Cantidad inválida." << std::endl;
                continue;
            }
            
            Animal* animal = pManager->getAnimal(animalIndex);
            pedido->agregarAnimal(animal, cantidad);
            
            std::cout << "¿Agregar otro animal? (s/n): ";
            std::cin >> continuar;
        }
        
        std::cout << "Pedido creado con " << pedido->getCantidadAnimales() << " animales." << std::endl;
        return pedido;
    }
    
    return nullptr;
}

// Métodos auxiliares
void Menu::loadInitialData() {
    std::cout << "Cargando datos iniciales..." << std::endl;
    
    pManager->agregarAnimal(new Ternera("Ternera1", "Bife", 2.5, "Angus"));
    pManager->agregarAnimal(new Cordero("Cordero1", "Chuleta", 1.2, "Lechal"));
    pManager->agregarAnimal(new Pollo("Pollo1", "Pechuga", 0.8, "Broiler"));
    pManager->agregarAnimal(new Pinguino("Tux1", "Filete", 1.0, "Tuquito"));
    pManager->agregarAnimal(new Niu("GNU1", "Asado", 3.0, "HURD"));
    
    pManager->agregarCliente(new Cliente("C001", "Juan Pérez", "Calle 123", "123456789"));
    pManager->agregarCliente(new Cliente("C002", "María López", "Avenida 456", "987654321"));
    pManager->agregarCliente(new Cliente("C003", "Carlos García", "Boulevard 789", "456789123"));
    
    std::cout << "Datos iniciales cargados." << std::endl;
}