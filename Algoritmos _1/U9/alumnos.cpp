#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

const int MAX_ALUMNOS = 100;
const string file = "alumnos.txt";

// Estructura para un alumno
typedef struct {
    int legajo;
    string apellido;
    string nombre;
    string direccion;
} tAlumno;

// Lista de alumnos
typedef struct {
    tAlumno alumnos[MAX_ALUMNOS];
    int contador;
} tListaAlumnos;

// Estructura general Contenedora
typedef struct {
    tListaAlumnos gestion;
} tGestionAlumnos;

// Sobrecarga de operadores para tAlumno (comparación por apellido y nombre)
bool operator>(const tAlumno &opIzq, const tAlumno &opDer) {
    if (opIzq.apellido != opDer.apellido) {
        return opIzq.apellido > opDer.apellido;
    }
    return opIzq.nombre > opDer.nombre;
}

bool operator<(const tAlumno &opIzq, const tAlumno &opDer) {
    if (opIzq.apellido != opDer.apellido) {
        return opIzq.apellido < opDer.apellido;
    }
    return opIzq.nombre < opDer.nombre;
}

// ---- Funciones auxiliares ----
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); // Mac o Linux
#endif
}

void pauseConsole() {
#ifdef _WIN32
    system("pause");
#else
    cout << "Presione ENTER para continuar...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
}

bool emptyList(const tGestionAlumnos &gestion) {
    return gestion.gestion.contador == 0;
}

int validarInt(const string &mensaje) {
    string entrada;
    int valor;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        stringstream ss(entrada);
        if (ss >> valor && ss.eof()) {
            return valor;
        } else {
            cout << "Entrada inválida. Ingrese un número entero válido.\n";
        }
    }
}

// ---- Prototipos de funciones ----
void showTitle(bool encendido);
void blinkTitle(int veces, int milisegundos);
void showMainMenu(tGestionAlumnos &gestion);
int showOptionsMenu();
int showSubMenuManagement();
int showSubMenuListing();
int showSubMenuSorting();

void saveList(const tGestionAlumnos &gestion);
void loadFromFile(tGestionAlumnos &gestion);
void insertAlumno(tGestionAlumnos &gestion);
void deleteAlumno(tGestionAlumnos &gestion);
void listAllAlumnos(const tGestionAlumnos &gestion);
void searchAlumnoByLegajo(const tGestionAlumnos &gestion, int legajoBuscado);
void sortAlumnos(tGestionAlumnos &gestion);
void swapAlumnos(tAlumno &a, tAlumno &b);
void sortAscending(tGestionAlumnos &gestion, int campo);
void sortDescending(tGestionAlumnos &gestion, int campo);

// =================================================== MAIN =========================================================== //
int main() {
    clearConsole();
    tGestionAlumnos gestion;
    gestion.gestion.contador = 0;

    loadFromFile(gestion);
    blinkTitle(4, 500);
    pauseConsole();

    showMainMenu(gestion);

    return 0;
}

// ---- Implementaciones de funciones de menú y visualización ----
void showTitle(bool encendido) {
    if (encendido) {
        cout << "\033[1;33m"; // texto amarillo brillante
        cout << "\033[40m";   // fondo negro
    } else {
        cout << "\033[30m";   // texto negro (apaga texto)
        cout << "\033[40m";   // fondo negro
    }

    cout << "\n";
    cout << "##################################################\n";
    cout << "#######     ######  ########    #####     ########\n";
    cout << "######  ##########  #######  ###  ###  #  ########\n";
    cout << "######  ##########  #######  ###  ###  ##  #######\n";
    cout << "######  ##########  #######       ###       ######\n";
    cout << "######   #########  #######  ###  ###   ###  #####\n";
    cout << "#######     #  ###       ##  ###  ###       ######\n";
    cout << "##################################################\n";
    cout << "                 GESTIÓN DE ALUMNOS                \n";
    cout << "##################################################\n";
    cout << "\033[0m"; // reset colores
}

