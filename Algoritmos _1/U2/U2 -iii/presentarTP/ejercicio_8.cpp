// 8. Hacer un programa en C++ que pida números mientras no se escriba un número negativo.
//El programa terminará escribiendo la suma de los números introducidos.

#include <iostream>

using namespace std;


int main(){

float numerosPediddos;
float suma = 0.0;
 do 
    {
        cout << "Ingresar numero: " << endl;
        cin >> numerosPediddos;
    
         if (numerosPediddos >= 0); { // Preguntar si esta bien primero if y dsps while
            suma += numerosPediddos;  
             }

            } while (numerosPediddos >= 0); { // Semantine el loop mientras es positivo
                cout << "\n***RESULTADOS***" << endl;     
                cout << "\nLa suma de los numeros positivos ingresados es: \n\t\t" << suma << endl;

    return 0;
             }
    return 0;         

   }




















