#include <iostream>
#include <string>
#include <fstream> // Necesario para stringstream, para parsear líneas del CSV
#include <limits>
#include <sstream>
using namespace std;

// Variables globales
const int MAX_ELEMENTOS = 90; 
const string file = "solicitudes_beauty.csv";

// Estructura para cada solicitud
typedef struct
{
    string id;
    string nombre;
    string direccion; 
    int montoAPagar;
} tsolicitud;

// Array + contador
typedef struct
{
    tsolicitud solicitudes[MAX_ELEMENTOS]; 
    int contador;                     
} tLista;

//Contenedor
typedef struct
{
    tLista ListaBeauty;
} tContenedor;

//Funciones auxiliares (ahora las definí entes del main)
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
void altaSolicitudes(tContenedor &Contenedor); // Inserción de solicitudes
void listarSolicitudes(const tContenedor &Contenedor);
void eliminarSolicitud(tContenedor &Contenedor);
void searchSolicitudesByCode(const tContenedor &Contenedor, string idBuscado);
void modificarSolicitudes(tContenedor &Contenedor, string solicitudAModificar);

////////////////////////////////////MAIN////////////////////////////////
int main()
{
    tContenedor Beauty;

    Beauty.ListaBeauty.contador = 0; // Inicializamos el contador de la lista principal
    clearConsole();
    cargarDesdeArchivo(Beauty);
    showCaratula();

    int opcion;
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
                 if (emptyList(Beauty)) {
                    cout << "La lista de solicitudes está vacía. No hay nadie para buscar.\n";
                    break; 
                }
                //Obtener el numero de solicitudAde solicitudes  a buscar
                string solicitudAModificar;
                cout << "Ingrese el id de solicitud a modificar: ";
                getline(cin, solicitudAModificar);
                /* Validar entrada de num solicitudA
                while (!(cin >> solicitudAModificar) || solicitudAModificar <= 0) {
                    cin.clear();
                    //hacer limnpieza de buffer
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
                    cout << "id inválido. Ingrese un id de solicitud válido (>0): ";
                }
               

                // Se llama a la funcion
              modificarSolicitudes(Beauty, solicitudAModificar);
               
            break;
        case 4:
            S(Beauty);
            break;
        case 5:
          cout << "==Buscar solicitudes por código==\n";
          string idBuscado;
          cout << "Ingrese el id de solicitud de solicitudes a modificar: ";
                
                // Validar entrada 
               /* while (!(cin >> idBuscado) || idBuscado<= 0) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "id inválido. Ingrese un id de solicitud válido (>0): ";
                }*/
                getline(cin, idBuscado); 

               
            sS(Beauty,idBuscado); 
            
            break;
        case 6:
            guardarLista(Beauty);
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción clienálida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}

// Implementación de Funciones
void showCaratula()
{
    cout << "___________________________________________________\n"
         << "\n\n        //***** Beauty Sand  *****//                      \n"
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
     while (opcion <1 || opcion>6) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "id inválido. Ingrese un id de opción válido (>0): ";
                }
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    
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
            const tsolicitud &solicitudActual = Contenedor.ListaBeauty.solicitudes[i];
            archivo << solicitudActual.id << ","
                    << solicitudActual.nombre << ","
                    << solicitudActual.direccion << ","
                    << solicitudActual.montoApagar << "\n"; 
        }
        archivo.close();
        cout << "Lista de solicitudes guardada en " << file << endl;
    }
    else
    {
        cerr << " No se pudo abrir el archivo para escritura." << endl;
    }
}

// Cargar solicitudes (Función de alta manual)
void S(tContenedor &Contenedor)
{
    if (Contenedor.ListaBeauty.contador < MAX_ELEMENTOS)
    {
        tsolicitud &nuevo = Contenedor.ListaBeauty.solicitudes[Contenedor.ListaBeauty.contador];

        nuevo.id= (Contenedor.ListaBeauty.contador) + 100;//Código generado automaticamente 
        
        cout << "\n------------------------------------\n";
        cout << "Ingrese nombre completo: ";
        getline(cin, nuevo.nombre);

        cout << "Ingrese Dirección : ";
        getline(cin, nuevo.direccion); 

        cout << "Ingrese montoApagar: ";
        getline(cin, nuevo.montoApagar); // Usar getline para leer el montoApagar

        cout << "\nSe registró el ingreso de un nuevo solicitud.\n";
        cout << "\n------------------------------------\n";
        Contenedor.ListaBeauty.contador++;
    }
    else
    {
        cout << "No se pueden agregar más solicitudes (límite de salón alcanzado)." << endl;
    }
    guardarLista(Contenedor); //Aseguramos guardar los cambios 
    cout << "\nLista acualizada." << endl;
}

