#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// ============================
// ENUMERACIONES
// ============================
 typedef enum { primera, business, economica} tClase_boleto;
 typedef enum { BHI, AEP, EPA, EZE, BRC, CTC, CRD} tAeropuerto;

// ============================
// PROTOTIPOS
// ============================

string getNombreAeropuerto ( tAeropuerto aeropuerto);
string getClase(tClase_boleto a);
void menuAeropuertos();
void menuClases();

//Auxiliares


int main(){

    string nombreApellido;
    int dni;
    tClase_boleto clase;
    tAeropuerto origen, destino;
    int opcion;
    bool verdadero;



    cout << "\n\t\t#==============#"  << endl;
    cout << "\t\t     Reservas" << endl;  
    cout << "\t\t#==============#"  << endl;

    
// Pedido de carga de datos al usuario

//  Nombre y apellido
    cout << "\nIngrese nombre y apellido: " << endl;
    cin.ignore ();
    getline(cin, nombreApellido);
 
 // DNI

    cout << "Ingrese Numero de DNI: " << endl;
    cin >> dni;


//Clase de boleto 
   cout << "Ingrese clase de boleto las mismas pueden ser;" << endl;

   menuClases(); 


   do {
    cout << "Seleccione clase de boleto (0-2): ";
     cin >> opcion;
      if (opcion  <= 2){
        clase = static_cast<tClase_boleto>(opcion); //
        verdadero = true;
       }

      else {
        cout << "Opcion incorrecta." << endl;
        } 
    } 
    while (!verdadero); 

    


// Selección de destino
  // Selección de aeropuerto de origen
  cout << "\nAeropuertos disponibles:\n";
   menuAeropuertos();
  verdadero = false;
  do {
      cout << "Seleccione aeropuerto de origen (0-6): ";
      cin >> opcion;
      
      if (opcion >= 0 && opcion <= 6) {
          origen = static_cast<tAeropuerto>(opcion);
          verdadero = true;
      } else {
          cout << "Error: Opción inválida. Intente nuevamente.\n";
      }
  } while (!verdadero);

  // Selección de aeropuerto de destino con validación
  {
       verdadero  = false;
      cout << "\nAeropuertos disponibles:\n";
       menuAeropuertos();
      
      do {
          cout << "Seleccione aeropuerto de destino (0-6): ";
          cin >> opcion;
          
          if (opcion >= 0 && opcion <= 6) {
              destino = static_cast<tAeropuerto>(opcion);
              verdadero = true;
          } else {
              cout << "Error: Opción inválida. Intente nuevamente.\n";
          }
      } while (!verdadero);

      if (origen == destino) {
          cout << "Error: Origen y destino no pueden ser iguales\n";
      }
  } while (origen == destino);

   


//Mostrar resultados por pantalla

cout << "\n\t\t#==============#"  << endl;
cout << "\t\t     Reserva" << endl;  
cout << "\t\t    Confirmada!!" << endl;
cout << "\t\t#==============#"  << endl;
cout << "Pasajero: " << nombreApellido << endl;
cout << "DNI: " << dni << endl;
cout << "Clase de boleto: " << getClase(clase) << endl;
cout << "Ruta: " << getNombreAeropuerto(origen) 
     << " ===> " << getNombreAeropuerto(destino) << endl;
cout << "\n\t\t#=================================\n" << endl;


return 0;
}





//======= Declaraciones =======//

string getClase(tClase_boleto a) {
    switch(a) {
        case primera: return "Primera Clase";
        case business: return "Business";
        case economica: return "Económica";
        default: return "Desconocida";
    }
}

string getNombreAeropuerto(tAeropuerto a){
    switch(a) {
        case BHI: return "Bahía Blanca (BHI)";
        case AEP: return "Buenos Aires Aeroparque (AEP)";
        case EPA: return "Buenos Aires El Palomar (EPA)";
        case EZE: return "Buenos Aires Ezeiza (EZE)";
        case BRC: return "San Carlos de Bariloche (BRC)";
        case CTC: return "San Fernando del Valle de Catamarca (CTC)";
        case CRD: return "Comodoro Rivadavia (CRD)";
        default: return "Desconocido";
    }
}






void menuAeropuertos() {
    cout << "\nAeropuertos disponibles:\n";
    cout << "0. Bahía Blanca (BHI)\n";
    cout << "1. Buenos Aires Aeroparque (AEP)\n";
    cout << "2. Buenos Aires El Palomar (EPA)\n";
    cout << "3. Buenos Aires Ezeiza (EZE)\n";
    cout << "4. San Carlos de Bariloche (BRC)\n";
    cout << "5. San Fernando del Valle de Catamarca (CTC)\n";
    cout << "6. Comodoro Rivadavia (CRD)\n";
    
}

void menuClases() {
    cout << "\nClases disponibles:\n";
    cout << "0. Primera Clase\n";
    cout << "1. Business\n";
    cout << "2. Económica\n";
    

}





