// manager.cpp
#include "manager.hpp"
#include <iostream>

// Constructor
Manager::Manager() : numAnimales(0), numClientes(0), numPedidos(0) {
    // Inicializa arrays a nullptr
    for (int i = 0; i < Constants::MAX_ANIMALES; ++i) {
        pAnimales[i] = nullptr;
    }
    for (int i = 0; i < Constants::MAX_CLIENTES; ++i) {
        pClientes[i] = nullptr;
    }
    for (int i = 0; i < Constants::MAX_PEDIDOS; ++i) {
        pPedidos[i] = nullptr;
    }
}

// Destructor
Manager::~Manager() {
    cleanup();  // Limpia la memoria asignada
}

// Métodos para animales
bool Manager::agregarAnimal(Animal* animal) {
    if (numAnimales < Constants::MAX_ANIMALES && animal != nullptr) {
        pAnimales[numAnimales] = animal;
        numAnimales++;
        return true;
    }
    return false;  // No se pudo agregar
}

Animal* Manager::getAnimal(int posPArray) {
    if (posPArray >= 0 && posPArray < numAnimales) {
        return pAnimales[posPArray];
    }
    return nullptr;  // Índice fuera de rango
}

int Manager::getNumAnimales() {
    return numAnimales;
}

void Manager::ejecutarPolimorfismo() {
    std::cout << "\n--- Ejecutando Polimorfismo ---" << std::endl;
    for (int i = 0; i < numAnimales; ++i) {
        if (pAnimales[i] != nullptr) {
            std::cout << "Animal: " << pAnimales[i]->getNombre() << std::endl;
            pAnimales[i]->comer();   // Llama al método específico de cada clase derivada
            pAnimales[i]->dormir();  // Llama al método específico de cada clase derivada
            std::cout << "-------------------" << std::endl;
        }
    }
}

void Manager::feedAnimals() {
    std::cout << "\n--- Alimentando Animales ---" << std::endl;
    for (int i = 0; i < numAnimales; ++i) {
        if (pAnimales[i] != nullptr) {
            pAnimales[i]->comer();  // Llama al comer() específico de cada animal
        }
    }
}

void Manager::sleepAnimals() {
    std::cout << "\n--- Haciendo Dormir Animales ---" << std::endl;
    for (int i = 0; i < numAnimales; ++i) {
        if (pAnimales[i] != nullptr) {
            pAnimales[i]->dormir();  // Llama al dormir() específico de cada animal
        }
    }
}

void Manager::showAnimals() {
    std::cout << "\n--- Lista de Animales ---" << std::endl;
    for (int i = 0; i < numAnimales; ++i) {
        if (pAnimales[i] != nullptr) {
            std::cout << "Animal " << i << ": " << pAnimales[i]->getNombre() 
                      << " (" << pAnimales[i]->getCorte() << "), Peso: " 
                      << pAnimales[i]->getPeso() << " kg" << std::endl;
        }
    }
}

// Métodos para clientes
bool Manager::agregarCliente(Cliente* cliente) {
    if (numClientes < Constants::MAX_CLIENTES && cliente != nullptr) {
        pClientes[numClientes] = cliente;
        numClientes++;
        return true;
    }
    return false;  // No se pudo agregar
}

Cliente* Manager::getCliente(int posPArray) {
    if (posPArray >= 0 && posPArray < numClientes) {
        return pClientes[posPArray];
    }
    return nullptr;  // Índice fuera de rango
}

int Manager::getNumClientes() {
    return numClientes;
}

void Manager::showClientes() {
    std::cout << "\n--- Lista de Clientes ---" << std::endl;
    for (int i = 0; i < numClientes; ++i) {
        if (pClientes[i] != nullptr) {
            std::cout << "Cliente " << i << ": " << pClientes[i]->getName() 
                      << " (Código: " << pClientes[i]->getCode() << ")" << std::endl;
        }
    }
}

// Métodos para pedidos
bool Manager::agregarPedido(Pedido* pedido) {
    if (numPedidos < Constants::MAX_PEDIDOS && pedido != nullptr) {
        pPedidos[numPedidos] = pedido;
        numPedidos++;
        return true;
    }
    return false;  // No se pudo agregar
}

Pedido* Manager::getPedido(int posPArray) {
    if (posPArray >= 0 && posPArray < numPedidos) {
        return pPedidos[posPArray];
    }
    return nullptr;  // Índice fuera de rango
}

int Manager::getNumPedidos() {
    return numPedidos;
}

void Manager::showPedidos() {
    std::cout << "\n--- Lista de Pedidos ---\t" << std::endl;
    for (int i = 0; i < numPedidos; ++i) {
        if (pPedidos[i] != nullptr) {
            std::cout << "Pedido " << i << ": " << pPedidos[i]->getCode() 
                      << " - Cliente: " << pPedidos[i]->getCustomer()->getName()
                      << " - Fecha: " << pPedidos[i]->getDate()
                      << " - Monto: $" << pPedidos[i]->getMonto() << std::endl;
            
            // Mostrar animales del pedido
            int numAnimalesPedido = pPedidos[i]->getNumAnimales();
            if (numAnimalesPedido > 0) {
                std::cout << "  Animales incluidos:" << std::endl;
                for (int j = 0; j < numAnimalesPedido; ++j) {
                    Animal* animal = pPedidos[i]->getAnimal(j);
                    int cantidad = pPedidos[i]->getCantidadXAnimal(j);
                    if (animal) {
                        std::cout << "    - " << animal->getNombre() 
                                  << " (" << animal->getCorte() << "), Peso: " 
                                  << animal->getPeso() << "kg, Cantidad: " 
                                  << cantidad << std::endl;
                    }
                }
            } else {
                std::cout << "  No hay animales en este pedido." << std::endl;
            }
            std::cout << "  -----------------------------------------" << std::endl;
        }
    }
}
// En manager.cpp, después de showPedidos():
bool Manager::eliminarPedido(int indice) {
    if (indice < 0 || indice >= numPedidos) {
        std::cout << "Índice de pedido inválido." << std::endl;
        return false;
    }
    
    // Eliminar el pedido (no lo eliminamos con delete porque no lo creamos aquí)
    // Solo movemos los elementos siguientes una posición hacia atrás
    for (int i = indice; i < numPedidos - 1; ++i) {
        pPedidos[i] = pPedidos[i + 1];
    }
    
    pPedidos[numPedidos - 1] = nullptr;  // Limpia la última posición
    numPedidos--;
    
    std::cout << "Pedido eliminado exitosamente." << std::endl;
    return true;
}
// Métodos auxiliares
void Manager::initData() {
    // Aquí se cargarían los 5 animales, 3 clientes y 2 pedidos
    // como pide el enunciado
    std::cout << "Cargando datos iniciales..." << std::endl;
    // En una implementación completa, aquí se crearían objetos
    // y se agregarían a los arrays
}

void Manager::showData() {
    showAnimals();
    showClientes();
    showPedidos();
}

void Manager::cleanup() {
    // Nota: No eliminamos los objetos aquí porque no los creamos con new en esta clase
    // La creación y destrucción de objetos debería manejarse en otra parte del sistema
    // (por ejemplo, en main() o en Menu)
    
    // Limpiar arrays
    for (int i = 0; i < numAnimales; ++i) {
        pAnimales[i] = nullptr;
    }
    for (int i = 0; i < numClientes; ++i) {
        pClientes[i] = nullptr;
    }
    for (int i = 0; i < numPedidos; ++i) {
        pPedidos[i] = nullptr;
    }
    
    numAnimales = 0;
    numClientes = 0;
    numPedidos = 0;
}