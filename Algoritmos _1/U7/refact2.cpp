#include <iostream>
#include <string>
#include <fstream> // Necesario para stringstream, para parsear líneas del CSV
#include <limits>
#include <sstream>
using namespace std;

// Variables globales
const int MAX_ELEMENTOS = 90; 
const string file = "clientes_nic_tech.csv";

// Estructura para cada cliente
typedef struct
{
    int codigo;
    string nombre;
    string direccion; 
    string celular;
} tCliente;

// Array + contador
typedef struct
{
    tCliente clientes[MAX_ELEMENTOS]; 
    int contador;                     
} tLista;

//Contenedor
typedef struct
{
    tLista ListaNicTech;
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
        return Contenedor.ListaNicTech.contador == 0;
    }


// Prototipo de funciones de salida por consola
int showMenu();
void showCaratula();

// Declaraciones de Funciones principales
void guardarLista(const tContenedor &Contenedor);
void cargarDesdeArchivo(tContenedor &Contenedor);
void altaClientes(tContenedor &Contenedor); // Inserción de clientes
void listarClientes(const tContenedor &Contenedor);
void eliminarCliente(tContenedor &Contenedor);
void searchClientesByCode(const tContenedor &Contenedor, int codigoBuscado);
void modificarClientes(tContenedor &Contenedor, int clienteAModificar);

////////////////////////////////////MAIN////////////////////////////////
int main()
{
    tContenedor NicTech;

    NicTech.ListaNicTech.contador = 0; // Inicializamos el contador de la lista principal
    clearConsole();
    cargarDesdeArchivo(NicTech);
    showCaratula();

    int opcion;
    do
    {
        opcion = showMenu();

        switch (opcion)
        {
        case 1: 
            cout << "\n==Alta Cliente==:\n";
            altaClientes(NicTech);
            break;
        case 2:
            cout << "\n==Baja Cliente= =\n";
            eliminarCliente(NicTech); 
           
            break;
        case 3:
                cout << "\n==Modificar cliente==\n";
                 if (emptyList(NicTech)) {
                    cout << "La lista de clientes está vacía. No hay nadie para buscar.\n";
                    break; 
                }
                //Obtener el numero de clienteAde clientes  a buscar
                int clienteAModificar;
                cout << "Ingrese el Número de 6 de clientes a modificar: ";
                
                // Validar entrada de num clienteA
                while (!(cin >> clienteAModificar) || clienteAModificar <= 0) {
                    cin.clear();
                    //hacer limnpieza de buffer
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Número inválido. Ingrese un número de clienteA válido (>0): ";
                }
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

                // Se llama a la funcion
              modificarClientes(NicTech, clienteAModificar);
               
            break;
        case 4:
            listarClientes(NicTech);
            break;
        case 5:
          cout << "==Buscar clientes por código==\n";
          int codigoBuscado;
          cout << "Ingrese el Número de cliente de clientes a modificar: ";
                
                // Validar entrada 
                while (!(cin >> codigoBuscado) || codigoBuscado<= 0) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Número inválido. Ingrese un número de cliente válido (>0): ";
                }
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

               
            searchClientesByCode(NicTech,codigoBuscado); 
            
            break;
        case 6:
            guardarLista(NicTech);
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
         << "\n\n        //***** NIC TECH  *****//                      \n"
         << "___________________________________________________\n\n"
         << endl;
}

int showMenu()
{
    int opcion;
    cout << "\n===== MENÚ PRINCIPAL =====\n"
         << "1. Alta (Agregar clientes)\n"
         << "2. Baja (Eliminar clientes)\n"
         << "3. Modificar datos\n"
         << "4. Listar clientes\n"
         << "5. Buscar por código\n"

         << "6. Salir\n"
         << "Opción: ";
    cin >> opcion;
     while (opcion <1 || opcion>6) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Número inválido. Ingrese un número de opción válido (>0): ";
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
        for (int i = 0; i < Contenedor.ListaNicTech.contador; ++i)
        {
            const tCliente &clienteActual = Contenedor.ListaNicTech.clientes[i];
            archivo << clienteActual.codigo << ","
                    << clienteActual.nombre << ","
                    << clienteActual.direccion << ","
                    << clienteActual.celular << "\n"; 
        }
        archivo.close();
        cout << "Lista de clientes guardada en " << file << endl;
    }
    else
    {
        cerr << " No se pudo abrir el archivo para escritura." << endl;
    }
}

