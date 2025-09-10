/*A tal fin deberemos generar una Aplicación que permita:
1. Gestionar la Lista de Invitados, la misma deberá contener los Datos Personales de los
mismos.
2. Además, deberemos saber si confirmo o no la asistencia a la Fiesta.
3. El sistema podrá agregar, borrar o cambiar datos personales.
4. Realizar un listado de asistentes por pantalla*/

#include <iostream>
#include <string>
#include <fstream>//Lectura y escritura de archivos
using namespace std;


//VAriables globales
  const int MAX_ELEMENTOS = 90; // Tamaño máximo del array o capacidad del salon
  typedef int tArray [MAX_ELEMENTOS];
  



// estructura con 6 campos para cada invitado
  typedef struct {
    int numTicket;
    string nombre;
    string apellido;
    int dni;
    string celular;
    bool asistenciaConfirmada;
    
}tInvitado;



// Array + contador
typedef struct {

     tInvitado invitados[MAX_ELEMENTOS]; // Array de estructuras
    int contador; // Contador de elementos actuales
}tLista;

//Crear Contenedor Lista Estructura annidada

typedef struct
{ tLista ListaClub54;
 
}tContenedor;

//Funciones auxilares
void clearConsole();
void mostarMenu();
void listaVacia();




      ////////Funciones////////
void guardarLista(const tContenedor &Contenedor);

void cargarDesdeArchivo(tContenedor &tContenedor);
//  Insercion de asistentes 
void cargarInvitados( tContenedor &Contenedor);
int showMenu();
//cerrar lista
void listarInvitados(const tContenedor &Contenedor);
//Asistencia confirmada
bool asistenciaConfirmada( tContenedor &Contenedor);// recorer lista buscando numT y cambia el true en campo 

//Cancelar Asistencia
bool cancelarAsistencia(tContenedor &Contenedor);//pareametros idem Asistencia confirmada

//Preguntar estado de asistencia

bool estadoDeAsistencia(tContenedor &Contenedor);//parametros idem Asistencia confirmada





//El sistema podrá agregar, borrar o cambiar datos personales.



//Realizar un listado de asistentes por pantalla*/
//Un asistente
//Todos los asistentes

