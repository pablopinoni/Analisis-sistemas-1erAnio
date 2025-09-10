#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


//Variables globales

const int Num_Max=90;

//Estructuras

struct Ficha {

string nombre;
string apellido;
string direccion;
int id;
bool asistencia;

};


struct Arreglo
{
   Ficha Fichero[Num_Max];
   int contador;
};

struct Contenedor{

    Arreglo listaFichas;
};

// Prototipo de Funciones 
void cargarFichas(Contenedor &c);
void mostrarFichero();
void guardarFichas(const Contenedor &c);


  int main(){

    Contenedor miContenedor;
    cargarFichas(miContenedor);


//Llamamos funcion esribir mostrarFichero
    guardarFichas(miContenedor);

    mostrarFichero(); 
return 0;
}



//Declaracion de funciones



void cargarFichas(Contenedor &c){

//Inicializanos contador 
   miContenedor.listaFichas.contador=0;
//Inicializamos carga
   miContenedor.listaFichas.Fichero[0].apellido="Belen";   
   miContenedor.listaFichas.Fichero[0].nombre="Maria";    
   miContenedor.listaFichas.Fichero[0].direccion="Grecia 1602";    
   miContenedor.listaFichas.Fichero[0].id=1;    
   miContenedor.listaFichas.Fichero[0].asistencia=0;   

//Incrementar contador
   miContenedor.listaFichas.contador++;

}
void guardarFichas(const Contenedor &c){

ofstream archivo("fichas.txt");

  if (!archivo){
     cerr << "error al abrir el archivo para escribir." << endl;
     return ;
    }

//Aca se eescriben las fichas

//Recorrer fichas
for (int  i = 0; i < c.listaFichas.contador;i++)
{
    archivo << "Apellido: " << c.listaFichas.Fichero[i].apellido << endl;;
    archivo << "Nombre: " << c.listaFichas.Fichero[i].nombre << endl; 
    archivo << "Dirección: " << c.listaFichas.Fichero[i].direccion << endl;
    archivo << "ID: " << c.listaFichas.Fichero[i].id<< endl ;
    archivo << "Asistencia: " << c.listaFichas.Fichero[i].asistencia<< endl;
    archivo << endl;
}

}   
void mostrarFichero(){
    ifstream archivo("fichas.txt"); //Abrimos el archivo

    if(!archivo) {cerr << "error al abrir el archivo para escribir." << endl;
     return ;
     }
string linea;
while (getline(archivo, linea)){ //lee cda lineahasta el final del archivo
    cout << linea << endl;//muestar cada linea leída
}
archivo.close(); // cerramos el archivo
}
