#include <iostream>
#include <string>
using namespace std;


// ============================
// ENUMERACIONES
// ============================
 


// Variables globales


bool volando = false;
int velocidad = 0;
const int velocidadMax = 70;
float altura = 0.0f;





// ============================
// PROTOTIPOS
// ============================


//Funciones Principales

void despegar();
void aterrizar();
void acelerar();
void frenar();
string estadoActual();

//Funciones auxiliares
void mostrarMenuPrincipal();
void clearConsole();









int main (){

 int opcion;
 bool repetir = true;// mantener el loop hasta que el usuaario pida la salida    
 
 do {
  clearConsole();

    cout << "\n\t#========================#"  << endl;
    cout << "\n\t      DRONE CONTROL\n" << endl;  
    cout << "\t#========================#\t\n"  << endl;
    
    cout << "   MENU PRINCIPAL\n" << endl;  


    mostrarMenuPrincipal();
    cin >> opcion; //¿¿¿ cin en main o en la declaracion de la funcion???
  
  
    clearConsole();
    
    switch (opcion) {
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
        
        case 0: //Salir No sé si es mejor dejar  "case 0;"
         repetir = false;
        break;
    
      default:
         
       cout << "Ingrese opcion valida: " << endl;
        break;
         } //Token cierre switch
   
         
   
     //cierre Do

      //  cout << estadoActual() << endl; no poude hacer que salga bien
        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();


  } while (repetir);

              return 0;


   
}  //cierre main

    
//Declaracion de las Funcione



void mostrarMenuPrincipal() {
    cout << "1. Despegar" << endl;
    cout << "2. Aterrizar" << endl;
    cout << "3. Acelerar" << endl;
    cout << "4. Frenar" << endl;
    cout << "0. Salir" << endl;
    cout << "\nSeleccione una opcion: ";
}

 void despegar(){ 
    if (!volando) {
    velocidad = 5;
    altura = 10;
    volando = true;  
    
    cout << "Chequeando 5... 4 ... 3 ..2 .. 1... 0..." << endl;
    cout << "\t\t  Dspegue exitoso!!!!!" << endl;  
    cout << "\t\t#=================#\n"  << endl;
 }
    
    else {
        cout << "El dron ya esta volando a " << altura << " metros." << endl; 

    }
  
  }

void acelerar() {
  if (volando) {
      if (velocidad + 5 <= velocidadMax) {
          velocidad += 5;
          cout << "Velocidad aumentada en 5 km/h. Velocidad actual: " << velocidad << " km/h." << endl;
      } else {
          cout << "Ha alcanzado su velocidad máxima de " << velocidadMax << " km/h." << endl;
      }
  } else {
      cout << "El dron debe estar en vuelo para acelerar." << endl;
  }
}
    
    
 void frenar(){
    
        if (volando && velocidad > 5 ) {
        velocidad -= 5;
        cout << "Velocidad reducida en 5 km/h. Velocidad actual: " << velocidad << " km/h." << endl;
      
       }
        else { 
     
           cout << "No se puede seguir reduciendo la velocidad. Velocidad actual: " << velocidad 
            << " km/h." << endl;
        }
    
     }


     void aterrizar() {
               if (volando ) {
                velocidad = 0;
                altura = 0.0;
                volando = false;

                cout << "Chequeando 5... 4 ... 3 ..2 .. 1... 0..." << endl;
                cout << "\t\t  Aterrizaje exitoso!!!!!" << endl;  
                cout << "\t\t#============================#\n"  << endl;
               }

                 else {
                cout << "Error: El dron ya está en tierra (altura: 0 m)" << endl;
                }

     }




       
    
    
   string estadoActual( int velocidad, float altura) {
    
    return "/ESTADO/ Altura: " + to_string(altura) +  " m | Velocidad: " + to_string(velocidad) + " Km/h."; 
}


void clearConsole() {
  #ifdef _WIN32
      system("cls");
  #else
      system("clear"); //Mac o Linux
  #endif
  }