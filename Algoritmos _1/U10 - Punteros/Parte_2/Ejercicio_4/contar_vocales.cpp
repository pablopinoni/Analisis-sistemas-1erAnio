#include "contar_vocales.h"   // Incluye el archivo de cabecera con la declaración de la función
#include <cctype>             // Librería para usar tolower()

namespace Vocales {           // Se define el espacio de nombres "Vocales" para evitar conflictos

// Función que cuenta cuántas veces aparece cada vocal en una cadena
void contarVocales(const std::string &cadena, int *a, int *e, int *i, int *o, int *u) {
    *a = *e = *i = *o = *u = 0;      // Inicializa todos los contadores de vocales en 0

    const char *ptr = cadena.c_str(); // Obtiene un puntero al primer carácter de la cadena

    while (*ptr != '\0') {            // Recorre la cadena hasta llegar al carácter nulo '\0'
        char c = std::tolower(*ptr);  // Convierte el carácter actual a minúscula para uniformar

        switch (c) {                  // Evalúa el carácter actual
            case 'a': (*a)++; break;  // Si es 'a', incrementa el contador apuntado por *a
            case 'e': (*e)++; break;  // Si es 'e', incrementa el contador apuntado por *e
            case 'i': (*i)++; break;  // Si es 'i', incrementa el contador apuntado por *i
            case 'o': (*o)++; break;  // Si es 'o', incrementa el contador apuntado por *o
            case 'u': (*u)++; break;  // Si es 'u', incrementa el contador apuntado por *u
        }

        ptr++;                        // Avanza el puntero al siguiente carácter
    }
}

} // Fin del namespace Vocales
