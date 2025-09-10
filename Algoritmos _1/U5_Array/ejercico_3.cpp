/* 3. Implementa un programa que permita realizar operaciones sobre matrices de NxN. El programa
debe permitir al usuario la selección de alguna de las siguientes operaciones:
a) Sumar 2 matrices.
b) Restar 2 matrices.
c) Multiplicar 2 matrices.
d) Trasponer una matriz.
e) Mostrar una matriz señalando cuáles son los puntos de silla (los puntos de silla de una matriz
son aquellos elementos de la misma que cumplen ser el mínimo de su fila y el máximo de su
columna).
Habrá también dos subprogramas para leer del teclado o mostrar en la pantalla una matriz.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Enumeraciones
enum tOperacionMatriz{sumarDos=1, restarDos, MultiplicarDos, trasponerUna, puntosSilla };


//Funciones
void SumarDosMatrices();
void RestarDosMatrices();
void MultiplicarDosMatrices();
void TrasponerUnaMatriz();
void PuntoSilla(),

//Subprogramas
typedef string tSubprorgrama;
string LeerDelTeclado(int,int);
string MostrarMatriz(filas, columnas);

//Funciones auxiliares
void MostrarMenu();
void ClearConsole();


//VAriables globales


int main(){

//Variables locales
int opcion;
bool continuar;
do
{
   

ClearConsole();
//Salida 
 cout << "\n\tPROGRAMA DE OPERACION CON MATRICES\t\n" << endl;
 cout << "\n\t\tSeleccione una opción:\t\n" << endl;
MostrarMenu();
cin >> continuar;
switch (opcion) {
      case 1:
        SumarDosMatrices();
        break;

      case 2:
        RestarDosMatrices();
        break;   
    
      case  3:
        MultiplicarDosMatrices();
        break;

      case 4: 
       TrasponerUnaMatriz();
       break;
        
      case 5: 
       PuntoSilla();
        break;  
        case 0: //Salir No sé si es mejor dejar  "case 0;"
         continuar= false;
        break;
    
      default:
         
       cout << "Ingrese opcion valida: " << endl;
        break;
         } //Token cierre switch
   
         
   
        }//cierre Do

      //  cout << estadoActual() << endl; no poude hacer que salga bien
        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();






 while (condition !=0);




    return 0;

}
















//DEclaracion de las funciones

//Auxiliares

void MostrarMenu() {
    
    cout << "\n\t\tSeleccione una opción:\t\n" << endl;
    cout << "1. Sumar 2 matrices" << endl;
    cout << "2. Restar 2 matricesr" << endl;
    cout << "3. Multiplicar 2 matrices" << endl;
    cout << "4. Trasponer una matriz" << endl;
    cout << "5. Puntos de silla" << endl;
    cout << "0. Salir" << endl;

}



void ClearConsole(){

#ifdef _WIN32
      system("cls");
  #else
      system("clear"); //Mac o Linux
  #endif


}



