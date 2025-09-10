#include <iostream>
using namespace std;

int main() 
{
    // Valores  enteros (sin decimales)
    const double Pi = 3.14;  // Valor de variable constante    
    double radio = 14.5;         
    double altura = 26.79;       
    // Fórmula: (PI * radio² * altura) / 3
     double volumen = (Pi * (radio * 2 ) * altura) / 3;

    cout << "Volumen del cono (usando double) es:  " << volumen  << endl;

    return 0;
}