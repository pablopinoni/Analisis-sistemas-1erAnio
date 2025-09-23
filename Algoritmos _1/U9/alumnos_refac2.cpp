/**
 * @file gestion_alumnos.cpp
 * @brief Programa para la gestión de alumnos, con funcionalidades de CRUD y ordenamiento.
 * @version 1.0
 * @author Gemini AI
 * @date 2025-09-23
 */

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

// --- CONSTANTES GLOBALES ---
const int MAX_ALUMNOS = 100;    ///< El número máximo de alumnos que la lista puede contener.
const string file = "alumnos.txt"; ///< Nombre del archivo de texto para la persistencia de datos.

// --- ESTRUCTURAS DE DATOS ---

/**
 * @struct tAlumno
 * @brief Estructura que representa a un alumno individual.
 * @param legajo: Identificador único del alumno.
 * @param apellido: Apellido del alumno.
 * @param nombre: Nombre del alumno.
 * @param direccion: Dirección de residencia del alumno.
 */
typedef struct {
    int legajo;
    string apellido;
    string nombre;
    string direccion;
} tAlumno;

/**
 * @struct tListaAlumnos
 * @brief Estructura que gestiona la colección de alumnos.
 * Contiene un array estático de tAlumno y un contador para
 * rastrear el número de elementos.
 */
typedef struct {
    tAlumno alumnos[MAX_ALUMNOS];
    int contador; ///< Número actual de alumnos en el array.
} tListaAlumnos;

/**
 * @struct tGestionAlumnos
 * @brief Estructura contenedora principal que agrupa la lista de alumnos.
 * Facilita el paso de la lista por referencia a las funciones.
 */
typedef struct {
    tListaAlumnos gestion;
} tGestionAlumnos;

// --- SOBRECARGA DE OPERADORES ---

/**
 * @brief Sobrecarga del operador de comparación > para la estructura tAlumno.
 * Permite comparar dos alumnos de forma alfabética. La comparación se realiza
 * primero por apellido y, si son iguales, por nombre.
 * @param opIzq El objeto tAlumno a la izquierda del operador.
 * @param opDer El objeto tAlumno a la derecha del operador.
 * @return Retorna true si opIzq es alfabéticamente mayor que opDer, de lo contrario false.
 */
bool operator>(const tAlumno &opIzq, const tAlumno &opDer) {
    if (opIzq.apellido != opDer.apellido) {
        return opIzq.apellido > opDer.apellido;
    }
    return opIzq.nombre > opDer.nombre;
}

/**
 * @brief Sobrecarga del operador de comparación < para la estructura tAlumno.
 * Permite comparar dos alumnos de forma alfabética para ordenamiento descendente.
 * La lógica es similar a la del operador >, pero con la comparación invertida.
 * @param opIzq El objeto tAlumno a la izquierda del operador.
 * @param opDer El objeto tAlumno a la derecha del operador.
 * @return Retorna true si opIzq es alfabéticamente menor que opDer, de lo contrario false.
 */
bool operator<(const tAlumno &opIzq, const tAlumno &opDer) {
    if (opIzq.apellido != opDer.apellido) {
        return opIzq.apellido < opDer.apellido;
    }
    return opIzq.nombre < opDer.nombre;
}

// --- FUNCIONES AUXILIARES ---

/**
 * @brief Limpia la pantalla de la consola.
 * Utiliza comandos específicos para Windows y sistemas basados en Unix (Linux/Mac).
 */
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
 * @brief Pausa la ejecución del programa y espera la entrada del usuario.
 * Simula el comportamiento de "presione una tecla para continuar" en diferentes sistemas operativos.
 */
void pauseConsole() {
#ifdef _WIN32
    system("pause");
#else
    cout << "Presione ENTER para continuar...";
    // Se usa cin.ignore para limpiar el buffer de entrada antes de esperar por un ENTER
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
}

/**
 * @brief Verifica si la lista de alumnos está vacía.
 * @param gestion Referencia constante al objeto que contiene la lista de alumnos.
 * @return Retorna true si el contador de alumnos es 0, de lo contrario false.
 */
bool emptyList(const tGestionAlumnos &gestion) {
    return gestion.gestion.contador == 0;
}

/**
 * @brief Valida la entrada del usuario para asegurar que es un número entero.
 * Solicita al usuario que ingrese un valor y lo valida en un bucle.
 * @param mensaje El mensaje a mostrar al usuario para solicitar la entrada.
 * @return El número entero válido ingresado por el usuario.
 */