// Cargar clientes (Función de alta manual)
void altaClientes(tContenedor &Contenedor)
{
    if (Contenedor.ListaNicTech.contador < MAX_ELEMENTOS)
    {
        tCliente &nuevo = Contenedor.ListaNicTech.clientes[Contenedor.ListaNicTech.contador];

        nuevo.codigo= (Contenedor.ListaNicTech.contador) + 100;//Código generado automaticamente 
        
        cout << "\n------------------------------------\n";
        cout << "Ingrese nombre completo: ";
        getline(cin, nuevo.nombre);

        cout << "Ingrese Dirección : ";
        getline(cin, nuevo.direccion); 

        cout << "Ingrese celular: ";
        getline(cin, nuevo.celular); // Usar getline para leer el celular

        cout << "\nSe registró el ingreso de un nuevo cliente.\n";
        cout << "\n------------------------------------\n";
        Contenedor.ListaNicTech.contador++;
    }
    else
    {
        cout << "No se pueden agregar más clientes (límite de salón alcanzado)." << endl;
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
        Contenedor.ListaNicTech.contador = 0;
        return;
    }

    tCliente tempCliente;
    Contenedor.ListaNicTech.contador = 0;

    while (localFile >> tempCliente.codigo)
    {
        localFile.ignore(numeric_limits<streamsize>::max(), ',');
        getline(localFile, tempCliente.nombre, ',');
        getline(localFile, tempCliente.direccion, ',');
        getline(localFile, tempCliente.celular);

        if (Contenedor.ListaNicTech.contador < MAX_ELEMENTOS)
        {
            Contenedor.ListaNicTech.clientes[Contenedor.ListaNicTech.contador] = tempCliente;
            Contenedor.ListaNicTech.contador++;
        }
    }
    localFile.close();
}
void listarClientes(const tContenedor &Contenedor)
{
    if (emptyList(Contenedor))
    { // Usamos la función emptyList que acabamos de corregir
        cout << "No hay clientes cargados para mostrar.\n";
        return;
    }

    cout << "\n==== LISTA DE CLIENTES  ====\n";
    for (int i = 0; i < Contenedor.ListaNicTech.contador; ++i)
    {
        const tCliente &clienteActual = Contenedor.ListaNicTech.clientes[i];
        cout << "Código: " << clienteActual.codigo << "\n";
        cout << "Nombre: " << clienteActual.nombre << "\n";
        cout << "Dirección: " << clienteActual.direccion << "\n";
        cout << "Celular: " << clienteActual.celular << "\n";
        cout << "--------------------------\n";
    }
}
void eliminarCliente(tContenedor &Contenedor)
{
    // 1. Verificar si la lista está vacía
    if (emptyList(Contenedor))
    {
        cout << "La lista de clientes está vacía. No hay nadie para eliminar.\n";
        return; 
    }

    int numClienteBorrar;
    cout << "Ingrese el Código del cliente a eliminar: ";

    // 2. Validación de entrada para el Código
    while (!(cin >> numClienteBorrar) || numClienteBorrar <= 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "Código clienálido. Ingrese un número positivo: ";
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    int indexEncontrado = -1;

    // 3. Buscar el cliente por su Código
    for (int i = 0; i < Contenedor.ListaNicTech.contador; i++)
    {
        if (Contenedor.ListaNicTech.clientes[i].codigo == numClienteBorrar)
        {
            indexEncontrado = i; 
            break;               
        }
    }

    
    if (indexEncontrado != -1) {
        
        for (int i = indexEncontrado; i < Contenedor.ListaNicTech.contador - 1; i++) {
            Contenedor.ListaNicTech.clientes[i] = Contenedor.ListaNicTech.clientes[i + 1];
        }
       
        Contenedor.ListaNicTech.contador--;
        cout << "clientes con Código #" << numClienteBorrar << " eliminado con éxito!\n";
    } else {
        // clientes no encontrado
        cout << "clientes con Código #" << numClienteBorrar << " no encontrado.\n";
    }
    guardarLista(Contenedor);//Mejor prevenir que curar
        cout << "\nLista acualizada." << endl;

}

void searchClientesByCode (const tContenedor &Contenedor, int codigoBuscado){
   if (Contenedor.ListaNicTech.contador == 0) {
        cout << "La lista de clientes está vacía. No hay nadie para buscar.\n";
        return; // Exit the function
    }

   for (int i = 0; i < Contenedor.ListaNicTech.contador; ++i) {

         
        const tCliente& clien = Contenedor.ListaNicTech.clientes[i];
        //Comparamos el codigo actual con el buscado
        if (clien.codigo == codigoBuscado){
                cout  << "\n\n== Datos del cliente ===" << "\n"
                      << "Número de codigo: " << clien.codigo << "\n"
                      << "Nombre: " << clien.nombre << "\n"
                      
                      << "Celular: " << clien.celular << "\n" 
                      << "Direccion: " << clien.direccion << "\n"
                      << "--------------------------------------\n";
       return;

         
        }
    }
   cout << "cliente con codigo #" << codigoBuscado << " no encontrado.\n";
}

void modificarClientes(tContenedor &Contenedor, int clienteAModificar) {
    
    
    bool encontrado = false; 
  // Recorremos la lista de clientes.
    for (int i = 0; i < Contenedor.ListaNicTech.contador; ++i) {
        
        if (Contenedor.ListaNicTech.clientes[i].codigo == clienteAModificar) {
            cout << "Cliente encontrado. Ingrese los nuevos datos:\n";

            cout << "Nuevo nombre: ";
            getline(cin, Contenedor.ListaNicTech.clientes[i].nombre);

            cout << "Nueva Dirección: ";
            getline(cin,  Contenedor.ListaNicTech.clientes[i].direccion);

            cout << "Nuevo celular: ";
            getline(cin,  Contenedor.ListaNicTech.clientes[i].celular);

            
           
            cout << "Cliente modificado exitosamente.\n";
            encontrado = true; 
            return; 
        }
    }
    guardarLista(Contenedor);
    

    // Si el loop termina y 'encontrado' sigue siendo 'false', avisamos el usuario 
    if (!encontrado) {
        cout << "No se encontró ningún cliente con el número de codigo " << clienteAModificar << ".\n";
    }
}
