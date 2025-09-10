#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

const string archivo="invitados.txt";
const int MAX_ELEMENTOS = 90;
typedef int tArray[MAX_ELEMENTOS];

// estructura con 6 campos para cada invitado
typedef struct {
    string codigo;
    string nombre;
    string apellido;
    int dni;
    string celular;
    bool asistenciaConfirmada;
} tInintnvitado;

// Array + contador
typedef struct {
    tInvitado invitados[MAX_ELEMENTOS];
    int contador;
} tLista;

typedef struct {
    tLista ListaClub54;
} tContenedor;

// Funciones 
void clearConsole();
int showMenu();// Return int opcion
int submenuListado();
void guardarLista(const tContenedor &Contenedor);
void cargarDesdeArchivo(tContenedor &Contenedor);
void cargarInvitados(tContenedor &Contenedor);
void listarInvitados(const tContenedor &Contenedor);//No se modifica el archivo
void modificarInvitado(tContenedor &Contenedor, int ticketAModificar );
void eliminarInvitado(tContenedor &Contenedor);
void buscarInvitadoPorNumTicket(const tContenedor &Contenedor, int ticketBuscado );

int main() {
    tContenedor ListaClub54;
    clearConsole();
    cargarDesdeArchivo(ListaClub54);

    cout << "\n_____________________________\n"
         << "\n||======== CLUB 54 ========||" << endl;
    cout << "\n_____________________________\n";

    int opcion;
    do {
        opcion = showMenu();
        switch (opcion) {
            case 1:
                cargarInvitados(ListaClub54);
                break;
            case 2:
                eliminarInvitado(ListaClub54); // revisar 
               break;
            case 3:
                // modificarInvitado(ListaClub54);
                 if (ListaClub54.ListaClub54.contador == 0) {
                    cout << "La lista de invitados está vacía. No hay nadie para buscar.\n";
                    break; // Exit this case
                }
                //Obtener el numero de ticketde invitado  a buscar
                int ticketAModificar;
                cout << "Ingrese el Número de Ticket de invitado a modificar: ";
                
                // Validar entrada de num ticket
                while (!(cin >> ticketAModificar) || ticketAModificar <= 0) {
                    cin.clear();
                    //hacer limnpieza de buffer
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Número inválido. Ingrese un número de ticket válido (>0): ";
                }
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline from the buffer

                // Ahora sí s ellama a la funcion
              modificarInvitado(ListaClub54, ticketAModificar);
               
                break;
            case 4:
                listarInvitados(ListaClub54);
                break;
            case 5:{ 
                if (ListaClub54.ListaClub54.contador == 0) {
                    cout << "La lista de invitados está vacía. No hay nadie para buscar.\n";
                    break; // Exit this case
                }
                //Obtener el numero de ticket a buscar
                int ticketBuscado;
                cout << "Ingrese el Número de Ticket a buscar: ";
                
                // Validar entrada de num ticket
                while (!(cin >> ticketBuscado) || ticketBuscado <= 0) {
                    cin.clear();
                    //hacer limnpieza de buffer
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Número inválido. Ingrese un número de ticket válido (>0): ";
                }
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                // Ahora sí s ellama a la funcion
                buscarInvitadoPorNumTicket(ListaClub54, ticketBuscado);
                break;
            } 
               
                break;
            case 6:
                guardarLista(ListaClub54);// REvisar
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}



//=========Declaración de Funciones=============//

//Función
int showMenu() {  //Agregar validacion
    int opcion;
    cout << "\n===== MENÚ PRINCIPAL =====\n"
         << "1. Alta (Agregar invitado)\n"
         << "2. Baja (Eliminar invitado)\n"
         << "3. Modificar datos\n"
         << "4. Listar invitados(Opciones)\n"
         << "5. Buscar por código\n"
         << "6. Salir\n"
         << "Opción: ";

    while (!(cin >> opcion) || opcion < 1 || opcion > 6) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Opción inválida. Ingrese un número del 1 al 6: ";
   }

    return opcion;
}

//Función Guarda Lista
void guardarLista(const tContenedor &Contenedor) {
    // CORRECCIÓN CLAVE: Abrir el archivo usando la constante global.
    // También es buena práctica darle un nombre distinto a la variable local del stream
    // para evitar confusiones con la constante global si ambas se llamaran 'archivo'.
    ofstream outputFile(archivo);

    // Ahora, verifica si 'outputFile' se abrió correctamente.
    if (outputFile.is_open()) {
        for (int i = 0; i < Contenedor.ListaClub54.contador; ++i) {
            const tInvitado &inv = Contenedor.ListaClub54.invitados[i];
            outputFile << inv.numTicket << ","
                          << inv.nombre << ","
                          << inv.apellido << ","
                          << inv.dni << ","
                          << inv.celular << ","
                          << (inv.asistenciaConfirmada ? "1" : "0") << endl;
        }
        outputFile.close();
        // Mejorar el mensaje para que use la constante también
        cout << "Lista de invitados guardada en '" << archivo << "'" << endl;
    } else {
        // Mejorar el mensaje de error para que use la constante
        cerr << "Error: No se pudo abrir el archivo para escritura: '" << archivo << "'" << endl;
    }
}


//Función Cargar lista de invitados
void cargarInvitados(tContenedor &Contenedor) {
    if (Contenedor.ListaClub54.contador < MAX_ELEMENTOS) {
        tInvitado &nuevo = Contenedor.ListaClub54.invitados[Contenedor.ListaClub54.contador];
        cout << "Ingrese número de Ticket: ";
         while (!(cin >> nuevo.numTicket) || nuevo.numTicket <= 0) {
         cin.clear();
         cin.ignore(1000, '\n');
         cout << "Número inválido. Ingrese un número de ticket válido (>0): ";
            }
        cin.ignore(1000, '\n');

        cout << "Ingrese nombre: ";
        getline(cin, nuevo.nombre);

        cout << "Ingrese apellido: ";
        getline(cin, nuevo.apellido);

        cout << "Ingrese DNI: ";
          while (!(cin >> nuevo.dni) || nuevo.dni <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "DNI inválido. Intente de nuevo: ";
            }
        cin.ignore(1000, '\n');

        cout << "Ingrese celular: ";
        getline(cin, nuevo.celular);

        int confirmacion;
    cout << "Estado de Asistencia (1 = SI, 0 = NO): ";
       while (!(cin >> confirmacion) || (confirmacion != 0 && confirmacion != 1)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Valor inválido. Ingrese 1 (Sí) o 0 (No): ";
          }
        nuevo.asistenciaConfirmada = (confirmacion == 1);
       cin.ignore(1000, '\n');


        cout << "\nSe registró el nuevo ingreso.\n";
        Contenedor.ListaClub54.contador++;
    } else {
        cout << "No entran más invitados (límite alcanzado)." << endl;
    }
}
//Función cargar desde archivo
void cargarDesdeArchivo(tContenedor &Contenedor) {
    ifstream localFile(archivo);
    if (!localFile.is_open()) {
        cout << "Archivo 'invitados.txt' no encontrado. Se iniciará una lista vacía." << endl;
        Contenedor.ListaClub54.contador = 0;
        return;
    }

    tInvitado invitado;
    Contenedor.ListaClub54.contador = 0;

    while (localFile >> invitado.numTicket) {
        localFile.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        getline(localFile, invitado.nombre, ',');
        getline(localFile, invitado.apellido, ',');
       localFile >> invitado.dni;
        localFile.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        getline(localFile, invitado.celular, ',');
        int confirmacion;
        localFile >> confirmacion;
        invitado.asistenciaConfirmada = (confirmacion == 1);
        localFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (Contenedor.ListaClub54.contador < MAX_ELEMENTOS) {
            Contenedor.ListaClub54.invitados[Contenedor.ListaClub54.contador] = invitado;
            Contenedor.ListaClub54.contador++;
        }
    }
    localFile.close();
}


//Función Listar invitados
void listarInvitados(const tContenedor &Contenedor) {
    if (Contenedor.ListaClub54.contador == 0) {
        cout << "No hay invitados cargados.\n";
        return;
    }

    int opcion=submenuListado();
    
  

    cout << "\n==== LISTA DE INVITADOS ====" << endl;
    bool encontrado = false;
    int total = 0;

    for (int i = 0; i < Contenedor.ListaClub54.contador; ++i) {
        const tInvitado &inv = Contenedor.ListaClub54.invitados[i];

        if ((opcion == 1) ||
            (opcion == 2 && inv.asistenciaConfirmada) ||
            (opcion == 3 && !inv.asistenciaConfirmada)) {

            cout << "Ticket #" << inv.numTicket << "\n";
            cout << "Nombre: " << inv.nombre << " " << inv.apellido << "\n";
            cout << "DNI: " << inv.dni << "\n";
            cout << "Celular: " << inv.celular << "\n";
            cout << "Asistencia: " << (inv.asistenciaConfirmada ? "Confirmada" : "No confirmada") << "\n";
            cout << "--------------------------\n";
            encontrado = true;
            total++;
        }
    }

    if (!encontrado) {
        cout << "No hay invitados que coincidan con ese criterio.\n";
    } else {
        cout << "Total mostrados: " << total << endl;
    }
}



//Submenú Listado
int submenuListado(){
int opcion;
cout << "\n=== SUBMENÚ LISTADO ===\n"
         << "1. Todos los invitados\n"
         << "2. Confirmaron asistencia\n"
         << "3. NO confirmaron asistencia\n"
         << "Opción: ";

   while (!(cin >> opcion) || opcion < 1 || opcion > 3) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Opción inválida. Ingrese un número del 1 al 3: ";
   }

    return opcion;
}



