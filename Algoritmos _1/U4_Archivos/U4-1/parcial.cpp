#include <iostream>
#include <string>
#include <fstream>     
#include <limits>      
#include <sstream>     

using namespace std;

// Variables globales
const int MAX_ELEMENTOS = 90;
const string file = "solicitudes_beauty_sand.csv";
const int CODIGO_INICIAL=500;
// Estructura para cada solicitud
typedef struct
{
    string codigo;
    string nombre;
    string apellido;
    int montoAPagar;
} tSolicitud;

// Array + contador
typedef struct
{
    tSolicitud solicitudes[MAX_ELEMENTOS];
    int contador;
} tLista;

// Contenedor
typedef struct
{
    tLista ListaBeauty;
} tContenedor;

// Funciones auxiliares
void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear"); // Mac o Linux
#endif
}

bool emptyList(const tContenedor &Contenedor)
{
    return Contenedor.ListaBeauty.contador == 0;
}

// Prototipo de funciones de salida por consola
int showMenu();
void showCaratula();

// Declaraciones de Funciones principales
void guardarLista(const tContenedor &Contenedor);
void cargarDesdeArchivo(tContenedor &Contenedor);
void altaSolicitudes(tContenedor &Contenedor); 
void listarSolicitudes(const tContenedor &Contenedor);
void eliminarSolicitud(tContenedor &Contenedor);
void searchSolicitudesByCode(const tContenedor &Contenedor, string codigoBuscado); 
void modificarSolicitudes(tContenedor &Contenedor, string solicitudAModificar);   