void blinkTitle(int veces, int milisegundos) {
    for (int i = 0; i < veces; ++i) {
        clearConsole();
        showTitle(true);
        this_thread::sleep_for(chrono::milliseconds(milisegundos));
        
        clearConsole();
        showTitle(false);
        this_thread::sleep_for(chrono::milliseconds(milisegundos));
    }
}

void showMainMenu(tGestionAlumnos &gestion) {
    int mainOption;
    do {
        mainOption = showOptionsMenu();

        switch (mainOption) {
            case 1: { // Gestión
                int managementOption;
                do {
                    managementOption = showSubMenuManagement();
                    switch (managementOption) {
                        case 1:
                            insertAlumno(gestion);
                            break;
                        case 2:
                            deleteAlumno(gestion);
                            break;
                        case 0:
                            cout << "Volviendo al menú principal..." << endl;
                            break;
                        default:
                            cout << "Opción inválida." << endl;
                    }
                } while (managementOption != 0);
                break;
            }
            case 2: { // Listar
                int listOption;
                do {
                    listOption = showSubMenuListing();
                    switch (listOption) {
                        case 1:
                            listAllAlumnos(gestion);
                            break;
                        case 2: {
                            int legajo = validarInt("Ingrese legajo del alumno a buscar: ");
                            searchAlumnoByLegajo(gestion, legajo);
                            break;
                        }
                        case 0:
                            cout << "Volviendo al menú principal..." << endl;
                            break;
                        default:
                            cout << "Opción inválida." << endl;
                    }
                } while (listOption != 0);
                break;
            }
            case 3: { // Ordenar
                sortAlumnos(gestion);
                break;
            }
            case 0:
                cout << "Guardando datos y saliendo..." << endl;
                saveList(gestion);
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }

    } while (mainOption != 0);
}

int showOptionsMenu() {
    int option;
    do {
        cout << "\n===== MENÚ PRINCIPAL =====\n";
        cout << "1. Gestión de Alumnos\n";
        cout << "2. Listar y Buscar Alumnos\n";
        cout << "3. Ordenar Alumnos\n";
        cout << "0. Salir\n";
        
        option = validarInt("Ingrese opción: ");
        
        if (option < 0 || option > 3) {
            cout << "Opción inválida. Por favor ingrese un número válido." << endl;
        }
    } while (option < 0 || option > 3);
    return option;
}

int showSubMenuManagement() {
    int option;
    do {
        cout << "\n===== MENÚ GESTIÓN =====\n";
        cout << "1. Insertar un Alumno\n";
        cout << "2. Eliminar un Alumno\n";
        cout << "0. Volver al menú principal\n";
        
        option = validarInt("Ingrese opción: ");

        if (option < 0 || option > 2) {
            cout << "Opción inválida. Por favor ingrese un número válido." << endl;
        }
    } while (option < 0 || option > 2);
    return option;
}

int showSubMenuListing() {
    int option;
    do {
        cout << "\n===== MENÚ LISTAR =====\n";
        cout << "1. Listar todos los alumnos\n";
        cout << "2. Buscar alumno por legajo\n";
        cout << "0. Volver al menú principal\n";
        
        option = validarInt("Ingrese opción: ");

        if (option < 0 || option > 2) {
            cout << "Opción inválida. Por favor ingrese un número válido." << endl;
        }
    } while (option < 0 || option > 2);
    return option;
}

int showSubMenuSorting() {
    int option;
    do {
        cout << "\n===== MENÚ ORDENAMIENTO =====\n";
        cout << "1. Ordenar por Legajo\n";
        cout << "2. Ordenar por Apellido y Nombre\n";
        cout << "0. Volver al menú principal\n";
        
        option = validarInt("Ingrese opción: ");

        if (option < 0 || option > 2) {
            cout << "Opción inválida. Por favor ingrese un número válido." << endl;
        }
    } while (option < 0 || option > 2);
    return option;
}

