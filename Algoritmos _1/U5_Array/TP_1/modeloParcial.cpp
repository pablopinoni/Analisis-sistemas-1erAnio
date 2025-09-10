#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 10;

typedef int tArray[MAX_ELEMENTOS];

typedef struct 
{
    tArray elementos;
    int contador;
} tLista;

void mostrarLista(const tLista &lista);
void ordenarLista(tLista &lista);
int buscarElemento(const tLista &lista, int valor);
bool eliminarElemento(tLista &lista, int valor);
bool insertarOrdenado(tLista &lista, int valor);


int main() 
{
    tLista lista = {{5, 2, 8, 1, 9, 3, 7, 4, 6, 10}, MAX_ELEMENTOS};
    
    // 1. Mostrar lista desordenada.
    cout << "1. Lista desordenada:" << endl;
    mostrarLista(lista);
    
    // 2. Ordenar la lista.
    ordenarLista(lista);
    
    // 3. Mostrar lista ordenada.
    cout << "\n3. Lista ordenada:" << endl;
    mostrarLista(lista);
    
    // 4. Buscar un elemento
    int valorBuscar;
    cout << "\n4. Ingrese un valor a buscar: ";
    cin >> valorBuscar;
    
    int pos = buscarElemento(lista, valorBuscar);
    if (pos != -1) 
    {
        cout << "El valor " << valorBuscar << " se encuentra en la posicion " << pos << endl;
    } else 
    {
        cout << "El valor " << valorBuscar << " no se encuentra en la lista" << endl;
    }
    
    // 5. Eliminar un elemento
    int valorEliminar;
    cout << "\n5. Ingrese un valor a eliminar: ";
    cin >> valorEliminar;
    
    if (eliminarElemento(lista, valorEliminar)) 
    {
        cout << "Valor eliminado correctamente. Lista actualizada:" << endl;
        mostrarLista(lista);
    } else 
    {
        cout << "El valor no se encuentra en la lista" << endl;
    }
    
    // 6. Insertar un elemento manteniendo el orden
    int valorInsertar;
    cout << "\n6. Ingrese un valor a insertar: ";
    cin >> valorInsertar;
    
    if (insertarOrdenado(lista, valorInsertar)) 
    {
        cout << "Valor insertado correctamente. Lista actualizada:" << endl;
        mostrarLista(lista);
    } else 
    {
        cout << "No se pudo insertar el valor (lista llena)" << endl;
    }
    
    return 0;
}

// Función para mostrar la lista
void mostrarLista(const tLista &lista) 
{
    cout << "Lista: [";
    for (int i = 0; i < lista.contador; i++) 
    {
        cout << lista.elementos[i];
        if (i < lista.contador - 1) 
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Función para ordenar la lista (usando burbujeo)
void ordenarLista(tLista &lista) 
{
    for (int i = 0; i < lista.contador - 1; i++) 
    {
        for (int j = 0; j < lista.contador - i - 1; j++) 
        {
            if (lista.elementos[j] > lista.elementos[j + 1]) 
            {
                // Intercambiar elementos
                int temp = lista.elementos[j];
                lista.elementos[j] = lista.elementos[j + 1];
                lista.elementos[j + 1] = temp;
            }
        }
    }
}

// Función para buscar un elemento en la lista.
int buscarElemento(const tLista &lista, int valor) 
{
    for (int i = 0; i < lista.contador; i++) 
    {
        if (lista.elementos[i] == valor) 
        {
            return i; // Devuelve la posición si lo encuentra.
        }
    }
    return -1; // Devuelve -1 si no lo encuentra.
}

// Función para eliminar un elemento de la lista.
bool eliminarElemento(tLista &lista, int valor) 
{
    int pos = buscarElemento(lista, valor);
    if (pos == -1) 
    {
        return false; // Elemento no encontrado.
    }
    
    // Desplazar elementos hacia la izquierda.
    for (int i = pos; i < lista.contador - 1; i++) 
    {
        lista.elementos[i] = lista.elementos[i + 1];
    }
    lista.contador--;
    return true;
}

// Función para insertar un elemento manteniendo el orden.
bool insertarOrdenado(tLista &lista, int valor) 
{
    if (lista.contador == MAX_ELEMENTOS) 
    {
        return false; // Lista llena
    }
    
    int pos = 0;
    // Encontrar la posición correcta.
    while (pos < lista.contador && lista.elementos[pos] < valor) 
    {
        pos++;
    }
    
    // Desplazar elementos hacia la derecha.
    for (int i = lista.contador; i > pos; i--) 
    {
        lista.elementos[i] = lista.elementos[i - 1];
    }
    
    // Insertar el nuevo elemento.
    lista.elementos[pos] = valor;
    lista.contador++;
    return true;
}
