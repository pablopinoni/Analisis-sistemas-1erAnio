#include <iostream>

using namespace std;

int main() 
{
    double n1; // Declaro variables y reservo espacio de memoria
    double n2;    
    // pedimos igreso de datos al usuario
    cout << "Ingrese el primer número: "; cin >> n1;
    cout << "Ingrese el segundo número: "; cin >> n2;

    // Declaro las operaciones
    double add = n1 + n2;
    double subs = n1 - n2;
    double mult = n1 * n2;

    
    // /mostrar el resultado en pantalla
    cout << "El resultado de la suma es:  " << add << endl;
    cout << "El resultado de la resta es: " << subs << endl;
    cout << "El resultado de la multiplicación es: " << mult << endl;

    // Evitar denominador cero para aplicar ejemplo de los visto el algoritmos
    if (n2 != 0) 
    {
    double 
    divs = n1 / n2;
     cout << "El resultado de la división es: " <<  divs << endl;

    } 
    else {
        cout << "No se puede dividir por cero " << endl;
    }

    return 0;
}