#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <string>
// Asumo que estas cabeceras están definidas en tus include/
#include "clientes.h" 
#include "articulos.h" 
#include "constants.h" 

class Order {
private:
    std::string code;
    Customer* customer; 

    // CORRECCIÓN 1: Definición de struct y uso de la constante correcta (MAX_ARTICLES)
    struct ArticleList {
        // CORRECCIÓN 1.1: Usamos la constante MAX_ARTICLES para el array de artículos
        Article* articles[Constants::MAX_ARTICLES]; 
        int numArticles;
        // CORRECCIÓN 1.2: El miembro 'numArticles' debe terminar con punto y coma
    } items; // CORRECCIÓN 1.3: El struct debe terminar con punto y coma aquí

public:
    Order(std::string code, Customer* customer);
    // Nota: El destructor ya estaba bien, pero se incluye para completitud si existía:
    //~Order(); 
    
    // CORRECCIÓN 2: Declaración de getCode() faltante
    std::string getCode() const; 
    
    // CORRECCIÓN 3: Declaración de addArticle() (soluciona el error en application.cpp)
    void addArticle(Article* article);

    // CORRECCIÓN 4: Añadir 'const' a show() para que coincida con la implementación en pedidos.cpp
    void show() const; 
};

#endif // PEDIDOS_H