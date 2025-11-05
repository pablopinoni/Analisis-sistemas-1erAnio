#pragma once

// Usamos un namespace para agrupar las constantes y evitar colisiones de nombres globales.
namespace Constants {
    
    // Las constantes ahora son de tipo int, vistas por el compilador y el debugger.
    // Esto es preferible a las directivas #define.
    const int MAX_ITEMS = 256;      // Límite para elementos en una colección, como en Order::ArticleList
    const int MAX_CUSTOMERS = 256;  // Límite para la colección de clientes del sistema
    const int MAX_ARTICLES = 256;   // Límite para la colección de artículos disponibles en el sistema
    const int MAX_TERMS = 256;
} // namespace Constants