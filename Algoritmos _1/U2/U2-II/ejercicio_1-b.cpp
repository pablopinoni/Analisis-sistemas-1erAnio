//Realizar un programa que pida 3 datos y nos devuelva el promedio
#include <iostream>
using namespace std;

int main() 
{
    int dato1, dato2, dato3;
    double result;
//Obtener datos
    cout <<"Ingrese gastos en Diciembre:" <<endl;
    cin >> dato1;

    cout <<"Ingrese gastos en Enero:" <<endl;
    cin >> dato2;

    cout <<"Ingrese gastos en Febrero:" <<endl;
    cin >> dato3;

    //Calculo promedio
   result = (dato1 + dato2 + dato3) / 3.0;

    cout << "El promedio de gastos de Diciembre a Enero fue de " << result << '.' << endl;

    return 0;
}