////////////////////////////////////MAIN////////////////////////////////
int main()
{
    tContenedor Beauty;

    Beauty.ListaBeauty.contador = 0; 
    clearConsole();
    cargarDesdeArchivo(Beauty);
    showCaratula();

    int opcion;
    string solicitudAModificar;
    string codigoBuscado;

    do
    {
        opcion = showMenu();

        switch (opcion)
        {
        case 1:
          cout << "\n==Alta solicitud==:\n";
            altaSolicitudes(Beauty);
            break;
        case 2:
            cout << "\n==Baja solicitud==\n";
            eliminarSolicitud(Beauty);
            break;
        case 3:
            cout << "\n==Modificar solicitud==\n";
            if (emptyList(Beauty))
            {
                cout << "La lista de solicitudes está vacía. No hay nadie para modificar.\n";
                break;
            }
            cout << "Ingrese el Codigo de solicitud a modificar: ";
            getline(cin, solicitudAModificar); // Ahora solo asigna, no declara
            modificarSolicitudes(Beauty, solicitudAModificar);
            break;
        case 4:
            listarSolicitudes(Beauty);
            break;
        case 5:
            cout << "==Buscar solicitudes por código==\n";
            cout << "Ingrese el Codigo de solicitud a buscar: ";
            getline(cin, codigoBuscado); // Ahora solo asigna, no declara
            searchSolicitudesByCode(Beauty, codigoBuscado);
            break;
        case 6:
            guardarLista(Beauty);
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}

// Implementación de Funciones
void showCaratula()
{
    cout << "___________________________________________________\n"
         << "\n\n        //***** Beauty  *****//                      \n"
         << "___________________________________________________\n\n"
         << endl;
}

int showMenu()
{
    int opcion;
    cout << "\n===== MENÚ PRINCIPAL =====\n"
         << "1. Alta (Agregar solicitudes)\n"
         << "2. Baja (Eliminar solicitudes)\n"
         << "3. Modificar datos\n"
         << "4. Listar solicitudes\n"
         << "5. Buscar por código\n"
         << "6. Salir\n"
         << "Opción: ";
    cin >> opcion;
    // Validar entrada del menú
    while (opcion < 1 || opcion > 6)
    {
        cin.clear();                                         // Limpiar el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
        cout << "Opción inválida. Ingrese un número de opción válido (1-6): ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer después de leer la opción
    return opcion;
}

// Guardar lista
void guardarLista(const tContenedor &Contenedor)
{
    ofstream archivo(file); // Crea o reemplaza el archivo
    if (archivo.is_open())
    {
        for (int i = 0; i < Contenedor.ListaBeauty.contador; ++i)
        {
            const tSolicitud &solicitudActual = Contenedor.ListaBeauty.solicitudes[i];
            archivo << solicitudActual.codigo << ","
                    << solicitudActual.nombre << ","
                    << solicitudActual.apellido << ","
                    << solicitudActual.montoAPagar << "\n";
        }
        archivo.close();
        cout << "Lista de solicitudes guardada en " << file << endl;
    }
    else
    {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
    }
}

// Cargar solicitudes (Función de alta manual)
void altaSolicitudes(tContenedor &Contenedor)
{
    if (Contenedor.ListaBeauty.contador < MAX_ELEMENTOS)
    {
        tSolicitud &nuevo = Contenedor.ListaBeauty.solicitudes[Contenedor.ListaBeauty.contador];

        // Código generado automáticamente (convertido a string)
        nuevo.codigo = "BT-" + to_string(Contenedor.ListaBeauty.contador + CODIGO_INICIAL);

        cout << "\n------------------------------------\n";
        cout << "Ingrese nombre completo: ";
        getline(cin, nuevo.nombre);

        cout << "Ingrese Dirección : ";
        getline(cin, nuevo.apellido);

        cout << "Ingrese montoAPagar: ";
        cin >> nuevo.montoAPagar;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nSe registró el ingreso de un nuevo solicitud.\n";
        cout << "\n------------------------------------\n";
        Contenedor.ListaBeauty.contador++;
    }
    else
    {
        cout << "No se pueden agregar más solicitudes (límite de salón alcanzado)." << endl;
    }
    guardarLista(Contenedor); // Aseguramos guardar los cambios
    cout << "\nLista acualizada." << endl;
}

// Cargar lista desde archivo
void cargarDesdeArchivo(tContenedor &Contenedor)
{
    ifstream localFile(file);
    if (!localFile.is_open())
    {
        cout << "Archivo " << file << " no encontrado. Se iniciará una lista vacía." << endl;
        Contenedor.ListaBeauty.contador = 0;
        return;
    }

    tSolicitud tempsolicitud;
    Contenedor.ListaBeauty.contador = 0;
    string line;

    while (getline(localFile, line)) // Leer la línea completa
    {
        stringstream ss(line); // Usar stringstream para parsear la línea
        string segment;

        // Leer código
        if (getline(ss, segment, ','))
        {
            tempsolicitud.codigo = segment;
        }
        // Leer nombre
        if (getline(ss, segment, ','))
        {
            tempsolicitud.nombre = segment;
        }
        // Leer dirección
        if (getline(ss, segment, ','))
        {
            tempsolicitud.apellido = segment;
        }
       //Leer montoAPagar (hasta el final de la línea)
        if (getline(ss, segment)){
        
            tempsolicitud.montoAPagar = stoi(segment);
        }
            
        

        if (Contenedor.ListaBeauty.contador < MAX_ELEMENTOS)
        {
            Contenedor.ListaBeauty.solicitudes[Contenedor.ListaBeauty.contador] = tempsolicitud;
            Contenedor.ListaBeauty.contador++;
        }
    }
    localFile.close();
}

void listarSolicitudes(const tContenedor &Contenedor)
{
    if (emptyList(Contenedor))
    { // Usamos la función emptyList
        cout << "No hay solicitudes cargados para mostrar.\n";
        return;
    }

    cout << "\n==== LISTA DE SOLICITUDES  ====\n";
    for (int i = 0; i < Contenedor.ListaBeauty.contador; ++i)
    {
        const tSolicitud &solicitudActual = Contenedor.ListaBeauty.solicitudes[i];
        cout << "Código: " << solicitudActual.codigo << "\n";
        cout << "Nombre: " << solicitudActual.nombre << "\n";
        cout << "Dirección: " << solicitudActual.apellido << "\n";
        cout << "montoAPagar: " << solicitudActual.montoAPagar << "\n";
        cout << "--------------------------\n";
    }
}

void eliminarSolicitud(tContenedor &Contenedor)
{
    // 1. Verificar si la lista está vacía
    if (emptyList(Contenedor))
    {
        cout << "La lista de solicitudes está vacía. No hay nadie para eliminar.\n";
        return;
    }

    string codigosolicitudBorrar; // Cambiado a string
    cout << "Ingrese el Código del solicitud a eliminar: ";
    getline(cin, codigosolicitudBorrar); // Leer como string

    int indexEncontrado = -1;

    // 2. Buscar el solicitud por su Código
    for (int i = 0; i < Contenedor.ListaBeauty.contador; i++)
    {
        if (Contenedor.ListaBeauty.solicitudes[i].codigo == codigosolicitudBorrar) // Comparar strings
        {
            indexEncontrado = i;
            break;
        }
    }

    if (indexEncontrado != -1)
    {
        // Mover los elementos restantes para llenar el espacio
        for (int i = indexEncontrado; i < Contenedor.ListaBeauty.contador - 1; i++)
        {
            Contenedor.ListaBeauty.solicitudes[i] = Contenedor.ListaBeauty.solicitudes[i + 1];
        }
        Contenedor.ListaBeauty.contador--;
        cout << "solicitud con Código " << codigosolicitudBorrar << " eliminado con éxito!\n";
    }
    else
    {
        // solicitud no encontrado
        cout << "solicitud con Código " << codigosolicitudBorrar << " no encontrado.\n";
    }
    guardarLista(Contenedor); // Guardar los cambios
    cout << "\nLista actualizada." << endl;
}

void searchSolicitudesByCode(const tContenedor &Contenedor, string codigoBuscado) // Cambiado a string
{
    if (Contenedor.ListaBeauty.contador == 0)
    {
        cout << "La lista de solicitudes está vacía. No hay nadie para buscar.\n";
        return; // Salir de la función
    }

    bool encontrado = false;
    for (int i = 0; i < Contenedor.ListaBeauty.contador; ++i)
    {
        const tSolicitud &clien = Contenedor.ListaBeauty.solicitudes[i];
        // Comparamos el codigo actual con el buscado (comparación de strings)
        if (clien.codigo == codigoBuscado)
        {
            cout << "\n\n== Datos del solicitud ==="
                 << "\n"
                 << "Codigo: " << clien.codigo << "\n"
                 << "Nombre: " << clien.nombre << "\n"
                 << "Apellido: " << clien.apellido << "\n"
                 << "montoAPagar: " << clien.montoAPagar << "\n"
                 << "--------------------------------------\n";
            encontrado = true;
            return; // solicitud encontrado, salimos de la función
        }
    }
    if (!encontrado)
    {
        cout << "Solicitud con codigo " << codigoBuscado << " no encontrado.\n";
        cout << "------------------\n";
    }
}

void modificarSolicitudes(tContenedor &Contenedor, string solicitudAModificar) // Cambiado a string
{
    bool encontrado = false;
    // Recorremos la lista de solicitudes.
    for (int i = 0; i < Contenedor.ListaBeauty.contador; ++i)
    {
        if (Contenedor.ListaBeauty.solicitudes[i].codigo == solicitudAModificar) // Comparar strings
        {
            cout << "solicitud encontrado. Ingrese los nuevos datos:\n";

            cout << "Nuevo nombre: ";
            getline(cin, Contenedor.ListaBeauty.solicitudes[i].nombre);

            cout << "Nueva Dirección: ";
            getline(cin, Contenedor.ListaBeauty.solicitudes[i].apellido);

            cout << "Nuevo montoAPagar: ";
            cin >> Contenedor.ListaBeauty.solicitudes[i].montoAPagar;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "solicitud modificado exitosamente.\n";
            encontrado = true;
            guardarLista(Contenedor); // Guardar los cambios inmediatamente
            cout << "\nLista actualizada." << endl;
            return;
        }
    }

    // Si el loop termina y 'encontrado' sigue siendo 'false', avisamos al usuario
    if (!encontrado)
    {
        cout << "No se encontró ningún solicitud con el Codigo " << solicitudAModificar << ".\n";
    }
}
