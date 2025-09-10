//Realizar un programa que pida 4 datos y devuelva el producto de Ambos
#include <iostream>
using namespace std;

int main() 
{
    int dato1, dato2, dato3, dato4;
    int  multiplicacion;
//Obtener datos
    cout <<"Ingrese numero de unidades en cada caja:" <<endl;
    cin >> dato1;

    cout <<"Ingrese numero de cajas desargadas en cada entrega:" <<endl;
    cin >> dato2;

    cout <<"Ingrese cantidad de entregas semanales:" <<endl;
    cin >> dato3;

    cout <<"Ingrese cantidad de semanas que ha recibido entregas:" <<endl;
    cin >> dato4;

    //Calculo promedio
   multiplicacion = dato1 * dato2 * dato3 * dato4;

    cout << "El el total de unidades fue de " << multiplicacion << '.' << endl;

    return 0;
}
