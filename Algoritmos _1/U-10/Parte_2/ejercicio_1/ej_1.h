#ifndef EJ_1_H
#define ARRAYS_PUNTEROS_H

#include <iostream>
#include <iomanip> // Si planeas usar setw, dec, etc. en la función implementada.

// --- 1. Definiciones Compartidas ---
const int sizeA = 10;
typedef int tArray[sizeA]; 

// --- 2. Prototipo de la Función Modular ---
// La función debe recibir un puntero a entero (el array) y su tamaño.
void showArrayXPunterosParesImpares(int* datos, int size);

#endif // ARRAYS_PUNTEROS_H
