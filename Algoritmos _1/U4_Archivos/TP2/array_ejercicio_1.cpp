/* 1. Realizar un programa Que rellene un array con los 100 primeros números enteros y los
muestre en pantalla*/
#include <iostream>
using namespace std;

typedef int tNumEnt[100];

int main() {
tNumEnt ceroACien;

    int i;
    // Rellenar el array con los números del 1 al 100
    for (i = 0; i < 100; i++) {
       ceroACien[i] = i + 1;
    }

    // Mostrar el array
    for (i = 0; i < 100; i++) {
        cout <<ceroACien[i] << " " ;
    }
   
    cout << endl;









}