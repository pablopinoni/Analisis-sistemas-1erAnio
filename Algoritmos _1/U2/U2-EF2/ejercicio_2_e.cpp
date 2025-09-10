// Nos piden un programa que resuelva la siguiente función lineal con salida x
//consola, deber pedir 4 valores para x dando le valor de y por consola.:
// y= 2x +1 


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

int x;

   cout << "\n\n\nCALCULADORA DE FUNCION LINEAL" << endl; 
   
   

  for (int i=0; i < 4; i++){
       cout << "\nIngrese valor de x" << (i + 1) << ":"  << endl;
       cin  >> x; 
    int y=  2 * x + 1; 
    
       cout << "EL valor de y es = " << y << endl; 
}

 cout << "\n\tCompletado el programa, el ejercicio y el TP Especial Funciones.\n" << endl;




    return 0;

}
