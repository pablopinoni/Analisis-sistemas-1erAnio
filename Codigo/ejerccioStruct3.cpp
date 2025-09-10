/*Leer los datos desde el archivo.

Calcular el promedio de cada estudiante.

Mostrar el nombre y promedio de cada uno.*/



#include <iostream>
#include <string>
#include<fstream>
#include <iomanip>
using namespace std;
//Enumeraciones

struct tEstudiante
{ string nombre;
    int nota1, nota2, nota3;
    float promedio;
   
};


//Funciones protitipo


//Variables globales


int main(){
const int MAX_ESTUDIANTES = 100;
     tEstudiante estudiante[MAX_ESTUDIANTES];
    int cantidad = 0;

    //Abrir archivo cargar a la memoria
    ifstream archivo("notas.txt");

    //Esta abierto?
    if (!archivo.is_open()){
  
       cerr << "Error no pudo abrirse el archivo"<< endl;
    }
 

    while (archivo < MAX_ESTUDIANTES)
    {
        /* code */
    }
    



    //llamada a las funciones


    // salida por consola


    //cerramos el archivo

archivo.close();


    return 0;
}