// Cargar lista desde archivo
void cargarDesdeArchivo(tContenedor &Contenedor)
{
    ifstream localFile(file);
    if (!localFile.is_open())
    {
        cout << "Archivo " << file << "no encontrado. Se iniciará una lista vacía." << endl;
        Contenedor.ListaBeauty.contador = 0;
        return;
    }

    tsolicitud tempsolicitud;
    Contenedor.ListaBeauty.contador = 0;

    while (localFile >> tempsolicitud.id)
    {
        localFile.ignore(numeric_limits<streamsize>::max(), ',');
        getline(localFile, tempsolicitud.nombre, ',');
        getline(localFile, tempsolicitud.direccion, ',');
        getline(localFile, tempsolicitud.montoApagar);

        if (Contenedor.ListaBeauty.contador < MAX_ELEMENTOS)
        {
            Contenedor.ListaBeauty.solicitudes[Contenedor.ListaBeauty.contador] = tempsolicitud;
            Contenedor.ListaBeauty.contador++;
        }
    }
    localFile.close();
}
void S(const tContenedor &Contenedor)
{
    if (emptyList(Contenedor))
    { // Usamos la función emptyList que acabamos de corregir
        cout << "No hay solicitudes cargados para mostrar.\n";
        return;
    }

    cout << "\n==== LISTA DE solicitudes  ====\n";
    for (int i = 0; i < Contenedor.ListaBeauty.contador; ++i)
    {
        const tsolicitud &solicitudActual = Contenedor.ListaBeauty.solicitudes[i];
        cout << "Código: " << solicitudActual.id << "\n";
        cout << "Nombre: " << solicitudActual.nombre << "\n";
        cout << "Dirección: " << solicitudActual.direccion << "\n";
        cout << "montoApagar: " << solicitudActual.montoApagar << "\n";
        cout << "--------------------------\n";
    }
}
void eliminarsolicitud(tContenedor &Contenedor)
{
    // 1. Verificar si la lista está vacía
    if (emptyList(Contenedor))
    {
        cout << "La lista de solicitudes está vacía. No hay nadie para eliminar.\n";
        return; 
    }

    int numsolicitudBorrar;
    cout << "Ingrese el Código del solicitud a eliminar: ";

    // 2. Validación de entrada para el Código
    while (!(cin >> numsolicitudBorrar) || numsolicitudBorrar <= 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "Código clienálido. Ingrese un id positivo: ";
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    int indexEncontrado = -1;

    // 3. Buscar el solicitud por su Código
    for (int i = 0; i < Contenedor.ListaBeauty.contador; i++)
    {
        if (Contenedor.ListaBeauty.solicitudes[i].id == numsolicitudBorrar)
        {
            indexEncontrado = i; 
            break;               
        }
    }

    
    if (indexEncontrado != -1) {
        
        for (int i = indexEncontrado; i < Contenedor.ListaBeauty.contador - 1; i++) {
            Contenedor.ListaBeauty.solicitudes[i] = Contenedor.ListaBeauty.solicitudes[i + 1];
        }
       
        Contenedor.ListaBeauty.contador--;
        cout << "solicitudes con Código #" << numsolicitudBorrar << " eliminado con éxito!\n";
    } else {
        // solicitudes no encontrado
        cout << "solicitudes con Código #" << numsolicitudBorrar << " no encontrado.\n";
    }
    guardarLista(Contenedor);//Mejor prevenir que curar
        cout << "\nLista acualizada." << endl;

}

void sS (const tContenedor &Contenedor, int idBuscado){
   if (Contenedor.ListaBeauty.contador == 0) {
        cout << "La lista de solicitudes está vacía. No hay nadie para buscar.\n";
        return; // Exit the function
    }

   for (int i = 0; i < Contenedor.ListaBeauty.contador; ++i) {

         
        const tsolicitud& clien = Contenedor.ListaBeauty.solicitudes[i];
        //Comparamos el id actual con el buscado
        if (clien.id == idBuscado){
                cout  << "\n\n== Datos del solicitud ===" << "\n"
                      << "id de id: " << clien.id << "\n"
                      << "Nombre: " << clien.nombre << "\n"
                      
                      << "montoApagar: " << clien.montoApagar << "\n" 
                      << "Direccion: " << clien.direccion << "\n"
                      << "--------------------------------------\n";
       return;

         
        }
    }
   cout << "solicitud con id #" << idBuscado << " no encontrado.\n";
}

void modificarsolicitudes(tContenedor &Contenedor, string solicitudAModificar) {
    
    
    bool encontrado = false; 
  // Recorremos la lista de solicitudes.
    for (int i = 0; i < Contenedor.ListaBeauty.contador; ++i) {
        
        if (Contenedor.ListaBeauty.solicitudes[i].id == solicitudAModificar) {
            cout << "solicitud encontrado. Ingrese los nuevos datos:\n";

            cout << "Nuevo nombre: ";
            getline(cin, Contenedor.ListaBeauty.solicitudes[i].nombre);

            cout << "Nueva Dirección: ";
            getline(cin,  Contenedor.ListaBeauty.solicitudes[i].direccion);

            cout << "Nuevo montoApagar: ";
            getline(cin,  Contenedor.ListaBeauty.solicitudes[i].montoApagar);

            
           
            cout << "solicitud modificado exitosamente.\n";
            encontrado = true; 
            return; 
        }
    }
    guardarLista(Contenedor);
    

    // Si el loop termina y 'encontrado' sigue siendo 'false', avisamos el usuario 
    if (!encontrado) {
        cout << "No se encontró ningún solicitud con el id de id " << solicitudAModificar << ".\n";
    }
}
