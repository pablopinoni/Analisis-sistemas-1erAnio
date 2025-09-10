/* API manejar un Drone, 
con 4 funciones Básicas: Despegar, Aterrizar, acelerar y frenar (una reducción pedagógica). 
La API deberá ser Modularizada en Funciones, Operada vía Menú x consola.*/



#include <iostream>
#include <limits>
#include <cstdlib>
#include<string>
using namespace std;


//Definicion de Tipos
//typedef int tAltura;
typedef int tVelocidad;

//Prototipos de funciones

// principales

void despegar();
void aterrizar();
void acelerar();
void frenar();
string estado();
bool volando();


// auxiliares
void clearConsole();
void pauseConsole();
void menu();


//VAriables globales
velocidad = 0 ;
altura = 0;
bool volando = false;

int main() 
{ 
    int opcion;
    bool repetir = true;


    do{ 
    
        clearConsole();
        cout << "t\tAPI DRONE/t" << endl;
        cout << "/t.........../t" <<  endl;
        cout << "/tMain Menu/t" << menu << endl;

        switch (opcion)
        {
        case 1:
            despegar();
            break;

        case 2:
            aterrizar();
            break;   
        
        case  3:
            acelerar();
            break;

        case 4: 
            frenar();
            break;
            
            case 0: //Salir
             repetir = false;
            break;
        
        default:
             
        cout << "Ingrese opcion valida: " << endl;
        break;
        }
    }    
    while (true);
    

        return 0;
}

//DEclaracion de Funciones Principales

constant despegar(){
if (altura = 0 )
}

bool aterrizar (int) {
if (altura >0)
}


int acelerar(int) {
   cons  tVelocidad velocidadMaxima = 70;

   if  (velocidad < velocidadMaxima)
    {
    velocidad =+ 5;
   return cout <<  "Velocidad aumentada en 5"; end;}
   else {
    return cout << " Ha alcanzado su velocidad maxima." <<  endl;
   }
}


int frenar(int){

    if (velocidad >= 5 ) {
    velocidad = - 5;
    return cout << "Reduciendo velocidad." << endl;
   }
    else { 
 
        return cout << "No se puede seguir reduciendo la velocidad." << endl;
    }

    

   }
int estado(tVelocidad velocidad, tAltura altura)  {
string estadoActual; 
  return "/ESTADO/ Altura: " + to_string(altura) + "Velocidad: "  "m | " + to_string(velocidad) + " Km/h."; 
}

void clearConsole() {
    //system("cls"); // Para Windows
     system("clear"); // Para Linux/Mac
} 