int validarInt(const string &mensaje) {
    string entrada;
    int valor;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        stringstream ss(entrada);
        // Intenta extraer un entero y verifica que no quede "basura" en el stream
        if (ss >> valor && ss.eof()) {
            return valor;
        } else {
            cout << "Entrada inválida. Ingrese un número entero válido.\n";
        }
    }
}

// --- PROTOTIPOS DE FUNCIONES DE MENÚ Y VISUALIZACIÓN ---
void showTitle(bool encendido);
void blinkTitle(int veces, int milisegundos);
void showMainMenu(tGestionAlumnos &gestion);
int showOptionsMenu();
int showSubMenuManagement();
int showSubMenuListing();
int showSubMenuSorting();

// --- PROTOTIPOS DE FUNCIONES PRINCIPALES DE GESTIÓN ---
void saveList(const tGestionAlumnos &gestion);
void loadFromFile(tGestionAlumnos &gestion);
void insertAlumno(tGestionAlumnos &gestion);
void deleteAlumno(tGestionAlumnos &gestion);
void listAllAlumnos(const tGestionAlumnos &gestion);
void searchAlumnoByLegajo(const tGestionAlumnos &gestion, int legajoBuscado);

// --- PROTOTIPOS DE FUNCIONES DE ORDENAMIENTO ---
void sortAlumnos(tGestionAlumnos &gestion);
void swapAlumnos(tAlumno &a, tAlumno &b);
void sortAscending(tGestionAlumnos &gestion, int campo);
void sortDescending(tGestionAlumnos &gestion, int campo);

// =================================================== MAIN =========================================================== //
int main() {
    clearConsole();
    // Instancia de la estructura contenedora principal
    tGestionAlumnos gestion;
    gestion.gestion.contador = 0;

    // Cargar los datos al inicio del programa desde el archivo
    loadFromFile(gestion);
    
    // Animación de bienvenida
    blinkTitle(4, 500);
    pauseConsole();

    // Iniciar el bucle del menú principal
    showMainMenu(gestion);

    return 0;
}

// --- IMPLEMENTACIONES DE FUNCIONES DE MENÚ Y VISUALIZACIÓN ---

/**
 * @brief Muestra el título o logo del programa.
 * @param encendido Controla si el título se muestra en color (encendido) o apagado.
 */
void showTitle(bool encendido) {
    // Código para controlar los colores del texto en la terminal (secuencias de escape ANSI)
    if (encendido) {
        cout << "\033[1;33m"; // texto amarillo brillante
        cout << "\033[40m";   // fondo negro
    } else {
        cout << "\033[30m";   // texto negro (apaga texto)
        cout << "\033[40m";   // fondo negro
    }
    
    // Dibujo ASCII del logo
    cout << "\n";
    cout << "##################################################\n";
    cout << "##################################################\n";
    cout << "##################################################\n";
    cout << "                 GESTIÓN DE ALUMNOS                \n";
    cout << "##################################################\n";
    cout << "##################################################\n";
    cout << "\033[0m"; // resetear colores de la terminal
}

/**
 * @brief Crea un efecto de parpadeo para el título del programa.
 * @param veces El número de veces que el título debe parpadear.
 * @param milisegundos El tiempo de espera entre cada parpadeo en milisegundos.
 */
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

/**
 * @brief Controla el flujo principal del programa y la navegación del menú.
 * Contiene el bucle principal que muestra los menús y llama a las funciones
 * correspondientes según la opción elegida por el usuario.
 * @param gestion Referencia a la estructura contenedora principal.
 */
