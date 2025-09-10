/*Escribe un programa que lea del teclado una frase y a continuación visualice las palabras de la
frase en columna, seguida cada una del número de letras que la componen.*/
#include <iostream>
#include <string>
using namespace std;

int main() { 

  string cadena, palabra= "";
  

cout << "Escriba una frase:\n" << endl;
getline(cin, cadena);
 
int pos;
 int caracteresTotales = cadena.size();
 cadena.find(palabra);
// ... (lectura de cadena)

pos = 0;


while (pos <= caracteresTotales) {

// Mientras no se llegue al final de la cadena
  if (pos == caracteresTotales|| cadena[pos]== ' '){
      
    if (!palabra.empty()) {
                cout << palabra << "\t" << palabra.length() << "\n";
                palabra = ""; // Reiniciar palabra para la siguiente
            }
     } 
    
     else {
            
            palabra += cadena[pos];
        }
  


pos++;//contador 


    } // ...












    return 0;
}