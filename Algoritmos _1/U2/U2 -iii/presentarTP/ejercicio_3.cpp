#include <iostream>
using namespace std;

float calcularPromedio(int num1, int num2, int num3);


int main () {

int num1, num2, num3;
bool aprobado;
float prom; 

cout << "Ingrese Nota 1: " << endl;
cin >> num1;
cout << "Ingrese Nota 2: " << endl;
cin >> num2;
cout << "Ingrese Nota 3: " << endl;
cin >> num3;
prom = calcularPromedio(num1, num2,  num3);

if (prom >= 70) {  
    aprobado = true;
    cout << "Aprobado con promedio: " << prom;

}
  else {
    aprobado = false;
    cout << "Desaprobado con promedio: " << prom <<  "\t" << endl;
}

return 0;

}

//Declaracion de funcion Promedio
float calcularPromedio(int num1, int num2, int num3) {
    return static_cast<float>(num1 + num2 + num3) / 3;
}