int main (){

     tContenedor ListaClub54;

     clearConsole();

//carga el archivo
cargarDesdeArchivo(ListaClub54);
//procesamos
//cargarInvitados(ListaClub54);


//mostarMenu();
//operar
   cout << "\n_____________________________\n"
        << "\n||======== CLUB 54 ========||" << endl;
   cout  << "\n_____________________________\n";

    int opcion;
       do {
          opcion = showMenu();

          switch (opcion) {
            case 1:
                cargarInvitados(ListaClub54);
                break;
            case 2:
                // eliminarInvitado(listaClub54); // aún no definida
                break;
            case 3:
                // modificarInvitado(listaClub54); // aún no definida
                break;
            case 4:
                listarInvitados(ListaClub54); // aún no definida
                break;
            case 5:
                // buscarInvitadoPorCodigo(listaClub54); // aún no definida
                break;
            case 6:
                guardarLista(ListaClub54);
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 6);


//persistencia

//guardarLista(ListaClub54);






return 0;

}

//Funciones

//Mostar Menu
int showMenu() {
    int opcion;
    cout << "\n===== MENÚ PRINCIPAL =====\n"
         << "1. Alta (Agregar invitado)\n"
         << "2. Baja (Eliminar invitado)\n"
         << "3. Modificar datos\n"
         << "4. Listar invitados\n"
         << "5. Buscar por código\n"
         << "6. Salir\n"
         << "Opción: ";
    cin >> opcion;
    return opcion;
}



//1-Guardar lista
void guardarLista(const tContenedor &Contenedor) {
    ofstream archivo("invitados.txt"); // Crea o reemplaza el archivo
    if (archivo.is_open()) {
        for (int i = 0; i < Contenedor.ListaClub54.contador; ++i) {
            const tInvitado &inv = Contenedor.ListaClub54.invitados[i];
            archivo << inv.numTicket << ","
                    << inv.nombre << ","
                    << inv.apellido << ","
                    << inv.dni << ","
                    << inv.celular << ","
                    << (inv.asistenciaConfirmada ? "1" : "0") << endl;//  if reducido
        }
        archivo.close();
        cout << "Lista de invitados guardada en 'invitados.txt'" << endl;
    } else {
        cerr << " No se pudo abrir el archivo para escritura." << endl;
    }
}


//2- Cargar invitados
void cargarInvitados( tContenedor &Contenedor){
    if (Contenedor.ListaClub54.contador<MAX_ELEMENTOS){ /// Acá me quedé crear estructura nueva
   tInvitado &nuevo = Contenedor.ListaClub54.invitados[Contenedor.ListaClub54.contador];//ESTUDIAR BIEN ESTO!!!!!!!!
    cout << "Ingrese número de Ticket: ";
        cin >> nuevo.numTicket;
        cin.ignore();

        cout << "Ingrese nombre: ";
        getline (cin, nuevo.nombre);
        
        cout << "Ingrese apellido: ";
        getline (cin, nuevo.apellido);

        cout << "Ingrese DNI: ";
        cin >> nuevo.dni;
        cin.ignore();

        cout << "Ingrese celular: ";
        getline (cin, nuevo.celular);

        cout << "Estado de Asistencia(1=SI, 0=no): ";
        int confirmacion;
        cin >> confirmacion;
        nuevo.asistenciaConfirmada = (confirmacion==1); // Por defecto
        cout << "\nSe registró el nuevo ingreso.\n";

        Contenedor.ListaClub54.contador++; // control control 
    } else {
        cout << "No entran más invitados (límite alcanzado)." << endl;
    }
    
     
     }
    
  
      void cargarDesdeArchivo(tContenedor &Contenedor) {
    ifstream archivo("invitados.txt");
    if (!archivo.is_open()) {
        cout << "Archivo 'invitados.txt' no encontrado. Se iniciará una lista vacía." << endl;
        Contenedor.ListaClub54.contador = 0;
        return;
    }

    tInvitado invitado;
    Contenedor.ListaClub54.contador = 0;

    while (archivo >> invitado.numTicket) {
        archivo.ignore(); // salta la coma
        getline(archivo, invitado.nombre, ',');
        getline(archivo, invitado.apellido, ',');
        archivo >> invitado.dni;
        archivo.ignore(); // salta la coma
        getline(archivo, invitado.celular, ',');
        int confirmacion;
        archivo >> confirmacion;
        invitado.asistenciaConfirmada = (confirmacion == 1);
        archivo.ignore(); // salta el salto de línea

        if (Contenedor.ListaClub54.contador < MAX_ELEMENTOS) {
            Contenedor.ListaClub54.invitados[Contenedor.ListaClub54.contador] = invitado;
            Contenedor.ListaClub54.contador++;
        }
      
       }
      }

void listarInvitados(const tContenedor &Contenedor) {
    if (Contenedor.ListaClub54.contador == 0) {
        cout << "No hay invitados cargados.\n";
        return;
    }

    cout << "\n==== LISTA DE INVITADOS ====\n";
    for (int i = 0; i < Contenedor.ListaClub54.contador; ++i) {
        const tInvitado &inv = Contenedor.ListaClub54.invitados[i];
        cout << "Ticket #" << inv.numTicket << "\n";
        cout << "Nombre: " << inv.nombre << " " << inv.apellido << "\n";
        cout << "DNI: " << inv.dni << "\n";
        cout << "Celular: " << inv.celular << "\n";
        cout << "Asistencia: " << (inv.asistenciaConfirmada ? "Confirmada" : "No confirmada") << "\n";
        cout << "--------------------------\n";
    }
}



///DEclaracion Fucniones auxiliares

void clearConsole() {
  #ifdef _WIN32
      system("cls");
  #else
      system("clear"); //Mac o Linux
  #endif
  }
/*void listaVacia(){
  if (is_empty(ListaClub54)) {return;
}*/