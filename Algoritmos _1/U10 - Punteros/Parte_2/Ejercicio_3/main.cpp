#include <iostream>
#include <ostream>
#include "array_dinamico.h"
using namespace std;

int main() {
    int N;
    cout << "======================================/n"
         << "/tARRAYS DINÁMICOS/t"
         << "======================================/n" << endl;
    // ... Código para pedir N y usar cin ...
    cout << "Ingrese la cantidad d enúmeros que desee. Para finañizr ingrese x." << endl;
    // Asignación de Memoria
    int* dynamicArray = new int[N]; 
    
    // Llamada a la lógica
    sortDynamicArray(dynamicArray, N);
    
    // Liberación de Memoria
    delete[] dynamicArray;
    
    return 0;
}