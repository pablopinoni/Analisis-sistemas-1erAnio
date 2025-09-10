/*Leer desde un archivo los datos de varias personas, guardar cada una en un arreglo de estructuras,
 y luego mostrar a la persona con mayor edad.*/

#include <iostream>
#include <string>
#include<fstream>
#include <iomanip>
using namespace std;
//Enumeraciones

struct persona_struct
{ string nombre;
    int edad;
   
};


//Funciones protitipo


//Variables globales


int main(){
const int MAX_PERSONAS = 100;
    persona_struct personas[MAX_PERSONAS];
    int cantidad = 0;

    //Abrir archivo cargar a la memoria
    ifstream archivo("personas.txt");

    //Esta abierto?
    if (!archivo.is_open())
    {
       cerr << "Error no pudo abrirse el archivo"<< endl;
       return 1;
    }
    
    //Procesamos informacion
     while (archivo >> personas[cantidad].nombre >> personas[cantidad].edad) {
     cantidad++;
     if (cantidad >= MAX_PERSONAS) break;
       }
 
 
int indiceMayor = 0;
for (int i = 1; i < cantidad; i++) {
    if (personas[i].edad > personas[indiceMayor].edad) {
        indiceMayor = i;
    }
}


    //llamada a las funciones


    // salida por consola

cout << "La persona de mayor edad es: "
     << personas[indiceMayor].nombre << " con "
     << personas[indiceMayor].edad << " años." << endl;


    //cerramos el archivo

archivo.close();


    return 0;
}