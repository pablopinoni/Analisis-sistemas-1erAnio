// Introducci�n a TDA C++
// Array con muchos struct y menu para manejarla
// ejemplo TDA con Valores y Funciones

#include <iostream>
#include <string>
using namespace std;


int i;               // Para bucles
int opcion;          // La opcion del menu que elija el usuario

string textoTemporal; // Para pedir datos al usuario
int numeroTemporal;

// Inicio Estructura tipoDatos
struct tipoDatos
{
    string nombre;        // Nombre del fichero
    long edad;             // El tama�o en bytes
  
};
// Fin Estructura tipoDatos

// Inicio Estructura alumnos
// TDA = Valores + Comportamiento
//********************************************************
struct alumnos
{
//Defino unos Valores que presentan un Estado 
  tipoDatos VFicheros[100] ;
  int tope ;

//Defino un comportamiento
  void ingresar()
        {
             //cout << "numero fichas: " << numeroFichas;
             cout << "Introduce el nombre: ";
             cin >> VFicheros[tope].nombre;
             cout << "Introduce la edad: ";
             cin >> VFicheros[tope].edad;
             //cout << "Nombre: " << VFicheros[tope].nombre << "  edad:" << VFicheros[tope].edad ;
             tope++;  // Y tenemos una ficha m�s
            
        }
 void mostrar()
 {
    for (i=0; i<tope; i++){
    cout << "i: " << i << " Nombre22: " << VFicheros[i].nombre << "  Edad: " << VFicheros[i].edad << endl;

 }
 }

};

//Fin Estructura alumnos
//********************************************************
 

int main()
{
    //tipoDatos *fichas = new tipoDatos[1000];
    alumnos salumnos;
    salumnos.tope=0;
    //salumnos.AtributoPrivado = 0 ;

    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opci�n:" << endl;
        cout << "1.- A�adir datos de un nuevo Alumno" << endl;
        cout << "2.- Mostrar los nombres de todos los ficheros" << endl;
        cout << "3.- Mostrar ficheros que sean de mas de un cierto tama�o" << endl;
        cout << "4.- Ver datos de un fichero" << endl;
        cout << "5.- Salir" << endl << endl;
        cin >> opcion;

        // Hacemos una cosa u otra seg�n la opci�n escogida
        switch(opcion)
        {
            case 1: // A�adir un dato nuevo
                if (salumnos.tope < 100)   // Si queda hueco
                {
                   salumnos.ingresar();
                   //salumnos.tope++;  // Muevo el Tope
                }
                else   // Si no hay hueco para m�s fichas, avisamos
                    cout << "M�ximo de fichas alcanzado (100)!" << endl;
                break;

            case 2: // Mostrar todos
              
                salumnos.mostrar();  
                break;

            case 3: // Mostrar seg�n el tama�o
               /* cout << "�A partir de que tama�o quieres que te muestre? ";
                cin >> numeroTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].tamanyo >= numeroTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tama�o: " << fichas[i].tamanyo
                            << " Kb" << endl;*/
                break;

            case 4: // Ver todos los datos (pocos) de un fichero
               /* cout << "�De qu� fichero quieres ver todos los datos?";
                cin >> textoTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].nombreFich == textoTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tama�o: " << fichas[i].tamanyo
                            << " Kb" << endl;*/
                break;

            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;

            default: // Otra opcion: no v�lida
                cout << "Opci�n desconocida!" << endl;
                break;
        }
    } while (opcion != 5);  // Si la opcion es 5, terminamos

    return 0;
}






