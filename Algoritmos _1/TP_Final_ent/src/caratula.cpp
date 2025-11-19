// caratula.cpp
#include "caratula.hpp"
#include <iostream>
#include <thread>
#include <chrono>

Caratula::Caratula() 
    : titulo("Sistema de Gestión - Boutique de Carnes"),
      autor("Pablo Pinoni"),
      materia("Algoritmos y Estructura de Datos I"),
      carrera("Analista de Sistemas"),
      instituto("ISFT N151") {
}

Caratula::~Caratula() {
}

void Caratula::clearConsole() {
    // Limpia la consola (funciona en Linux/Mac)
    std::cout << "\033[2J\033[1;1H";
}

void Caratula::showPolloUkelele(bool encendido) {
    if (encendido) {
        std::cout << "\033[1;33m"; // texto amarillo brillante
        std::cout << "\033[40m";   // fondo negro
    } else {
        std::cout << "\033[30m";   // texto negro (apaga texto)
        std::cout << "\033[40m";   // fondo negro
    }
std::cout << "\n";
std::cout << "  ##################################################################\n";
std::cout << "  #                                                                #\n";
std::cout << "  #          ╔══════════════════════════════════════════╗          #\n";
std::cout << "  #          ║           BOUTIQUE DE CARNES             ║          #\n";
std::cout << "  #          ║            UKELELE CHICKEN               ║          #\n";
std::cout << "  #          ╚══════════════════════════════════════════╝          #\n";
std::cout << "  #                                                                #\n";
std::cout << "  #  ██████████████████████████████████████████████████████████    #" << std::endl;
std::cout << "  #  ██                                                      ██    #" << std::endl;
std::cout << "  #  ██        ██████        (o)>      ██████                ██    #" << std::endl;
std::cout << "  #  ██        ██████\\      <_.)       ██████                ██    #" << std::endl;
std::cout << "  #  ██                                                      ██    #" << std::endl;
std::cout << "  #  ██████████████████████████████████████████████████████████    #" << std::endl;
std::cout << "  ##################################################################\n";
std::cout << "  #     🐔 UKELELE CHICKEN - SISTEMA DE GESTIÓN DE CARNES 🐔       #\n";
std::cout << "  #                 POO - C++ - GNU/Linux                          #\n";
std::cout << "  ##################################################################\n";
std::cout << "\033[0m"; // reset colores

}
void Caratula::parpadearPolloUkelele(int veces, int milisegundos) {
    for (int i = 0; i < veces; ++i) {
        clearConsole();
        showPolloUkelele(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
        
        clearConsole();
        showPolloUkelele(false);
        std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
    }
    clearConsole(); // Limpia al final
}

void Caratula::mostrarCaratula() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "           " << titulo << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << " Institución: " << instituto << std::endl;
    std::cout << " Carrera: " << carrera << std::endl;
    std::cout << " Materia: " << materia << std::endl;
    std::cout << " Autor: " << autor << std::endl;
    std::cout << " Proyecto: Boutique de Carnes 'ukelele chicken'" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::endl;
}

void Caratula::mostrarCaratulaConPollo(int veces, int milisegundos) {
    parpadearPolloUkelele(veces, milisegundos);
    
    // Mostrar información formal después del efecto
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "           " << titulo << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << " Institución: " << instituto << std::endl;
    std::cout << " Carrera: " << carrera << std::endl;
    std::cout << " Materia: " << materia << std::endl;
    std::cout << " Autor: " << autor << std::endl;
    std::cout << " Proyecto: Boutique de Carnes 'ukelele chicken'" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::endl;
}

void Caratula::mostrarTitulo() {
    std::cout << "\n" << std::string(50, '*') << std::endl;
    std::cout << "    " << titulo << std::endl;
    std::cout << std::string(50, '*') << std::endl;
}

void Caratula::mostrarDatos() {
    std::cout << " Desarrollado por: " << autor << std::endl;
    std::cout << " Curso: " << materia << std::endl;
    std::cout << " Carrera: " << carrera << std::endl;
    std::cout << std::endl;
}

void Caratula::mostrarBienvenida() {
    std::cout << "\n ¡Bienvenido al Sistema de Gestión!" << std::endl;
    std::cout << " Este sistema permite gestionar:" << std::endl;
    std::cout << " - Animales (productos de carnicería)" << std::endl;
    std::cout << " - Clientes" << std::endl;
    std::cout << " - Pedidos" << std::endl;
    std::cout << " - Polimorfismo de comportamientos" << std::endl;
    std::cout << std::endl;
}