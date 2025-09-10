#include <iostream>
using namespace std;
// Porotoipo de funcio Nota Final
float notaFinal (int, int, int);

int main() 
{ int notaLab, notaTeo, notaPrac;
    cout << "Ingrese nota obtenida en Laboratorio: " << endl;
    cin >> notaLab;
    cout << "Ingrese nota obtenida en Teoria: " << endl;
    cin >> notaTeo;
    cout << "Ingrese nota obtenida en Practica: " << endl;
    cin >> notaPrac;

    // LLamada a la funcion //
    cout << "La nota final es: " << notaFinal(notaLab, notaTeo, notaPrac) << endl;

    return 0;



}
// Implementacion de la Funcion
float notaFinal (int notaLab, int notaTeo, int notaPrac)

{  return  float(( notaLab *30) + ( notaTeo *  60) + (notaPrac * 10)) / 100;

//{return ( notaLab * 0.3) + ( notaTeo *  0.6) + (notaPrac * 0.1);

}