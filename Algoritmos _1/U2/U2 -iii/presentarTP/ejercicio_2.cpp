#include <iostream>
using namespace std;
//Prototipo de funciones
int salarioHasta40Hs (int hsTrabajadas,int precioHsReg);
int salarioMas40Hs (int hsTrabajadas, int precioHsReg, int precioHsEx);

int main() {
const int precioHsReg = 200;
const int precioHsEx  = 250;
int hsTrabajadas;
int salario; 

cout << "Calculadora de Salario" << endl;
cout << "Ingrese la cantidad de hs semanales trabajadas: "<< endl;
cin >> hsTrabajadas;

while (hsTrabajadas == 0 ) { 

    cout << "Entrada no valida." << endl;
return 0;
  }

 if (hsTrabajadas < 41) {
  salario = salarioHasta40Hs ( hsTrabajadas, precioHsReg);
 }
else if (hsTrabajadas > 40) {
    salario =  salarioMas40Hs (hsTrabajadas, precioHsReg, precioHsEx);
}

cout << "El salario a cobrar es de $" << salario << ".- " << endl;

return 0;
}

//Declaracion de las funciones
int salarioHasta40Hs (int hsTrabajadas, int precioHsReg){
     return hsTrabajadas * precioHsReg;
  }

int salarioMas40Hs (int hsTrabajadas, int precioHsReg, int precioHsExtra){
    return (40 * precioHsReg) + (hsTrabajadas - 40) * precioHsExtra; 
  }