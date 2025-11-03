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

//Función consigna 2
//Función consigna 2
int findMinElement(int* datos, int size){ //Desreferencia datos para usarlo como parámetro 


// Creamos punteros de inicio y fin

    int* ptr_actual = datos; //se le asigam la dirección de datos, primer posisción del array, no usamos &
    int* ptr_final = datos + size; // creamos puntero int cuya dirección es el valor de size x int(4bytes)



    // 1. Inicialización del menor valor
    // Tarea 1: Inicializa con el valor del primer elemento.
    int menor_valor = *datos; 
    
    // 2. Avanzamos el puntero de trabajo para empezar a comparar desde el segundo elemento.
    ptr_actual++; 
    
    // 3. Bucle de recorrido
    while (ptr_actual < ptr_final) {
        
        // 4. COMPARACIÓN: Si el valor apuntado por ptr_actual es menor que menor_valor
        // Tarea 2: Usa la desreferencia en la condición.
        if (*ptr_actual < menor_valor) {
            
            // 5. ACTUALIZACIÓN: menor_valor = valor apuntado por ptr_actual
            // Tarea 3: Usa la desreferencia en la asignación.
            menor_valor = *ptr_actual;
        }
        
        // Avance al siguiente elemento
        ptr_actual++; 
    }
    
    return menor_valor;
}



