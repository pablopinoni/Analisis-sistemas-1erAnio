// Introducción a TDA C++ INTEREFACES Y OCULTAMIENTO
// Array con muchos struct y menu para manejarla
//Ejemplo TDA con Valorers,Funciones (Interfaces), Ocultamiento

/* Ahora Tenemos:

Refactoring 0: Abstraccion 
Refactoring 1: Modularización 
Refactoring 2: Encapsulamiento 
Refactoring 3: Agregamos ocultamiento x visibilidad

*/
#include <iostream>
#include <string>
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

// Inicio Estructura alumnos
// TDA = Valores + Comportamiento (Abstraccion, Modularidad, Encapsulamiento y Ocultamiento)
//********************************************************
struct alumnos
{
  tipoDatos VFicheros[100] ;
  int tope ;

// Observen los 3 Niveles de Alcance de la Visibilidad (fijate al final te lo explico)

protected:
    int protegido; // miembro protegido.

private:
    int privado ; // miembro privado.

public:
 
 //Defino la Interface Publica 
 void setPrivado(int a);
 int getPrivado();
 void ingresar();
 void mostrar();
 void interTDA();

};

//Fin Estructura alumnos
//********************************************************

//Implemento la Interface
// Proximamente veremos como ponerlo en otro Archivo
// Separando el Header (con un Include) (.h) de la Implementacion (.cpp)
//********************************************************

//Implemento la Interface
//********************************************************
void alumnos::setPrivado(int a) {privado = a;}
int alumnos::getPrivado( ) {return privado;}
void alumnos::mostrar()
{ 
    setPrivado(33) ;
    cout << "Muestro la Implementacion de la Interface, la edad de Cristo:" << getPrivado() << endl; 

}

void alumnos::interTDA() 
        { 
              cout << "Te ejecuto la Interface del TDA" << endl; 
        }

void alumnos::ingresar()
        {
             //cout << "numero fichas: " << numeroFichas;
             cout << "Introduce el nombre: ";
             cin >> VFicheros[tope].nombre;
             cout << "Introduce la edad: ";
             cin >> VFicheros[tope].edad;
             //cout << "Nombre: " << VFicheros[tope].nombre << "  edad:" << VFicheros[tope].edad ;
             tope++;  // Y tenemos una ficha más
            
        }
//Fin Implementación de la Interface
//********************************************************



int main()
{
    //tipoDatos *fichas = new tipoDatos[1000];
    alumnos salumnos;
    salumnos.tope=0;
    salumnos.privado = 0 ;

    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo Alumno" << endl;
        cout << "2.- Mostrar los Atributos Privados" << endl;
        cout << "3.- Mostrar Interfaz TDA" << endl;
        cout << "4.- Ver datos de un fichero" << endl;
        cout << "5.- Salir" << endl << endl;
        cin >> opcion;

        // Hacemos una cosa u otra según la opción escogida
        switch(opcion)
        {
            case 1: // Añadir un dato nuevo
                if (salumnos.tope < 100)   // Si queda hueco
                {
                   salumnos.ingresar();
                   //salumnos.tope++;  // Muevo el Tope
                }
                else   // Si no hay hueco para más fichas, avisamos
                    cout << "Máximo de fichas alcanzado (100)!" << endl;
                break;

            case 2: // Mostrar todos
              
                salumnos.mostrar();  
                break;

            case 3: // Mostrar Interfaz TDA
               salumnos.interTDA();
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

/*
1. Público: Todos los miembros de la clase declarados bajo el especificador público 
estarán disponibles para todos. Los miembros de datos y las funciones de miembros 
declarados como públicos también pueden ser accedidos por otras clases y funciones. 
Se puede acceder a los miembros públicos de una clase desde cualquier lugar del 
programa utilizando el operador de acceso directo de miembros (.)

2. Privado: Los miembros de la clase declarados como privados solo pueden ser 
accedidos por las funciones miembro dentro de la clase. No se permite que ningún 
objeto o función ajena a la clase acceda directamente a ellos. Solo las funciones 
de miembro o las funciones de amigo pueden acceder a los miembros de datos privados 
de una clase.

3. Protegido: el modificador de acceso protegido es similar al modificador de acceso 
privado en el sentido de que no se puede acceder a él fuera de su clase a menos que 
con la ayuda de la clase amigo, la diferencia es que los miembros de la clase declarados 
como Protegidos pueden ser accedidos por cualquier subclase (clase derivada) de esa 
clase también.

*/




