#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "articulo.h"
#include "cliente.h"
#include "pedido.h"

/*
===========================================================
 CLASE Menu
 ----------------------------------------------------------
 Clase estática que gestiona todo el flujo del sistema de 
 ventas, incluyendo:
   - Carga de artículos, clientes y pedidos.
   - Búsqueda y visualización de información.
   - Liberación de memoria dinámica.

 Usa arrays de punteros a objetos (no STL) para practicar 
 POO con memoria dinámica básica.
===========================================================
*/

class Menu {
private:
    // =====================================================
    // --- Constantes y atributos estáticos ---
    // =====================================================

    static const int MAX_ELEMENTS = 100;  // Límite máximo de elementos por tipo

    // Arrays estáticos que almacenan punteros a objetos
    static Articulo* articulos[MAX_ELEMENTS]; // Lista de artículos
    static int numArticulos;                  // Cantidad actual de artículos cargados

    static Cliente* clientes[MAX_ELEMENTS];   // Lista de clientes
    static int numClientes;                   // Cantidad actual de clientes cargados

    static Pedido* pedidos[MAX_ELEMENTS];     // Lista de pedidos
    static int numPedidos;                    // Cantidad actual de pedidos cargados

    // =====================================================
    // --- Métodos privados: gestión interna del sistema ---
    // =====================================================

    // --- Carga de datos ---
    static void cargarArticulos();   // Carga artículos en memoria
    static void cargarClientes();    // Carga clientes en memoria
    static void cargarPedidos();     // Genera pedidos con artículos y clientes

    // --- Visualización ---
    static void mostrarArticulos();  // Muestra todos los artículos cargados
    static void mostrarClientes();   // Muestra todos los clientes cargados
    static void mostrarPedidos();    // Muestra los pedidos generados

    // --- Funciones auxiliares ---
    static Cliente* buscarCliente(const std::string& code);  // Busca un cliente por código
    static Articulo* buscarArticulo(const std::string& code); // Busca un artículo por código
    static void liberarMemoria(); // Libera todos los objetos creados con new

public:
    // =====================================================
    // --- Métodos públicos: interfaz principal ---
    // =====================================================

    static int showMainMenu();  // Muestra el menú principal y devuelve la opción elegida
    static void ejecutar();     // Controla el flujo principal del programa

    // --- Entrada de datos validada ---
    static std::string readString(const std::string& prompt); // Solicita texto con validación
    static float readFloat(const std::string& prompt);        // Solicita número con validación
};
