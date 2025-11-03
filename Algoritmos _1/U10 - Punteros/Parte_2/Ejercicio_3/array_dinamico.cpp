#include "array_dinamico.h"



// --- Implementación del Ordenamiento por Burbuja (Bubble Sort) ---
void sortDynamicArray(int* datos, int size) {
    int i, j;
    
    // Recorrido de pases (outer loop)
    for (i = 0; i < size - 1; i++) {
        
        // Recorrido interno para comparar adyacentes
        for (j = 0; j < size - i - 1; j++) {
            
            // Si el elemento actual es mayor que el siguiente, se intercambian
            if (datos[j] > datos[j+1]) {
                
                // Intercambio (Swap)
                int temp = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = temp;
            }
        }
    }
}

// --- Implementación Imprimir Array ---
void printArray(int* arr, int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) {
       std:: cout << arr[i];
        if (i < n - 1) {
         std::   cout << ", ";
        }
    }
   std:: cout << " ]\n";
}