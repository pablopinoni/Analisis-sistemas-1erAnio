#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Variables Globales
const int MAX_CLIENTES  = 150;
const int MAX_PRODUCTOS = 250;
const string archivoArticulos = "articulos.csv";
const string archivoCliebntes = "clientes.csv";

//Estructura para articulos 3 campos
typedef struct {
  int codigo;
  int stock;
  float precio;
} tArrayArticulos;
//Articulos estructura + contador de articulos
typedef struct {
  tArrayArticulos Articulos[MAX_PRODUCTOS];
  int contadorArticulos;
} tStructArticulos;

//Estructura Cliente 4 campos + struct con articulos anidados
typedef struct {
  string codigo;
  string apellido;
  string nombre;
  string direccion;
  tStructArticulos productos;
} tCliente;

//Lista con estructura cliente + contador
typedef struct {
  tCliente Clientes[MAX_CLIENTES];
  int contador;
} tLista;

/*Agregar otra estructura  encapsuladora?

typedef struct{

    tLista PedidoXCliente;
    int fecha de entrega;
}tContenedor;*/


//Prototipo de funciones
void clearConsole();
void showMainMenu();


int main() {
  tLista ListaCloroGab;
  ListaCloroGab.contador = 0;

  cout << "====CLORO GAB====\n";

  return 0;
}
