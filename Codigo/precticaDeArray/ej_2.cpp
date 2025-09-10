/* crear una estructura simple (por ejemplo, Persona con un id y un nombre) y declarar una variable de ese tipo.*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int Max_numero= 90;
struct tLista
{
    string nombre;
    int id;
};
struct Contenedor
{ tLista personas[Max_numero];
  int contador2;  
};

tLista persona1 = {"Ana", 23};

tLista persona2 = {"Tony", 25};
tLista persona3 = {"Leo" , 32};

tLista personas[Max_numero] = {persona1, persona2};
int main()
{ 
    
    Contenedor Grupo;

    int indice = 1;
    // recorrido
    for (int i = 0; i < 2; i++)
    {
        cout <<  indice << ") ID: " << personas[i].id << " | Nombre: " << personas[i].nombre << endl;

        indice++;
    }

    return 0;
}