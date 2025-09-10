#include <iostream>
using namespace std;

typedef int tCeroACien[100];
//funcion numero primo
bool numeroPrimo(int numero);



int main() {

int contador=0; // cuantos primos llevamos
tCeroACien numPrimo;// array para guardar los numeros primos
  

for (int i = 1; i <= 100; i++) {
    if (numeroPrimo(i)) {
        numPrimo[contador] = i; // guardamos el primo en el array
        contador++;             // aumentamos el contador
         }
     }
    
    
     // Mostrar el array
     int j;
     for (j = 0; j < contador; j++) {
   
        cout <<numPrimo[j] << " " ;
    }
 cout << endl;

 return 0;
}
bool numeroPrimo(int numero) {
   int contador;
    if (numero < 2) return false;

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false;
    }
  tCeroACien numPrimo[contador];
    return true;
}
   