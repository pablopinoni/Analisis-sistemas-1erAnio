/*Un archivo de texto contiene información acerca de los productos que se venden en un
almacén. Lo único que se sabe acerca del número de productos es que no puede superar
un cierto valor MaxProductos. De cada producto se guarda información sobre su código
identificador (entero positivo), su precio (real) y el número de unidades existentes (entero
positivo). El formato en el que se guarda la información dentro del archivo es el siguiente:
id1 precio1 unidades1
id2 precio2 unidades2
...
idN precioN unidadesN
‐1
a) Declara un tipo tProducto que represente la información de un producto y
un tipo tLista que mantenga la información de todos los productos.
b) Escribe un subprograma que lea los datos del archivo de texto que almacena
la información, los guarde en la lista y luego los muestre en la pantalla.
c) Escribe un subprograma que encuentre el producto con máximo valor en el
almacén, considerando que el valor del producto i es precioi*unidadesi.
d) Escribe un subprograma que dado un identificador de producto a eliminar
del almacén, lo busque en la lista y lo elimine actualizando la lista como
corresponda.*/ 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


//Variables globales
const int MaxProductos=21;

const string archivo= "stock.txt";

typedef struct {
    int id[MaxProductos];
    float precio[MaxProductos];
    int unidades[MaxProductos];
    }tProducto;

typedef struct {
    tProducto productos[MaxProductos];
    int contador;
}tLista;
//Prototipo de la función
void leerDatosDesdeArchivo(tLista& lista);
void mostarProductos(const tLista& Lista);
int encotrarIdMaximoValor(const tLista& Lista);

int main (){
  tLista Stock;
  Stock.contador=0;
  leerDatosDesdeArchivo(Stock);

  encotrarIdMaximoValor(Stock);
  cout << "El producto con máximo valor en el stock es" << endl;

    return 0;
}
//Implementar Funciones
void leerDatosDesdeArchivo(tLista& Lista){

    ifstream inputFile(archivo);
    if (!inputFile.is_open())
    {
        cout << "No se pudo abrir el archivo." << endl;
      return;  
    }
     int tempId, tempUnidades;
    double tempPrecio; // Usamos double para la lectura del precio

    lista.contador = 0;

    while (lista.contador < MaxProductos && inputFile >> tempId && tempId != -1) {
        inputFile >> tempPrecio >> tempUnidades;
        lista.productos[lista.contador].id = tempId;
        lista.productos[lista.contador].precio = tempPrecio;
        lista.productos[lista.contador].unidades = tempUnidades;
        lista.contador++;
    }

    inputFile.close();
    cout << "Archivo '" << archivo << "' leido con exito. Productos cargados: " << lista.contador << endl;
}
void mostarProductos(const tLista& Lista){
if(Lista.co)
for (size_t i = 0; i < count; i++)
{
    /* code */
}

 }
   
int encotrarIdMaximoValor(const tLista& Lista){
float maxValue[MaxProductos][MaxProductos];
float posicion[MaxProductos][MaxProductos];


}