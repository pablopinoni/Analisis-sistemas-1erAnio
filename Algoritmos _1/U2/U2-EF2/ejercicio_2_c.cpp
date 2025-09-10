//Realizar un programa que pida los datos necesarios y Calcule los Perímetros:
//Podes hardcodearlo (poner los valores vos) o pedir por consola
// Rectángulo P = 2 L + 2 W
#include <iostream>
#include <cmath>
#include <cstdlib> 
#include <limits>
using namespace std;

// Prototipos de funciones
void perimetroCuad();
void perimetroRect();
void perimetroTrian();
void pauseConsole();
void clearConsole();

int main() {

int opcion;
bool repetir = true;

do{

   clearConsole();

   cout << "\n\n\t\t\tMENU CALCULAR PERIMETRO" << endl;
   cout << "\t\t\t-----------------------" << endl;
   cout << "\n\t1. Cuadrado" << endl;
   cout << "\t2. Rectangulo" << endl;
   cout << "\t3. Triangulo" << endl;
   cout << "\t0. REGRESAR" << endl;

   cout << "\n\tIngrese una opcion:  ";
   cin >> opcion;  





   switch (opcion)
   {
       case 1:
            perimetroCuad();
            break;

       case 2:
            perimetroRect();
            break;
            
       case 3:
            perimetroTrian();
            break;
            
         
       case 0:
            repetir = false;
            break;   

         default: 
         cout << "\tIngrese una opcion correcta (1/2/3/0): " << endl; 
      } 
   }     
   while (repetir);
  return 0; 
 

   }
   
//Declaracion de las funciones principales
void perimetroCuad()
{
    clearConsole();

     int lado1= 6;
     int resultado;
    
   
     
     resultado = (lado1 * 4);
     cout << "\tResultado: " << resultado << endl;

      pauseConsole();
}
void perimetroTrian()
{  
   clearConsole();
      
   int lado1= 5;
   int lado2= 5; 
   int lado3= 8;
   int  resultado;
    

      cout << "\n\tPerimetro Triangulo";
      cout << "\n\t=========================\n";
      
      cout << "\t--------------------------" <<endl;
      resultado = lado1 + lado2 + lado3;
      cout << "\tResultado: " << resultado << endl;

      pauseConsole();
}

void perimetroRect()
{
      int largo = 9;
      int ancho= 7;
      int  resultado;
     clearConsole();

      cout << "\n\tPerimetro Rectangulo";
      cout << "\n\t=========================\n";
      cout << "\t--------------------------" <<endl;

      
      resultado = (largo * 2) + (ancho * 2);
      cout << "\tResultado: " << resultado << endl;

      pauseConsole();
}


// Implementación de funciones auxiliares
void clearConsole() {
  //system("cls"); // Para Windows
   system("clear"); // Para Linux/Mac
}


   //system("pause"); // Para Windows
   void pauseConsole() {
      cout << "\n\tPresione Enter para continuar...";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
    //system("pause"); // Para Windows 
   }








