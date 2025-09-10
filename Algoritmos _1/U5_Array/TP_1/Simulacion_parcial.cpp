#include <iostream>   
#include <fstream>    
#include <string>     
#include <iomanip>    
#include <sstream>    
#include <limits>     
using namespace std;


// --- Constantes ---

const int MAXIMO = 110;
const string file = "clientes_nic_tech.csv";

// --- Estructuras (Structs) ---

struct tCliente {
    int cod;
    string nombre;
    string direccion;
     int celular;
};

struct tLista {
    tCliente clientes[MAXIMO];
    int contador;             
};

// --- Prototipos de Funciones (Declaraciones) ---

// Funciones Auxiliares 
void showCaratula();
void clearConsole();
void pauseConsole();
void showMenu();
bool listaVacia(const tLista& lista); 
void ordenarLista(tLista &lista);
// Funciones de sobre de Archivos
void createOrCheckFile();        
void loadClientesFromFile(tLista& lista);
void saveClientsToFile(tLista& lista);

// Funciones de Gestión de Clientes
void altaCliente(tLista& lista);
void bajaCliente(tLista& lista, int codBuscado);
void modificarData(tLista& lista, int codBuscado);
void buscarClientesXCod(tLista& lista, int codBuscado);
void listarClientes(const tLista& lista); 

// --- Función Principal (main) ---
int main() {
    clearConsole(); 
    tLista ListaNicTech; 
    ListaNicTech.contador = 0; 

    createOrCheckFile(); 
    loadClientesFromFile(ListaNicTech); 
    
    showCaratula();
    pauseConsole(); 

    int opcion; 

    do {
        clearConsole(); 
        showCaratula(); 
        showMenu();     
        
        cin >> opcion; 

        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, ingrese un número.\n"; 
            cin.clear(); 
            pauseConsole(); 
            continue; 
        }
        
        switch (opcion) 
        {
            case 1:
                cout <<"Opción 1: Alta Cliente" << endl;
                altaCliente(ListaNicTech);
                break;
            case 2: 
                cout <<"Opción 2: Baja Cliente" << endl;
                {
                    int cod;
                    cout << "Código del cliente a dar de baja: ";
                    cin >> cod;
                    if (cin.fail()) { 
                        cout << "Código inválido. Por favor, ingrese un número.\n";
                        cin.clear();
                    } else {
                        bajaCliente(ListaNicTech, cod);
                    }
                }
                break;
            case 3:
                cout <<"Opción 3: Modificar Cliente por código" << endl;
                {
                    int codigoBuscado;
                    cout << "Código del cliente a modificar: ";
                    cin >> codigoBuscado;
                    if (cin.fail()) { 
                        cout << "Código inválido. Por favor, ingrese un número.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        modificarData(ListaNicTech, codigoBuscado);
                    }
                }
                break;
            case 4:  
                cout <<"Opción 4: Lista de Clientes" << endl;
                listarClientes(ListaNicTech); 
                break;
            case 5: 
                cout <<"Opción 5: Buscar Cliente por código" << endl;
                {
                    int cod;
                    cout << "Código del cliente: ";
                    cin >> cod;
                    if (cin.fail()) { 
                        cout << "Código inválido. Por favor, ingrese un número.\n";
                        cin.clear();
                    } else {
                        buscarClientesXCod(ListaNicTech, cod); 
                    }
                }
                break;
            case 6: 
                cout << "Saliendo... ¡Hasta pronto!" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo.\n"; 
                break; 
        }

        if (opcion != 6) {
            pauseConsole();
        }

    } while (opcion != 6);

    return 0; 
}


// --- Implementación de Funciones ---

void clearConsole() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear"); 
#endif
}

void pauseConsole() {
   cout << "Presione Enter para continuar...\n"; 
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cin.get(); 
}


void showCaratula() {
    cout << "___________________________________________________\n"
         << "\n\n             //***** NIC TECH  *****//                           \n"
         << "___________________________________________________\n\n" << endl;
}

bool listaVacia(const tLista& lista) { 
    return lista.contador == 0; 
}