void showMainMenu(tGestionAlumnos &gestion) {
    int mainOption;
    do {
        mainOption = showOptionsMenu();

        switch (mainOption) {
            case 1: { // Opción para ir al menú de Gestión
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
            case 2: { // Opción para ir al menú de Listar y Buscar
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
            case 3: { // Opción para ir al menú de Ordenamiento
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

/**
 * @brief Muestra las opciones del menú principal.
 * @return La opción elegida por el usuario, validada como un entero.
 */
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

/**
 * @brief Muestra las opciones del submenú de gestión.
 * @return La opción elegida por el usuario, validada como un entero.
 */
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

/**
 * @brief Muestra las opciones del submenú de listado.
 * @return La opción elegida por el usuario, validada como un entero.
 */
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

/**
 * @brief Muestra las opciones del submenú de ordenamiento.
 * @return La opción elegida por el usuario, validada como un entero.
 */
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

// --- IMPLEMENTACIONES DE FUNCIONES PRINCIPALES ---

/**
 * @brief Guarda la lista de alumnos en el archivo de texto especificado.
 * El formato del archivo es:
 * - Primera línea: el número total de alumnos.
 * - Líneas siguientes: los datos de cada alumno separados por comas.
 * @param gestion Referencia constante a la estructura que contiene la lista.
 */
void saveList(const tGestionAlumnos &gestion) {
    ofstream archivo(file); // Abre el archivo en modo escritura (crea o sobrescribe)
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    
    // 1. Escribe el número total de alumnos en la primera línea para una carga eficiente
    archivo << gestion.gestion.contador << endl;
    
    // 2. Itera sobre el array de alumnos y guarda los datos
    for (int i = 0; i < gestion.gestion.contador; ++i) {
        const tAlumno &a = gestion.gestion.alumnos[i];
        // 3. Escribe los datos de cada alumno separados por comas
        archivo << a.legajo << ","
                << a.apellido << ","
                << a.nombre << ","
                << a.direccion << endl;
    }
    
    archivo.close(); // Cierra el archivo
    cout << "Lista de alumnos guardada en " << file << endl;
}

/**
 * @brief Carga la lista de alumnos desde el archivo de texto.
 * Si el archivo no existe, la lista se inicia vacía.
 * @param gestion Referencia a la estructura donde se cargarán los alumnos.
 */
void loadFromFile(tGestionAlumnos &gestion) {
    ifstream archivo(file); // Abre el archivo en modo lectura
    if (!archivo.is_open()) {
        cout << "Advertencia: No se encontró el archivo '" << file << "'. Se iniciará una lista vacía." << endl;
        gestion.gestion.contador = 0;
        return;
    }

    string linea;
    gestion.gestion.contador = 0;
    
    // 1. Lee el primer número, que indica la cantidad de alumnos a cargar
    getline(archivo, linea);
    int numAlumnos = 0;
    try {
        numAlumnos = stoi(linea);
    } catch (...) {
        numAlumnos = 0; // Si la conversión falla, asumimos 0 alumnos
    }

    // 2. Bucle para leer cada alumno del archivo
    for (int i = 0; i < numAlumnos && getline(archivo, linea); ++i) {
        if (gestion.gestion.contador >= MAX_ALUMNOS) break;
        
        stringstream ss(linea);
        string segment;
        tAlumno temp;

        // 3. Lee cada campo de la línea usando la coma como separador
        if (getline(ss, segment, ',')) temp.legajo = stoi(segment);
        if (getline(ss, segment, ',')) temp.apellido = segment;
        if (getline(ss, segment, ',')) temp.nombre = segment;
        if (getline(ss, segment, ',')) temp.direccion = segment;
        
        // 4. Asigna el alumno temporal al array y aumenta el contador
        gestion.gestion.alumnos[gestion.gestion.contador++] = temp;
    }

    archivo.close();
    cout << "Archivo cargado exitosamente: " << gestion.gestion.contador << " alumnos." << endl;
}

/**
 * @brief Inserta un nuevo alumno en la lista.
 * Verifica si hay espacio disponible antes de solicitar los datos del nuevo alumno.
 * @param gestion Referencia a la estructura donde se insertará el alumno.
 */
void insertAlumno(tGestionAlumnos &gestion) {
    if (gestion.gestion.contador >= MAX_ALUMNOS) {
        cout << "No se pueden agregar más alumnos. Se ha alcanzado el límite." << endl;
        return;
    }

    tAlumno nuevoAlumno;
    cout << "\n===== INSERTAR ALUMNO =====\n" << endl;
    nuevoAlumno.legajo = validarInt("Ingrese legajo del alumno: ");
    
    cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline()
    
    cout << "Ingrese nombre: ";
    getline(cin, nuevoAlumno.nombre);

    cout << "Ingrese apellido: ";
    getline(cin, nuevoAlumno.apellido);

    cout << "Ingrese dirección: ";
    getline(cin, nuevoAlumno.direccion);

    // Asigna el nuevo alumno al final del array y actualiza el contador
    gestion.gestion.alumnos[gestion.gestion.contador++] = nuevoAlumno;

    cout << "\nAlumno agregado con éxito.\n";
    saveList(gestion); // Guarda los cambios
}

/**
 * @brief Elimina un alumno de la lista por su número de legajo.
 * Busca el alumno y, si lo encuentra, desplaza el resto de elementos para
 * "borrarlo" lógicamente del array.
 * @param gestion Referencia a la estructura de gestión de alumnos.
 */
void deleteAlumno(tGestionAlumnos &gestion) {
    if (emptyList(gestion)) {
        cout << "No hay alumnos para eliminar." << endl;
        return;
    }

    int legajoBuscado = validarInt("Ingrese el legajo del alumno a eliminar: ");

    int indice = -1;
    // Bucle para buscar el índice del alumno
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

    // Desplaza los elementos a la izquierda para sobreescribir el alumno eliminado
    for (int i = indice; i < gestion.gestion.contador - 1; ++i) {
        gestion.gestion.alumnos[i] = gestion.gestion.alumnos[i + 1];
    }

    gestion.gestion.contador--; // Decrementa el contador de alumnos

    cout << "Alumno con legajo " << legajoBuscado << " eliminado correctamente." << endl;
    saveList(gestion); // Guarda los cambios
}

/**
 * @brief Muestra la información de todos los alumnos cargados en la lista.
 * @param gestion Referencia constante a la estructura que contiene la lista.
 */
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

/**
 * @brief Busca y muestra un alumno específico por su legajo.
 * @param gestion Referencia constante a la estructura que contiene la lista.
 * @param legajoBuscado El legajo del alumno a buscar.
 */
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

/**
 * @brief Coordina el proceso de ordenamiento de la lista de alumnos.
 * Muestra el submenú de ordenamiento y llama a las funciones de ordenación
 * correspondientes (ascendente o descendente).
 * @param gestion Referencia a la estructura que contiene la lista.
 */
void sortAlumnos(tGestionAlumnos &gestion) {
    if (emptyList(gestion)) {
        cout << "No hay alumnos para ordenar." << endl;
        return;
    }
    
    int sortOption = showSubMenuSorting(); // Pide al usuario el campo de ordenamiento
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
    
    listAllAlumnos(gestion); // Muestra la lista ya ordenada
}

/**
 * @brief Ordena la lista de alumnos de forma ascendente.
 * Utiliza el algoritmo de la burbuja (bubble sort) y la sobrecarga de operadores
 * para la comparación.
 * @param gestion Referencia a la estructura que contiene la lista.
 * @param campo Campo por el cual se va a ordenar (1: legajo, 2: apellido/nombre).
 */
void sortAscending(tGestionAlumnos &gestion, int campo) {
    int n = gestion.gestion.contador;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            bool shouldSwap = false;
            
            if (campo == 1) { // Ordenar por legajo (numérico)
                if (gestion.gestion.alumnos[j].legajo > gestion.gestion.alumnos[j + 1].legajo) {
                    shouldSwap = true;
                }
            } else if (campo == 2) { // Ordenar por apellido y nombre (alfabético)
                // Se usa el operador '>' sobrecargado para comparar directamente los objetos
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

/**
 * @brief Ordena la lista de alumnos de forma descendente.
 * La lógica es similar a la del ordenamiento ascendente, pero con la condición de
 * intercambio invertida para lograr el orden descendente.
 * @param gestion Referencia a la estructura que contiene la lista.
 * @param campo Campo por el cual se va a ordenar (1: legajo, 2: apellido/nombre).
 */
void sortDescending(tGestionAlumnos &gestion, int campo) {
    int n = gestion.gestion.contador;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            bool shouldSwap = false;
            
            if (campo == 1) { // Ordenar por legajo
                if (gestion.gestion.alumnos[j].legajo < gestion.gestion.alumnos[j + 1].legajo) {
                    shouldSwap = true;
                }
            } else if (campo == 2) { // Ordenar por apellido y nombre
                // Se usa el operador '<' sobrecargado para comparar los objetos
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

/**
 * @brief Función auxiliar para intercambiar dos objetos de tipo tAlumno.
 * Es esencial para los algoritmos de ordenamiento que requieren swaps.
 * @param a Referencia al primer objeto.
 * @param b Referencia al segundo objeto.
 */
void swapAlumnos(tAlumno &a, tAlumno &b) {
    tAlumno temp = a;
    a = b;
    b = temp;
}