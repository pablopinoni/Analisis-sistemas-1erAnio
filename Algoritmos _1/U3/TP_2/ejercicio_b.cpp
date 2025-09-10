/*Hacer un programa en C++ que ayude a una empresa a
incrementar los salarios de los trabajadores de la siguiente manera:
Tipo de salario %
De 0 a $9 000 20%
De $9 000 a $15 000 10%
De $15 000 a $20 000 5%
Más de $20 000 3%*/





#include <iostream>
using namespace std;



typedef float tSalario;



int main() {

tSalario mesAnt;
tSalario actual;




    cout << "Ingrese salario cobrado el último mes:" << endl;
    cin >> mesAnt;
     if ( mesAnt <0) { cout << "Imgrese un número valido.";
    }

     
     if ( mesAnt < 9000){
     actual= mesAnt * 1.2;
     }
      else if ( mesAnt < 15000){
        actual= mesAnt * 1.1;
       
      }
       else if ( mesAnt <= 20000){
            actual= mesAnt * 1.05;
           
       }
           else {
                actual= mesAnt * 1.03;
                
            }

            

cout << "El sueldo actual es: $" << actual << ".-" << endl;

     return 0;
    }
    













