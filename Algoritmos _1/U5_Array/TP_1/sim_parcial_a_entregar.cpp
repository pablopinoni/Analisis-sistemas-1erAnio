#include <iostream>   
#include <fstream>    
#include <string>     
#include <iomanip>    
#include <sstream>    
#include <limits>     // Necesario para numeric_limits
using namespace std;


// --- Constantes ---

const int MAXIMO = 110;
const string file = "clientes_nich_tech.csv";

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

// Funciones Auxiliares y de Interfaz
void showCaratula();
void clearConsole();
// void pauseConsole(); // ELIMINADO
void showMenu();
bool listaVacia(const tLista& lista); 

// Funciones de Gestión de Archivos
void createOrCheckFile();        
void loadClientesFromFile(tLista& lista);
void saveClientsToFile(tLista& lista);

// Funciones de Gestión de Clientes
void altaCliente(tLista& lista);
void bajaCliente(tLista& lista, int codBuscado);
void modificarData(tLista& lista, int codBuscado);
void buscarClientesXCod(const tLista& lista, int codBuscado); // <-- Asegúrate de que el prototipo sea const
void listarClientes(const tLista& lista); 

// --- Función Principal (main) ---
int main() {
    clearConsole(); 
    tLista ListaNicTech; 
    ListaNicTech.contador = 0; 

    createOrCheckFile(); 
    loadClientesFromFile(ListaNicTech); 
    
    showCaratula();
    // pauseConsole(); // ELIMINADO

    int opcion; 

    do {
        // En cada iteración del bucle, la pantalla se limpiará y el menú se mostrará de nuevo.
        // Esto funciona como una "pausa" natural donde el usuario debe interactuar.
        clearConsole(); 
        showCaratula(); 
        showMenu();     
        
        cin >> opcion; 

        // Manejo de entrada inválida para la opción del menú
        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, ingrese un número.\n"; 
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de lo que se ingresó mal
           
            continue; // Volver al inicio del bucle do-while
        }
        
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

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
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        bajaCliente(ListaNicTech, cod);
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer después de la lectura del código
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
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
                }
                break;
            case 4:  
                cout <<"Opción 4: Lista de Clientes" << endl;
                listarClientes(ListaNicTech); 
                // Después de listar, puedes querer que el usuario presione Enter para volver al menú
                // o simplemente que el menú se muestre directamente de nuevo.
                // Si quieres una pausa aquí, puedes usar cin.get() o simplemente un cout << "Pulsa Enter para volver..."
                cout << "\nPresione Enter para volver al menú principal...\n";
                cin.get(); // Esperar Enter
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
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        buscarClientesXCod(ListaNicTech, cod); 
                    }
                    cout << "\nPresione Enter para volver al menú principal...\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer después de la lectura del código
                    cin.get(); // Esperar Enter
                }
                break;
            case 6: 
                cout << "Saliendo... ¡Hasta pronto!" << endl;
                // No hay necesidad de pauseConsole aquí, el programa terminará.
                break;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo.\n"; 
                // pauseConsole(); // ELIMINADO
                break; 
        }

        // Ya no necesitamos esta verificación porque las pausas están gestionadas
        // dentro de cada case o eliminadas.
        // if (opcion != 6) {
        //    pauseConsole();
        // }

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

