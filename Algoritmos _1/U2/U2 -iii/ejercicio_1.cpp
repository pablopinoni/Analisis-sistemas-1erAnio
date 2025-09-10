//DEscuento segun cantidad de unidades compradas
#include <iostream>
using namespace std;




int main ()

{
    const int precio = 80;
    int unidades;
    float descuento;
    float result;
    

  cout << " Cantidad de unidades a comprar: " << endl;
  cin >> unidades;
  
  
  if ( unidades > 31) {
    result = precio * unidades * 0.6;
  }
 else if ( unidades > 21) {
    result = precio * unidades * 0.75; 
 }
 else if ( unidades > 10) {
    result = precio * unidades * 0.88; 
 }
 else if (unidades >= 1) {
    result = precio * unidades * 1;

 }
while (unidades < 0 || unidades > 1000) { 
    cout << "Entrada no valida." << endl;
 return 0;
 }
 
 cout <<" EL costo total por " << unidades << " unidades es de " <<  result << "  pesos." << endl;
 return 0;

}



