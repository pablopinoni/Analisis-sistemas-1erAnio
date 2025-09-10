#include <iostream>
using namespace std;

typedef int tCeroACien[100];
//funcion numero impar
bool Impar(int numero);



int main() {

int contador=0; // cuantos impares llevamos
tCeroACien numeroImpar;// array para guardar los numeros primos
  

for (int i = 1; i <= 100; i++) {
    if (Impar(i)) {
        numeroImpar[contador] = i; // guardamos el impar en el array
        contador++;             // aumentamos el contador
         }
     }
    
    
     // Mostrar el array
     int j;
     for (j = 0; j < contador; j++) {
   
        cout <<numeroImpar[j] << " ";
    }

cout  << endl;
    return 0;
}
bool Impar(int numero) {
  
    if (numero %2==0) return false;
    else { return true;
    }
}
