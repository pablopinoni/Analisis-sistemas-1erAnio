#include "contar_vocales.h"   ///< Incluye el encabezado con la declaración de la función
#include <cctype>             ///< Incluye funciones para manejo de caracteres (tolower)

namespace Vocales {           ///< Espacio de nombres para agrupar funciones relacionadas con vocales

/**
 * @brief Cuenta la cantidad de veces que aparecen las vocales a, e, i, o, u en una cadena.
 *
 * @param cadena Cadena de texto de entrada.
 * @param a Puntero a un entero donde se almacenará la cantidad de 'a'.
 * @param e Puntero a un entero donde se almacenará la cantidad de 'e'.
 * @param i Puntero a un entero donde se almacenará la cantidad de 'i'.
 * @param o Puntero a un entero donde se almacenará la cantidad de 'o'.
 * @param u Puntero a un entero donde se almacenará la cantidad de 'u'.
 *
 * @details La función recorre la cadena carácter por carácter mediante un puntero.
 * Convierte cada letra a minúscula para no distinguir entre mayúsculas y minúsculas.
 * Incrementa el contador correspondiente cada vez que encuentra una vocal.
 */
void contarVocales(const std::string &cadena, int *a, int *e, int *i, int *o, int *u) {
    *a = *e = *i = *o = *u = 0;      ///< Inicializa todos los contadores de vocales en 0

    const char *ptr = cadena.c_str(); ///< Puntero al primer carácter de la cadena

    while (*ptr != '\0') {            ///< Itera hasta llegar al carácter nulo de fin de cadena
        char c = std::tolower(*ptr);  ///< Convierte el carácter actual a minúscula

        switch (c) {                  ///< Determina si el carácter es una vocal
            case 'a': (*a)++; break;  ///< Incrementa el contador de 'a'
            case 'e': (*e)++; break;  ///< Incrementa el contador de 'e'
            case 'i': (*i)++; break;  ///< Incrementa el contador de 'i'
            case 'o': (*o)++; break;  ///< Incrementa el contador de 'o'
            case 'u': (*u)++; break;  ///< Incrementa el contador de 'u'
        }

        ptr++;                        ///< Avanza el puntero al siguiente carácter
    }
}

} ///< Fin del namespace Vocales
