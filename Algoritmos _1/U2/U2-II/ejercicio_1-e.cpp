//*Modifica el programa anterior para que use tres variables, todas de tipo
//double: radio, altura y volumen. Las dos primeras se inicializarán a 14,5 y
//26,79 respectivamente. La tercera obtendrá el resultado de la fórmula.


#include <iostream>
using namespace std;

int main() 
{
    // Valores  enteros (sin decimales)
    const double Pi = 3.141592;  // Valor de variable constante    
    double radio = 14.5;         
    double altura = 26.79;       
    // Fórmula: (PI * radio² * altura) / 3
     double volumen = (Pi * (radio * radio ) * altura) / 3;

    cout << "Volumen del cono (usando double) es:  " << volumen  << endl;

    return 0;
}