void eliminarInvitado(tContenedor &Contenedor) {
    // 1. Verificar si la lista está vacía
    if (Contenedor.ListaClub54.contador == 0) {
        cout << "La lista de invitados está vacía. No hay nadie para eliminar.\n";
        return; // Salir de la función si no hay invitados
    }

    int numTicketABorrar;
    cout << "Ingrese el Número de Ticket del invitado a eliminar: ";

    // 2. Validación de entrada para el número de ticket
    while (!(cin >> numTicketABorrar) || numTicketABorrar <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia el buffer
        cout << "Número de ticket inválido. Ingrese un número positivo: ";
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia el buffer después de la lectura numérica exitosa

    int indexEncontrado = -1;

    // 3. Buscar el invitado por su número de ticket
    for (int i = 0; i < Contenedor.ListaClub54.contador; i++) {
        if (Contenedor.ListaClub54.invitados[i].numTicket == numTicketABorrar) {
            indexEncontrado = i; // Guarda la posición del invitado
            break;               // Sale del bucle una vez que lo encuentra
        }
    }

    // 4. Procesar el resultado de la búsqueda
    if (indexEncontrado != -1) {
        // Invitado encontrado: Desplazar elementos para "eliminar"
        for (int i = indexEncontrado; i < Contenedor.ListaClub54.contador - 1; i++) {
            Contenedor.ListaClub54.invitados[i] = Contenedor.ListaClub54.invitados[i + 1];
        }
        // Disminuir el contador, ya que un elemento fue eliminado
        Contenedor.ListaClub54.contador--;
        cout << "Invitado con Ticket #" << numTicketABorrar << " eliminado con éxito!\n";
    } else {
        // Invitado no encontrado
        cout << "Invitado con Ticket #" << numTicketABorrar << " no encontrado.\n";
    }
}


void buscarInvitadoPorNumTicket(const tContenedor &Contenedor, int ticketBuscado){
if (Contenedor.ListaClub54.contador == 0) {
        cout << "La lista de invitados está vacía. No hay nadie para buscar.\n";
        return; // Exit the function
    }

   for (int i = 0; i < Contenedor.ListaClub54.contador; ++i) {

         
        const tInvitado& inv = Contenedor.ListaClub54.invitados[i];
        //Comparamos el ticket actual con el buscado
        if (inv.numTicket == ticketBuscado){
                cout  << "\n\n== Datos del invitado ===" << "\n"
                      << "Número de Ticket: " << inv.numTicket << "\n"
                      << "Nombre: " << inv.nombre << "\n"
                      << "Apellido: " << inv.apellido << "\n"
                      << "Celular: " << inv.celular << "\n" 
                      << "DNI: " << inv.dni << "\n"
                      << "Asistencia: " << (inv.asistenciaConfirmada ? "Confirmada" : "No confirmada") << "\n"
                      << "--------------------------------------\n";
       return;

         
        }
    }
   cout << "Invitado con Ticket #" << ticketBuscado << " no encontrado.\n";
}

void modificarInvitado(tContenedor &Contenedor, int ticketAModificar) {
    
    // Esto es útil para mostrar un mensaje si el ticket no existe.
    bool encontrado = false; 
  // Recorremos la lista de invitados.
    for (int i = 0; i < Contenedor.ListaClub54.contador; ++i) {
        // *** ERROR CORREGIDO: Aquí usábamos 'localInv' que no existía.
        // Ahora comparamos el 'numTicket' del invitado actual con 'ticketAModificar'.
        if (Contenedor.ListaClub54.invitados[i].numTicket == ticketAModificar) {
            cout << "Invitado encontrado. Ingrese los nuevos datos:\n";

            cout << "Nuevo nombre: ";
            cin >> Contenedor.ListaClub54.invitados[i].nombre;

            cout << "Nuevo apellido: ";
            cin >> Contenedor.ListaClub54.invitados[i].apellido;

            cout << "Nuevo celular: ";
            cin >> Contenedor.ListaClub54.invitados[i].celular;

            
            int confirmacion;
            cout << "¿Asistencia confirmada? (0= No ,  = Si): ";
            cin >> confirmacion;
            Contenedor.ListaClub54.invitados[i].asistenciaConfirmada = (confirmacion != 0);
           
            cout << "Cliente modificado exitosamente.\n";
            encontrado = true; // Marcamos que el invitado fue encontrado y modificado
            return; 
        }
    }

    // Si el loop termina y 'encontrado' sigue siendo 'false', significa que no se encontró el ticket.
    if (!encontrado) {
        cout << "No se encontró ningún invitado con el número de ticket " << ticketAModificar << ".\n";
    }
}





//Función
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