// ---- Implementaciones de funciones principales ----
void saveList(const tGestionAlumnos &gestion) {
    ofstream archivo(file);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    
    archivo << gestion.gestion.contador << endl;
    for (int i = 0; i < gestion.gestion.contador; ++i) {
        const tAlumno &a = gestion.gestion.alumnos[i];
        archivo << a.legajo << ","
                << a.apellido << ","
                << a.nombre << ","
                << a.direccion << endl;
    }
    
    archivo.close();
    cout << "Lista de alumnos guardada en " << file << endl;
}

void loadFromFile(tGestionAlumnos &gestion) {
    ifstream archivo(file);
    if (!archivo.is_open()) {
        cout << "Advertencia: No se encontró el archivo '" << file << "'. Se iniciará una lista vacía." << endl;
        gestion.gestion.contador = 0;
        return;
    }

    string linea;
    gestion.gestion.contador = 0;
    
    getline(archivo, linea);
    int numAlumnos = 0;
    try {
        numAlumnos = stoi(linea);
    } catch (...) {
        numAlumnos = 0;
    }

    for (int i = 0; i < numAlumnos && getline(archivo, linea); ++i) {
        if (gestion.gestion.contador >= MAX_ALUMNOS) break;
        
        stringstream ss(linea);
        string segment;
        tAlumno temp;

        if (getline(ss, segment, ',')) temp.legajo = stoi(segment);
        if (getline(ss, segment, ',')) temp.apellido = segment;
        if (getline(ss, segment, ',')) temp.nombre = segment;
        if (getline(ss, segment, ',')) temp.direccion = segment;
        
        gestion.gestion.alumnos[gestion.gestion.contador++] = temp;
    }

    archivo.close();
    cout << "Archivo cargado exitosamente: " << gestion.gestion.contador << " alumnos." << endl;
}

void insertAlumno(tGestionAlumnos &gestion) {
    if (gestion.gestion.contador >= MAX_ALUMNOS) {
        cout << "No se pueden agregar más alumnos. Se ha alcanzado el límite." << endl;
        return;
    }

    tAlumno nuevoAlumno;
    cout << "\n===== INSERTAR ALUMNO =====\n" << endl;
    nuevoAlumno.legajo = validarInt("Ingrese legajo del alumno: ");
    
    cin.ignore(); // Limpiar el buffer
    
    cout << "Ingrese nombre: ";
    getline(cin, nuevoAlumno.nombre);

    cout << "Ingrese apellido: ";
    getline(cin, nuevoAlumno.apellido);

    cout << "Ingrese dirección: ";
    getline(cin, nuevoAlumno.direccion);

    gestion.gestion.alumnos[gestion.gestion.contador++] = nuevoAlumno;

    cout << "\nAlumno agregado con éxito.\n";
    saveList(gestion);
}

void deleteAlumno(tGestionAlumnos &gestion) {
    if (emptyList(gestion)) {
        cout << "No hay alumnos para eliminar." << endl;
        return;
    }

    int legajoBuscado = validarInt("Ingrese el legajo del alumno a eliminar: ");

    int indice = -1;
    for (int i = 0; i < gestion.gestion.contador; ++i) {
        if (gestion.gestion.alumnos[i].legajo == legajoBuscado) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "Alumno con legajo " << legajoBuscado << " no encontrado." << endl;
        return;
    }

    for (int i = indice; i < gestion.gestion.contador - 1; ++i) {
        gestion.gestion.alumnos[i] = gestion.gestion.alumnos[i + 1];
    }

    gestion.gestion.contador--;

    cout << "Alumno con legajo " << legajoBuscado << " eliminado correctamente." << endl;
    saveList(gestion);
}

