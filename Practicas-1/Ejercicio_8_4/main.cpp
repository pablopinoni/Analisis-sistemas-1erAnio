#include <iostream>
using namespace std;

//Declarar prototipo de función:
int multiply(int a, int b);

int main()
{
    /* code */
    //declarar y definir variables de tipo integer.
    
    int n1;//declarar: reservo y denomino el contenedor (espacio en memoria) o variable. 
    
    n1 = 2;//definir: establecer el valor de la variable.

    int n2 = 3; //declarar y definir.

    //solo declarando la variable resultado:
    int result;

    //llamar a la función y cargar lo que retorna en la variable "result".
    result = multiply(n1, n2);
    
    //mostrar resultado en pantalla:
    cout << "El resultado de la multiplicacion es: " << result << endl;

    //siempre se retorna int en la función main
    //0 significa todo piola para el computador.
    return 0;
}

//Definir función
 int multiply(int a, int b)
{
    return  a * b; 
}