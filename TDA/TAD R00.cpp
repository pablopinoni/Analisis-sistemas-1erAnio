// Introducción a TDA C++
// Off-Topic Iteracion 00 "Punteros"
// TDA - Punteros Básico

#include <iostream>
#include <string>
#include <locale.h>
using namespace std;


int numeroFichas = 0;  // Número de fichas que ya tenemos
int i;               // Para bucles
int opcion;          // La opcion del menu que elija el usuario

string textoTemporal; // Para pedir datos al usuario
int numeroTemporal;

struct tipoDatos
{
    string nombre;        // Nombre del fichero
    long edad;             // El tamaño en bytes
  
};

struct alumnos
{
  tipoDatos VFicheros[100] ;
  int tope ;
};

//Define Prototipo de la Función
void ingresar();
void mostrar();

//Creo TDA salumnos con un "Puntero de Memoria"
// Keep Kalm And Continue Coding...
//esto lo vas a ver el Proximo Semestre....


alumnos *salumnos = new alumnos;
//alumnos salumnos;
//salumnos.tope=0;

 

int main()
{
    setlocale(LC_ALL, "");
    //alumnos *salumnos = new alumnos;
    //alumnos salumnos;
    salumnos->tope=0;
    //salumnos.AtributoPrivado = 0 ;

    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo Alumno" << endl;
        cout << "2.- Mostrar los nombres de todos los Alumnos" << endl;
        cout << "3.- Mostrar Alumnos que tengan mas de una cierta edad" << endl;
        cout << "4.- Ver datos de un fichero" << endl;
        cout << "5.- Salir" << endl << endl;
        cin >> opcion;

        // Hacemos una cosa u otra según la opción escogida
        switch(opcion)
        {
            case 1: // Añadir un dato nuevo
                if (salumnos->tope < 100)   // Si queda hueco
                {
                   ingresar();
                   //salumnos.tope++;  // Muevo el Tope
                }
                else   // Si no hay hueco para más fichas, avisamos
                    cout << "Máximo de fichas alcanzado (100)!" << endl;
                break;

            case 2: // Mostrar todos
              
                //llamo a la Funcion
                mostrar();  
                break;

            case 3: // Mostrar según el tamaño
               /* cout << "¿A partir de que tamaño quieres que te muestre? ";
                cin >> numeroTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].tamanyo >= numeroTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tamaño: " << fichas[i].tamanyo
                            << " Kb" << endl;*/
                break;

            case 4: // Ver todos los datos (pocos) de un fichero
               /* cout << "¿De qué fichero quieres ver todos los datos?";
                cin >> textoTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].nombreFich == textoTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tamaño: " << fichas[i].tamanyo
                            << " Kb" << endl;*/
                break;

            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;

            default: // Otra opcion: no válida
                cout << "Opción desconocida!" << endl;
                break;
        }
    } while (opcion != 5);  // Si la opcion es 5, terminamos

    return 0;
}

//Definicion de un comportamiento (Modularización)
  void ingresar()
        {
             //cout << "numero fichas: " << numeroFichas;
             cout << "Introduce el nombre: ";
             cin >> salumnos->VFicheros[salumnos->tope].nombre;
             cout << "Introduce la edad: ";
             cin >> salumnos->VFicheros[salumnos->tope].edad;
             //cout << "Nombre: " << VFicheros[tope].nombre << "  edad:" << VFicheros[tope].edad ;
             salumnos->tope++;  // Y tenemos una ficha más
            
        }
 void mostrar()
 {
    for (i=0; i<salumnos->tope; i++){
    cout << "i: " << i << " Nombre22: " << salumnos->VFicheros[i].nombre << "  Edad: " << salumnos->VFicheros[i].edad << endl;

 }
 }






