//Realizar un programa que pida la fecha de nacimiento y nos de la edad
#include <iostream>

using namespace std;

int main() 
{
    int diaN, mesN, anioN;
    int diaA, mesA, anioA;
    
    // Obtener fecha actual
    cout << "Ingresa fecha actual (DD MM AAAA): ";
    cin >> diaA >> mesA >> anioA;

    
    // Pedir fecha de nacimiento
    cout << "Ingresa tu fecha de nacimiento (DD MM AAAA): ";
    cin >> diaN >> mesN >> anioN;

    // Calcular edad
    int edad = anioA - anioN;
    
    // Ajustar si aún no ha pasado el cumpleaños este año
    if (mesA < mesN || (mesA == mesN && diaA < diaN)) 
    {
        edad;
    }

    // Mostrar resultados
    //cout << "Tenés " << edad << " años" << endl;
    
    if ( anioN <= 1984 )
    { cout << "Tenés " << edad << " pirulos" << endl;

    }
    else 
    cout << "Tenés " << edad << " años" << endl;

    return 0;
}