void listAllAlumnos(const tGestionAlumnos &gestion) {
    if (emptyList(gestion)) {
        cout << "\nNo hay alumnos cargados.\n";
        return;
    }

    cout << "\n==== LISTA DE ALUMNOS ====\n";
    for (int i = 0; i < gestion.gestion.contador; ++i) {
        const tAlumno &a = gestion.gestion.alumnos[i];
        cout << "Legajo: " << a.legajo << "\n";
        cout << "Apellido: " << a.apellido << "\n";
        cout << "Nombre: " << a.nombre << "\n";
        cout << "Dirección: " << a.direccion << "\n";
        cout << "--------------------------\n";
    }
}

void searchAlumnoByLegajo(const tGestionAlumnos &gestion, int legajoBuscado) {
    bool encontrado = false;
    for (int i = 0; i < gestion.gestion.contador; ++i) {
        if (gestion.gestion.alumnos[i].legajo == legajoBuscado) {
            const tAlumno &a = gestion.gestion.alumnos[i];
            cout << "\nAlumno encontrado:\n";
            cout << "Legajo: " << a.legajo << "\n";
            cout << "Apellido: " << a.apellido << "\n";
            cout << "Nombre: " << a.nombre << "\n";
            cout << "Dirección: " << a.direccion << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Alumno con legajo " << legajoBuscado << " no encontrado.\n";
    }
}

void sortAlumnos(tGestionAlumnos &gestion) {
    if (emptyList(gestion)) {
        cout << "No hay alumnos para ordenar." << endl;
        return;
    }
    
    int sortOption = showSubMenuSorting();
    if (sortOption == 0) return;
    
    char orderOption;
    cout << "¿Desea ordenar de forma ascendente (a) o descendente (d)?: ";
    cin >> orderOption;
    
    cin.ignore();
    
    if (orderOption == 'a' || orderOption == 'A') {
        sortAscending(gestion, sortOption);
        cout << "Lista ordenada de forma ascendente." << endl;
    } else if (orderOption == 'd' || orderOption == 'D') {
        sortDescending(gestion, sortOption);
        cout << "Lista ordenada de forma descendente." << endl;
    } else {
        cout << "Opción de ordenamiento inválida. No se aplicó ningún cambio." << endl;
    }
    
    listAllAlumnos(gestion);
}

void sortAscending(tGestionAlumnos &gestion, int campo) {
    int n = gestion.gestion.contador;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            bool shouldSwap = false;
            
            if (campo == 1) { // Ordenar por legajo
                if (gestion.gestion.alumnos[j].legajo > gestion.gestion.alumnos[j + 1].legajo) {
                    shouldSwap = true;
                }
            } else if (campo == 2) { // Ordenar por apellido y nombre (usando operadores sobrecargados)
                if (gestion.gestion.alumnos[j] > gestion.gestion.alumnos[j + 1]) {
                    shouldSwap = true;
                }
            }
            
            if (shouldSwap) {
                swapAlumnos(gestion.gestion.alumnos[j], gestion.gestion.alumnos[j + 1]);
            }
        }
    }
}

void sortDescending(tGestionAlumnos &gestion, int campo) {
    int n = gestion.gestion.contador;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            bool shouldSwap = false;
            
            if (campo == 1) { // Ordenar por legajo
                if (gestion.gestion.alumnos[j].legajo < gestion.gestion.alumnos[j + 1].legajo) {
                    shouldSwap = true;
                }
            } else if (campo == 2) { // Ordenar por apellido y nombre (usando operadores sobrecargados)
                if (gestion.gestion.alumnos[j] < gestion.gestion.alumnos[j + 1]) {
                    shouldSwap = true;
                }
            }
            
            if (shouldSwap) {
                swapAlumnos(gestion.gestion.alumnos[j], gestion.gestion.alumnos[j + 1]);
            }
        }
    }
}

void swapAlumnos(tAlumno &a, tAlumno &b) {
    tAlumno temp = a;
    a = b;
    b = temp;
}