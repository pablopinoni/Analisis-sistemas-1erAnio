//Escribe un programa que lea del teclado un tiempo transcurrido en segundos
// y muestre en la pantalla las horas, los minutos y los segundos equivalentes.
#include <iostream>
using namespace std;

int main()

{ int totalSegundos, segundos, minutos, horas;

  cout << "Ingrese un tiempo transcurrido en segundos:  " << endl;
  cin >> totalSegundos;
  
  horas = totalSegundos / (60 * 60);          // 1 hora = 60 minutos
  int resto = totalSegundos % 3600;      // Segundos restantes después de calcular horas
    minutos = resto / 60;                  // 1 minuto = 60 segundos
    segundos = resto % 60;                 // Segundos restante
 
 cout << " EL tiempon transcurrido fue de " << horas << "hs " << minutos << "' " << segundos << "'' " << endl;   
    return 0;
}