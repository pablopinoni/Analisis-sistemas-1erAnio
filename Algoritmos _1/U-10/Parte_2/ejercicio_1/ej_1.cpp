// arrays_punteros.cpp

#include "ej_1.h" // Necesitas las definiciones y prototipos

// Usamos std:: para evitar la directiva 'using namespace std;' en el header.
using std::cout;
using std::setw;
using std::dec;
using std::endl;

// --- Implementación de la Función ---
void showArrayXPunterosParesImpares(int* datos, int size) {
    
    cout << "\n--- Resultados Consigna 1 (Modularizado y Efectivo) ---\n";

    int* ptr_actual = datos; 
    int* ptr_final = datos + size; 

    while (ptr_actual < ptr_final) 
    {
        if ( (*ptr_actual) % 2 == 0 ) 
        {
            cout << "PAR:   " << dec << setw(3) << (*ptr_actual) 
                 << " | Direccion: " 
                 << (void*)ptr_actual << endl; 
        }
        else 
        {
            cout << "IMPAR: " << dec << setw(3) << (*ptr_actual) 
                 << " | Direccion: " 
                 << (void*)ptr_actual << endl; 
        }
        
        ptr_actual++; 
    }
}