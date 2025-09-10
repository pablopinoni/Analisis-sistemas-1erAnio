//Escribe un programa en C++ que nos diga cuál es el volumen de un cono con
//un radio de la base de 14,5 y una altura de 26,79. La fórmula que debes usar
//es: (PI * Radio al cuadrado * altura)/3 Recuerda que el valor (aproximado) de
//ԉ es 3,141592.
#include <iostream>
using namespace std;

int main() 
{
    // Valores  enteros (sin decimales)
    const int Pi = 3.141592;  // Valor de variable constante    
    int radio = 14.5;         
    int altura = 26.79;       
    // Fórmula: (PI * radio² * altura) / 3
     int volumen = (Pi * (radio * radio ) * altura) / 3;

    cout << "Volumen del cono (usando int) es:  " << volumen  << endl;

    return 0;
}