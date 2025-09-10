#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAXIMO=10;
const string file="notas.txt";

struct tEstudiante{
int numLegajo;
float notaFinal;
bool aprobado;
};

struct tLista{
tEstudiante estudiantes[MAXIMO];
int contador;
};

//Protipo de Funciones
void loadFromFile(tLista& lista);
void mostarEstudiantes(const tLista& lista);
int contarAprobados(const tLista& lista);

int main() {
    tLista Notas1ero;
    Notas1ero.contador=0;

   loadFromFile(Notas1ero);
   mostarEstudiantes(Notas1ero);
   contarAprobados(Notas1ero);
  cout <<"El total de aprobados es: " << contarAprobados(Notas1ero) <<endl;
return 0;
}

//Implementación de las funciones
void loadFromFile(tLista& lista){
 ifstream inputFile(file);
  if (!inputFile.is_open())
  {
    cout << "No se pudo abrir el archivo" << endl;
    return;
  }
  //Variables locales temporales
  int tempLegajo;
  float tempNota;
  bool tempAprobado;
   lista.contador=0;

  while (lista.contador < MAXIMO && inputFile >> tempLegajo && tempLegajo!= -1) 
  { inputFile >> tempNota >> tempAprobado;
    lista.estudiantes[lista.contador].numLegajo=tempLegajo;
    lista.estudiantes[lista.contador].notaFinal=tempNota;
    lista.estudiantes[lista.contador].aprobado=tempAprobado;
  
    lista.contador ++;
}
  
inputFile.close();
}
void mostarEstudiantes(const tLista& lista){

if (lista.contador==0)
{cout << "La lista no contien elementos cargados" << endl;
    return;
}
else
{
   cout << "\n=== Lista de Etudiantes ===\n \n";
   cout << "Legajo\tNota\tAprobado \n"       
        << "________________________________" << endl;
for (int i = 0; i <lista.contador; i++)
{
  //Acceso a posiscion i
  cout << lista.estudiantes[i].numLegajo << "\t";
  cout << fixed << setprecision(2) << lista.estudiantes[i].notaFinal << "\t";
  cout << lista.estudiantes[i].aprobado << endl;
}

cout << "________________________________" << endl;
cout << "El total de estudiantes es: " << lista.contador << ".-" << endl;
}
}

int contarAprobados(const tLista& lista){
int cantAprobados=0;
for (int i = 0; i < lista.contador; i++)
{ if (lista.estudiantes[i].aprobado==0)

  cantAprobados++;
}

  return cantAprobados;
}
 
void clea
#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