void createOrCheckFile() {
    ifstream inFile(file);

    if (inFile.good()) {
        cout << "El archivo '" << file << "' ya existe y se utilizará." << endl;
        inFile.close();
    } else {
        ofstream outFile(file);
        if (outFile.is_open()) {
            outFile << "Codigo,Nombre,Direccion,Celular" << endl; 
            outFile.close();
            cout << "El archivo '" << file << "' ha sido creado exitosamente con su cabecera." << endl;
        } else {
            cerr << "ERROR: No se pudo abrir o crear el archivo '" << file << "'." << endl;
        }
    }
}

void loadClientesFromFile(tLista &lista) {
    ifstream localFile(file); 

    if (!localFile.is_open()) {
        cout << "Advertencia: Archivo '" << file << "' no encontrado o no se pudo abrir. Se iniciará una lista de clientes vacía." << endl;
        return; 
    }

    string line;
    if (!getline(localFile, line)) {
        cout << "El archivo '" << file << "' está vacío o solo contiene la cabecera (no hay datos de clientes)." << endl;
        localFile.close();
        lista.contador = 0; 
        return;
    }

    lista.contador = 0;

    while (getline(localFile, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string segment;
        tCliente tempClient; 

        if (getline(ss, segment, ',')) {
    stringstream ss_cod(segment); // Creamos un stringstream para el segmento del código
    int temp_cod_val; // Variable temporal para almacenar el valor

    // Intentamos leer el entero del stringstream
    ss_cod >> temp_cod_val; 

    // Verificamos si la lectura falló (no se pudo leer un número)
    // o si quedaron caracteres no numéricos al final del segmento (ej. "123abc")
    if (ss_cod.fail() || !ss_cod.eof()) {
        cerr << "Error de formato (Código no válido): '" << line << "'. Saltando línea." << endl;
        continue; // Si hay un error, saltamos completamente esta línea del archivo y pasamos a la siguiente.
    }
    tempClient.cod = temp_cod_val; // Si la validación fue exitosa, asignamos el valor.
    }    
    else {
         cerr << "Error de formato: Código no encontrado en línea: '" << line << "'. Saltando línea." << endl;
        continue;
      }
        if (!getline(ss, tempClient.nombre, ',')) {
            cerr << "Error de formato: Nombre no encontrado en linea: '" << line << "'. Saltando linea." << endl;
            continue;
        }

        if (!getline(ss, tempClient.direccion, ',')) {
            cerr << "Error de formato: Direccion no encontrado en linea: '" << line << "'. Saltando linea." << endl;
            continue;
        }

        if (getline(ss, segment)) {
             stringstream    ssCEl(segment); // Creamos un ss del celular
            int tempCelVal; // Variable temp

    // Intentamos leer el entero del stringstream
    ssCEl >> tempCelVal;

    // Verificamos la lectura y los caracteres restantes
    if     (ssCEl.fail() ||     ssCEl.eof()) {
        cerr << "Error de formato (Celular no válido): '" << line << "'. Saltando línea." << endl;
        continue; // Si hay un error, saltamos esta línea.
    }
    tempClient.celular = tempCelVal; 
        } else {
            cerr << "Error de formato: Celular no encontrado en linea: '" << line << "'. Saltando linea." << endl;
            continue;
        }

        if (lista.contador < MAXIMO) {
            lista.clientes[lista.contador] = tempClient; 
            lista.contador++; 
        } else {
            cout << "Advertencia: Límite de clientes alcanzado (" << MAXIMO << "). No se cargaron más clientes desde el archivo." << endl;
            break; 
        }
    }

    localFile.close();
    cout << "Se cargaron " << lista.contador << " clientes desde el archivo '" << file << "'." << endl;
}

void showMenu() {
        cout << "\n_________________\n"
              <<" \n\n----- MENÚ -----\n"
              << "\n_________________\n\n"
              << "------------------\n"
              << "OPCIONES CLIENTES:\n"
              << "------------------\n"
              << "1. Alta\n"
              << "2. Baja\n"
              << "3. Modificar\n"
              << "4. Listar\n"
              << "5. Buscar por código\n"
              << "6. Salir\n"
              << "Opción: ";
}

void altaCliente(tLista& lista){
    clearConsole();

    if (lista.contador >=MAXIMO) { 
        cout << "No se pueden agregar más clientes.\n";
        return;
    }
    tCliente nuevoCliente;

    nuevoCliente.cod = (lista.contador > 0) ? lista.clientes[lista.contador - 1].cod + 1 : 100;
    cout << "Código asignado al nuevo cliente: " << nuevoCliente.cod << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    
    cout << "Nombre completo: ";
    getline(cin, nuevoCliente.nombre);
    cout << "Dirección: ";
    getline(cin, nuevoCliente.direccion);

    cout << "Celular: ";
    cin >> nuevoCliente.celular;

    if (cin.fail()) {
        cout << "Entrada inválida para el celular. Se asignará 0 por defecto." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        nuevoCliente.celular = 0;
    }

    lista.clientes[lista.contador] = nuevoCliente;
    lista.contador++;

    cout << "Cliente agregado correctamente.\n";
    ordenarLista(lista);
    saveClientsToFile(lista); 
}

void bajaCliente(tLista& lista, int codBuscado) {
    clearConsole();

    if (listaVacia(lista)) { 
        cout << "La lista de clientes está vacía. No hay clientes para dar de baja.\n";
        return;
    }
    
    int indiceEncontrado = -1;

    for (int i = 0; i < lista.contador; ++i) {
        if (lista.clientes[i].cod == codBuscado) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        cout << "Se encontró el cliente con Código: " << lista.clientes[indiceEncontrado].cod
            << ", Nombre: " << lista.clientes[indiceEncontrado].nombre << ".\n";

        cout << "¿Confirmar eliminación de este cliente? (s/n): ";
        char confirmacion;
        cin >> confirmacion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

      
        if (confirmacion == 's' || confirmacion == 'S') {
            
            lista.clientes[indiceEncontrado] = lista.clientes[lista.contador - 1];
            lista.contador--; 

            cout << "Cliente con código " << codBuscado << " eliminado correctamente.\n";
            ordenarLista(lista);
            saveClientsToFile(lista); 
        } else {
            cout << "Operación de eliminación cancelada.\n";
        }
    } else {
        cout << "Cliente con código " << codBuscado << " no encontrado.\n";
    }
}

void modificarData(tLista& lista, int codBuscado){
    clearConsole();
    cout << "===== Modificar Cliente por Código =====\n" << endl;
    if (listaVacia(lista)) { 
        cout << "La lista de clientes está vacía. No hay clientes modificar.\n"; 
        return;
    }

    cout << "Código a modificar: " << codBuscado << endl; 
    
    
    int indiceEncontrado = -1; 

    for (int i = 0; i < lista.contador; ++i) {
        if (lista.clientes[i].cod == codBuscado) {
            indiceEncontrado = i; 
            break; 
        }
    }

   
    if (indiceEncontrado != -1) {
         tCliente& c = lista.clientes[indiceEncontrado];

        cout << "\n=====Cliente encontrado - Datos ACtuales=====\n;";
        cout << "Código:    " << c.cod << "\n";
        cout << "Nombre:    " << c.nombre << "\n";
        cout << "Dirección: " << c.direccion << "\n";
        cout << "Celular:   " << c.celular << "\n";
        cout << "--------------------------\n";
     
     int campoAModificar;
        cout << "\n¿Qué campo desea modificar?\n";
        cout << "1. Nombre\n";
        cout << "2. Dirección\n";
        cout << "3. Celular\n";
        cout << "4. Cancelar modificación\n"; // Opción para no hacer cambios
        cout << "Opción: ";
     cin >> campoAModificar;
     
    if (cin.fail()) { 
        cout << "Por favor, ingrese un número válido.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return;     
    }cin.ignore(numeric_limits<streamsize>::max(), '\n');
         switch (campoAModificar)
         {
         case 1: 
            cout << "Ingrese nuevo Nombre completo:"; 
            getline(cin, c.nombre);
            cout << " Nombre y apellido modificados correctamente\n";
            break;
         
        case 2:
            cout <<"Ingrese nueva dirección:";
            getline(cin, c.direccion);
           cout << "Dirección modificada correctamente\n";
            break;
        case 3:
           cout << "Ingrese nuevo celular :";
           int nuevoCelular;
           cin >> nuevoCelular;
         if (cin.fail()) { 
        cout << "Por favor, ingrese un número válido.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
             }
         else{
            c.celular=nuevoCelular;
            cout << "Celular modificado correctamente\n";
         }
      
            break;

         case 4:
         cout << "Modificación cancelada\n\n";
         return;

         default:
            return;
         }
                    }
    
 else{
    cout << "No se ha encontrado un cliente que corresponda al código "
    << codBuscado << " ." << endl;
    return;
 }
    saveClientsToFile(lista);
}

void buscarClientesXCod(tLista& lista, int cod){
    clearConsole(); 
  
    if (listaVacia(lista)) { 
        cout << "La lista de clientes está vacía. No hay clientes para buscar.\n"; 
        return;
    }
    
    int indiceEncontrado = -1; 

    for (int i = 0; i < lista.contador; ++i) {
        if (lista.clientes[i].cod == cod) {
            indiceEncontrado = i; 
            break; 
        }
    }
    tCliente& c = lista.clientes[indiceEncontrado];
    if (indiceEncontrado != -1) {
        cout << "--- Detalles del Cliente ---\n";
        cout << "Código:    " << c.cod << "\n";
        cout << "Nombre:    " << c.nombre << "\n";
        cout << "Dirección: " << c.direccion << "\n";
        cout << "Celular:   " << c.celular << "\n";
        cout << "--------------------------\n";
    } else {
        cout << "Cliente con código " << cod << " no encontrado.\n";
    }
}

void listarClientes(const tLista& lista) {
    clearConsole();
    showCaratula();
    

    if (listaVacia(lista)) { 
        cout << "No hay clientes para mostrar en la lista.\n";
        return;
    }
    tLista tempL =  lista;
   ordenarLista(tempL);
    cout << "\n----- LISTA DE CLIENTES -----\n";
    cout << left << setw(8) << "CODIGO"
         << left << setw(25) << "NOMBRE"
         << left << setw(35) << "DIRECCION"
         << left << setw(15) << "CELULAR" << endl;
    cout << string(83, '-') << endl;

    for (int i = 0; i < tempL.contador; ++i) {
        cout << left << setw(8) << tempL.clientes[i].cod
             << left << setw(25) << tempL.clientes[i].nombre
             << left << setw(35) << tempL.clientes[i].direccion
             << left << setw(15) << tempL.clientes[i].celular << endl;
    }
    cout << string(83, '-') << endl;
    cout << "Total de clientes: " << tempL.contador << endl;
}

void saveClientsToFile(tLista& lista){
    ofstream outFile(file); 

    if (!outFile.is_open()) {
        cerr << "ERROR: No se pudo abrir el archivo '" << file << "' para guardar los clientes." << endl;
        return;
    }

    outFile << "Codigo,Nombre,Direccion,Celular" << endl;

    for (int i = 0; i < lista.contador; ++i) {
       
        outFile << lista.clientes[i].cod << ","
                << lista.clientes[i].nombre << ","
                << lista.clientes[i].direccion << ","
                << lista.clientes[i].celular << endl;
    }

    outFile.close();
}
// Función para ordenar la lista (usando burbujeo)
void ordenarLista(tLista& lista) 
{
    for (int i = 0; i < lista.contador - 1; i++) 
    {
        for (int j = 0; j < lista.contador - i - 1; j++) 
        {
            if (lista.clientes[j].cod > lista.clientes[j + 1].cod) 
            {
                // Intercambiar elementos
                tCliente temp = lista.clientes[j];
                lista.clientes[j] = lista.clientes[j + 1];
                lista.clientes[j + 1] = temp;
            }
        }
    }
}
