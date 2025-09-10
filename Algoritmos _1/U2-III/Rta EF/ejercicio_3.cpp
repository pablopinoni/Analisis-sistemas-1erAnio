#include <iostream>
using namespace std;

// Prototipo de las funciones
void crearRango(float &, float &);
bool perteneceAlRango(float, float, float); 
int main()
{
    float limiteInf, limiteSup;
    float numeroAVerificar;
  
    crearRango(limiteInf, limiteSup); // Llamar a la funcion crearRango

    // Paso 2: Pedir número y verificar
    cout << "Ingrese un numero: " << endl;
    cin >> numeroAVerificar;

    if (perteneceAlRango(numeroAVerificar, limiteInf, limiteSup)) {
        cout << numeroAVerificar << " SI esta en el rango [" << limiteInf << "-- " << limiteSup << "]." << endl;
    } else {
        cout << numeroAVerificar << " NO esta en el rango [" << limiteInf << "--" << limiteSup << "]" << endl;
    }
    
    return 0;
}

// Definir funcion crear rango 
void crearRango(float &limiteInf, float &limiteSup) 
{
    cout << "Ingrese el limite inferior: ";
    cin >> limiteInf;
    cout << "Ingrese el limite superior: ";
    cin >> limiteSup;

    
}

// Implementación de la función de validar
bool perteneceAlRango(float numeroAValidar, float limiteInf,  float limiteSup )

{
    return (numeroAValidar >= limiteInf && numeroAValidar <= limiteSup);
    
}