// void pauseConsole() { // ELIMINADO
//    cout << "Presione Enter para continuar...\n"; 
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    cin.get(); 
// }


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
    // Considera si quieres una pausa aquí. Sin pauseConsole, el mensaje podría pasar rápido.
    // Una opción es usar un cin.get() aquí si quieres que el usuario lo lea.
    // cout << "Presione Enter para continuar...\n";
    // cin.get(); 
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
            try { // Añadir try-catch para stoi()
                tempClient.cod = stoi(segment);
            } catch (const std::invalid_argument& e) {
                cerr << "Error de formato: Código no numérico en línea: '" << line << "'. Saltando línea." << endl;
                continue;
            } catch (const std::out_of_range& e) {
                cerr << "Error de formato: Código fuera de rango en línea: '" << line << "'. Saltando línea." << endl;
                continue;
            }
        } else {
            cerr << "Error de formato: Codigo no encontrado en linea: '" << line << "'. Saltando linea." << endl;
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
            try { // Añadir try-catch para stoi()
                tempClient.celular = stoi(segment);
            } catch (const std::invalid_argument& e) {
                cerr << "Error de formato: Celular no numérico en línea: '" << line << "'. Saltando línea." << endl;
                continue;
            } catch (const std::out_of_range& e) {
                cerr << "Error de formato: Celular fuera de rango en línea: '" << line << "'. Saltando línea." << endl;
                continue;
            }
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
    // Considera si quieres una pausa aquí.
    cout << "Presione Enter para continuar...\n";
    //6 cin.get();
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

    if (lista.contador >= MAXIMO) { 
        cout << "No se pueden agregar más clientes. La lista está llena.\n";
        return;
    }
    tCliente nuevoCliente;

    nuevoCliente.cod = (lista.contador > 0) ? lista.clientes[lista.contador - 1].cod + 1 : 100;
    cout << "Código asignado al nuevo cliente: " << nuevoCliente.cod << endl;

    // --- Validar Nombre ---
    // cin.ignore() aquí para limpiar cualquier newline pendiente del menú principal
    // (el que se deja por el 'cin >> opcion;' en main)
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    
    do {
        cout << "Nombre completo: ";
        getline(cin, nuevoCliente.nombre);
        if (nuevoCliente.nombre.empty()) {
            cout << "El nombre no puede estar vacío. Por favor, ingrese un nombre válido.\n";
        }
    } while (nuevoCliente.nombre.empty());

    // --- Validar Dirección ---
    do {
        cout << "Dirección: ";
        getline(cin, nuevoCliente.direccion);
        if (nuevoCliente.direccion.empty()) {
            cout << "La dirección no puede estar vacía. Por favor, ingrese una dirección válida.\n";
        }
    } while (nuevoCliente.direccion.empty());

    // --- Validar Celular (más a fondo) ---
    bool celularValido = false;
    do {
        cout << "Celular: ";
        cin >> nuevoCliente.celular; 

        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, ingrese un número para el celular.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            if (nuevoCliente.celular <= 0) {
                cout << "El número de celular debe ser un número positivo.\n";
            } else {
                celularValido = true; 
            }
             // Limpiamos el buffer del '\n' que cin >> dejó, si la entrada fue un número
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    } while (!celularValido);
    
    // Este cin.ignore() se mueve dentro del bucle de validación del celular,
    // ya que cin >> nuevoCliente.celular; deja un '\n' que debe limpiarse.
    // La eliminación de pauseConsole() hace que el ciclo del main limpie antes de la siguiente opción.

    lista.clientes[lista.contador] = nuevoCliente;
    lista.contador++;

    cout << "\nCliente agregado correctamente.\n"; 
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
        // Limpiar el buffer después de leer la confirmación (char)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
      
        if (confirmacion == 's' || confirmacion == 'S') {
            
            lista.clientes[indiceEncontrado] = lista.clientes[lista.contador - 1];
            lista.contador--; 

            cout << "Cliente con código " << codBuscado << " eliminado correctamente.\n";
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
        cout << "La lista de clientes está vacía. No hay clientes para modificar.\n"; 
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

        cout << "\n===== Cliente encontrado - Datos Actuales =====\n";
        cout << "Código:    " << c.cod << "\n";
        cout << "Nombre:    " << c.nombre << "\n";
        cout << "Dirección: " << c.direccion << "\n";
        cout << "Celular:   " << c.celular << "\n";
        cout << "----------------------------------------------------\n";
     
        int campoAModificar;
        cout << "\n¿Qué campo desea modificar?\n";
        cout << "1. Nombre\n";
        cout << "2. Dirección\n"; 
        cout << "3. Celular\n";   
        cout << "4. Cancelar modificación\n";
        cout << "Opción: ";
        cin >> campoAModificar;
        
        if (cin.fail()) { 
            cout << "Entrada inválida. Por favor, ingrese un número válido (1-4).\n"; 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return; 
        } 
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        switch (campoAModificar)
        {
        case 1: 
            cout << "Ingrese nuevo Nombre (actual: " << c.nombre << "): "; 
            getline(cin, c.nombre);
            cout << "Nombre modificado correctamente.\n";
            break;
        case 2: 
            cout << "Ingrese nueva Dirección (actual: " << c.direccion << "): "; 
            getline(cin, c.direccion);
            cout << "Dirección modificada correctamente.\n";
            break;
        case 3: 
            cout << "Ingrese nuevo Celular (actual: " << c.celular << "): "; 
            int nuevoCelular; 
            cin >> nuevoCelular;
            if (cin.fail()) {
                cout << "Entrada inválida para el celular. No se modificó.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                c.celular = nuevoCelular;
                cout << "Celular modificado correctamente.\n";
            }
            // Después de leer un número con cin >>, siempre limpia el buffer del '\n'
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break;

        case 4: 
            cout << "Modificación cancelada. No se realizaron cambios.\n";
            return;
            
        default: 
            cout << "Opción no válida. No se realizó ninguna modificación.\n";
            return;
        }
        
        saveClientsToFile(lista);
        cout << "Los cambios se han guardado correctamente en el archivo.\n";

    } else { 
        cout << "No se ha encontrado un cliente que corresponda al código "
             << codBuscado << " .\n";
        return;
    }
}

void buscarClientesXCod(const tLista& lista, int codBuscado){ // Asegúrate de que el parámetro sea const
    clearConsole(); 

    if (listaVacia(lista)) { 
        cout << "La lista de clientes está vacía. No hay clientes para buscar.\n"; 
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
        const tCliente& c = lista.clientes[indiceEncontrado]; // Asegúrate de que la referencia sea const
        cout << "--- Detalles del Cliente ---\n";
        cout << "Código:    " << c.cod << "\n";
        cout << "Nombre:    " << c.nombre << "\n";
        cout << "Dirección: " << c.direccion << "\n";
        cout << "Celular:   " << c.celular << "\n";
        cout << "--------------------------\n";
    } else {
        cout << "Cliente con código " << codBuscado << " no encontrado.\n";
    }
}

void listarClientes(const tLista& lista) {
    clearConsole();
    showCaratula();

    if (listaVacia(lista)) { 
        cout << "No hay clientes para mostrar en la lista.\n";
        return;
    }

    cout << "\n----- LISTA DE CLIENTES -----\n";
    cout << left << setw(8) << "CODIGO"
         << left << setw(25) << "NOMBRE"
         << left << setw(35) << "DIRECCION"
         << left << setw(15) << "CELULAR" << endl;
    cout << string(83, '-') << endl;

    for (int i = 0; i < lista.contador; ++i) {
        cout << left << setw(8) << lista.clientes[i].cod
             << left << setw(25) << lista.clientes[i].nombre
             << left << setw(35) << lista.clientes[i].direccion
             << left << setw(15) << lista.clientes[i].celular << endl;
    }
    cout << string(83, '-') << endl;
    cout << "Total de clientes: " << lista.contador << endl;
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