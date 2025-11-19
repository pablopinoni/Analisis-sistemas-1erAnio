// caratula.hpp
#pragma once
#include <string>
#include <thread>
#include <chrono>

class Caratula {
private:
    std::string titulo;
    std::string autor;
    std::string materia;
    std::string carrera;
    std::string instituto;

public:
    Caratula();
    ~Caratula();
    
    void mostrarCaratula();
    void mostrarCaratulaConPollo(int veces = 2, int milisegundos = 800);
    void mostrarTitulo();
    void mostrarDatos();
    void mostrarBienvenida();
    
private:
    void showPolloUkelele(bool encendido);
    void parpadearPolloUkelele(int veces, int milisegundos);
    void clearConsole();
};