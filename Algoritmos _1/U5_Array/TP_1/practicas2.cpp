#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAXIMO=20;
const string file="inventario.txt";

struct tProducto{
int cod;
string nombre;
float precioUnitario;
int stock;
};

struct tInventario{
tProducto productos[MAXIMO];
int contador;
};

//Protipo de Funciones
void loadFromFile(tInventario& inventario);
void mostarproductos(const tInventario& inventario);
int searchProductByCode(const tInventario& inventario, int cod);

int main() {
    tInventario InventarioJulio;
    InventarioJulio.contador=0;

   loadFromFile(InventarioJulio);
   mostarproductos(InventarioJulio);
   int codABuscar;
   cout << "Ingrese numero de producto a buscar: ";
   cin >> codABuscar;
   int indiceEncontrado= searchProductByCode(InventarioJulio, codABuscar); 
 if (indiceEncontrado==-1){
    cout <<"Código" << codABuscar <<" no encontrado" << endl;
 }
 else{
    cout << "=== Producto encontrado === " << endl;
    cout << "Código: " << InventarioJulio.productos[indiceEncontrado].cod << endl;
    cout << "Nombre: " << InventarioJulio.productos[indiceEncontrado].nombre << endl;
    cout << "Precio: " << InventarioJulio.productos[indiceEncontrado].precioUnitario << endl;
    cout << "Stock: " << InventarioJulio.productos[indiceEncontrado].stock << endl;

 }
return 0;
}

//Implementación de las funciones
void loadFromFile(tInventario& inventario){
 ifstream inputFile(file);
  if (!inputFile.is_open())
  {
    cout << "No se pudo abrir el archivo" << endl;
    return;
  }
  //Variables locales temporales
  int tempCod;
  string tempNombre;
  float tempPrecio;
  int tempStock;
   inventario.contador=0;
 

  while (inventario.contador < MAXIMO &&  (inputFile>> tempCod)) 
  {   
    if (tempCod==-1)
    {
        break;
    }
    
    inputFile >> tempNombre >> tempPrecio >> tempStock;
    inventario.productos[inventario.contador].cod=tempCod;
    inventario.productos[inventario.contador].nombre=tempNombre;
    inventario.productos[inventario.contador].precioUnitario=tempPrecio;
    inventario.productos[inventario.contador].stock=tempStock;
  
    inventario.contador ++;
    
}
  
inputFile.close();
cout << "Carga de productos finalizada." << endl;
}
void mostarproductos(const tInventario& inventario){

if (inventario.contador==0)
{cout << "La inventario no contien elementos cargados" << endl;
    return;
}
else
{
   cout << "\n=== Lista de Productos ===\n \n"
        << left  << setw(8) <<  "Cod"
        << left  << setw(20) <<  "Nombre"
        << right << setw(12) << "$ Unitario" 
        << right << setw(8) << "Stock"<< endl;   
      cout  << "___________________________________________________" << endl;
for (int i = 0; i <inventario.contador; i++)
{
  //Acceso a posiscion i
  cout << left  << setw(8) <<inventario.productos[i].cod;
  cout << left  << setw(20) << inventario.productos[i].nombre ;
  cout << right << setw(12) << fixed << setprecision(2) << inventario.productos[i].precioUnitario;
  cout << right << setw(8) << inventario.productos[i].stock<< endl;
}

cout << "__________________________________________________" << endl;
cout << "El total de productos es: " << inventario.contador << ".-" << endl;
}
}


int searchProductByCode(const tInventario& inventario, int codigoBuscado){
if (inventario.contador==0)
{
 cout << "No se encontraron elementos en la lista." << endl;
 return -1;
}

for (int i = 0; i < inventario.contador; i++)
{


if (inventario.productos[i].cod == codigoBuscado){


return i;}
}
cout << "Código no encontrado" << endl;
return -1;
}
