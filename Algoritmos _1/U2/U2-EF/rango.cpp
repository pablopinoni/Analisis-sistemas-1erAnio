#include <iostream>
using namespace std;

//Prototipo de las funciones
void crearRango (float &, float & );
bool  (float, float, float);

int main()
{
    float limiteInf, limiteSup;
    float numeroAVerificar;
  
    crearRango(limiteInf, limiteSup); // Llamar a la funcion crearRango

    // Paso 2: Pedir número y verificar
    cout << "Ingrese un numero: ";
    cin >> numeroAVerificar;


    if (pertenceAlRango  ( numeroAVerificar, limiteInf, limiteSup )) {
        cout << numeroAVerificar << " SI esta en el rango [" << limiteInf << ", " << limiteSup << "]." << endl;
    
    } 
    else {
        cout << numeroAVerificar << " NO esta en el rango [" << limiteInf << ", " << limiteSup  << "]." << endl;
    }
}
        return 0;




//Definir funcion crear rango 
 void crearRango(float &limiteInf, float &limiteSup); 
     
  { float limiteInf, limiteSup;
    cout << "Ingrese el numero menor: " << endl;
     cin >> limiteInf;
     cout << "Ingrese el numero mayor" << endl;
     cin >> limiteSup;
  } 



 
