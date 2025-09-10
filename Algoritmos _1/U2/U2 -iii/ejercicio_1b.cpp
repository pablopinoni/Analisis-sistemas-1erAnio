//DEscuento segun cantidad de unidades compradas
#include <iostream>
using namespace std;
//Prototipo de las funciones 
float descuento12(int unidades);
float descuento25(int unidades);
float descuento40(int unidades);


int main ()

{
    const int precio = 80;
    int unidades;
    float result;
    

  cout << " Cantidad de unidades a comprar: ";
  cin  >> unidades;
  
  // Asegurarse la entrada de un numero valido (ebtre 1 y 999)
  while (unidades < 0 || unidades > 1000) { 

    cout << "Entrada no valida." << endl;
 return 0;
 }
 
  // Descuento segun rango de unidades
  if ( unidades > 31) { // Llamada a la funcion
    result = descuento40(unidades) * precio;
  }
 
  else if ( unidades > 21) {
    result = descuento25 (unidades) * precio;
  }
    else if ( unidades > 10) {
    result = descuento12 (unidades) * precio;
    }  
 else if (unidades >= 1) {
    float descuento40 (unidades);
       
    
    result = precio * unidades * 1;

 }

 cout <<" EL costo total por " << unidades << " unidades es de " <<  result << "  pesos." << endl;
 
 
 
 return 0;
 
 
 } 
 
 // DEclaracion de funciones
 
 float descuento40 ( int unidades) {
    return unidades * 0.6f; 
 }

 float descuento25 ( int unidades) {
    return unidades * 0.75f; 
 }

 float descuento12 ( int unidades) {
    return  unidades * 0.88f; 
 }