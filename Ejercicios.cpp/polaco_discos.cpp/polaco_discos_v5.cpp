#include <iostream>
#include <locale>
#include <ostream>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include <iomanip> // Para std::fixed y std::setprecision
#include <cstdio>  // Para system("cls") o system("clear")

using namespace std;

// --- Constantes ---
const int MAX_CLIENTES = 75;
const int MAX_MOVIMIENTOS = 50;
const string FILE_CLIENTES = "clientes_polaco_discos.csv";

// --- Estructuras ---
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Movimiento {
    Fecha fecha;
    float importe;
    string detalle;
};

struct tMovimiento {
    Movimiento movimientos[MAX_MOVIMIENTOS];
    int cantidadMovimientos;
};

struct tCliente {
    int codigo;
    string nombre;
    string direccion;
    string telefono;
    bool reservas;
    tMovimiento movimiento; // Sub-estructura para manejar los movimientos de este cliente
};

struct tLista {
    tCliente clientes[MAX_CLIENTES];
    int counterCliente;
};

struct tContenedor {
    tLista Lista;
};

// --- Prototipos ---
void guardarMovimientosCSV(int codigo_cliente, const tMovimiento& movimientos_cliente);
void cargarMovimientosCSV(int codigo_cliente, tMovimiento& movimientos_cliente);
float calcularSaldo(const tCliente& cliente);
void guardarClientesCSV(const tContenedor& contenedor);
void cargarClientesCSV(tContenedor& contenedor);
void clearConsole();
void limpiarBuffer();
int validarINT(const string& mensaje);
float validarFloat(const string& mensaje);
bool validarBool(const string& mensaje);
Fecha pedirFecha();
int buscarClientePorCodigo(const tContenedor& contenedor, int codigo);
void agregarMovimiento(tCliente& cliente);
void altaCliente(tContenedor& contenedor);
void listarClientes(const tContenedor& contenedor);
void modificarCliente(tContenedor& contenedor);
void eliminarCliente(tContenedor& contenedor);
void mostrarEstadoCuenta(const tCliente& cliente);
void menu(tContenedor& contenedor);

// --- Funciones auxiliares ---

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int validarINT(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            limpiarBuffer();
            return valor;
        } else {
            cout << "Entrada inválida. Por favor ingrese un número entero.\n";
            limpiarBuffer();
        }
    }
}

float validarFloat(const string& mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            limpiarBuffer();
            return valor;
        } else {
            cout << "Entrada inválida. Por favor ingrese un número válido.\n";
            limpiarBuffer();
        }
    }
}

bool validarBool(const string& mensaje) {
    string entrada;
    while (true) {
        cout << mensaje << " (s/n): ";
        getline(cin, entrada);
        if (entrada == "s" || entrada == "S") return true;
        if (entrada == "n" || entrada == "N") return false;
        cout << "Entrada inválida. Ingrese 's' o 'n'.\n";
    }
}

// Validación simple para fechas válidas (día y mes dentro de rango)
Fecha pedirFecha() {
    Fecha f;
    while (true) {
        f.dia = validarINT("Día (1-31): ");
        f.mes = validarINT("Mes (1-12): ");
        f.anio = validarINT("Año: ");

        if (f.dia >= 1 && f.dia <= 31 && f.mes >= 1 && f.mes <= 12 && f.anio > 1900) {
            break;
        } else {
            cout << "Fecha inválida. Intente de nuevo.\n";
        }
    }
    return f;
}

// Escapa texto para CSV (comillas y comas)
string escaparParaCSV(const string& texto) {
    bool tiene_coma = texto.find(',') != string::npos;
    bool tiene_comilla = texto.find('"') != string::npos;
    if (!tiene_coma && !tiene_comilla) {
        return texto; // sin cambios si no hay comas ni comillas
    }
    string resultado = "\"";
    for (char c : texto) {
        if (c == '"') resultado += "\"\""; // duplicar comillas
        else resultado += c;
    }
    resultado += "\"";
    return resultado;
}

// Lee un campo CSV con soporte para comillas y comas internas
string leerCampoCSV(istream& ss) {
    string resultado;
    if (ss.peek() == '"') {
        ss.get(); // consumir comilla inicial
        char c;
        while (ss.get(c)) {
            if (c == '"') {
                if (ss.peek() == '"') { // comilla escapada
                    ss.get();
                    resultado += '"';
                } else {
                    break; // fin del campo con comillas
                }
            } else {
                resultado += c;
            }
        }
        if (ss.peek() == ',') ss.get(); // consumir coma después de cerrar comillas
    } else {
        getline(ss, resultado, ',');
    }
    return resultado;
}

// --- Funciones de persistencia ---

void guardarMovimientosCSV(int codigo_cliente, const tMovimiento& movimientos_cliente) {
    string nombre_archivo_mov = "movimientos_cliente_" + to_string(codigo_cliente) + ".csv"; 
    ofstream archivo_movimientos(nombre_archivo_mov); 
    if (!archivo_movimientos.is_open()) {
        cout << "Error: No se pudo abrir el archivo de movimientos para el cliente " << codigo_cliente << ".\n";
        return; 
    }

    archivo_movimientos.unsetf(ios_base::floatfield); 
    archivo_movimientos << defaultfloat;

    for (int i = 0; i < movimientos_cliente.cantidadMovimientos; ++i) {
        const Movimiento& m = movimientos_cliente.movimientos[i]; 
        archivo_movimientos << m.fecha.dia << ","
                            << m.fecha.mes << ","
                            << m.fecha.anio << ","
                            << fixed << setprecision(2) << m.importe << ","
                            << escaparParaCSV(m.detalle) << "\n"; 
    }
    archivo_movimientos.close(); 
}

void cargarMovimientosCSV(int codigo_cliente, tMovimiento& movimientos_cliente) {
    string nombre_archivo_mov = "movimientos_cliente_" + to_string(codigo_cliente) + ".csv";
    ifstream archivo_movimientos(nombre_archivo_mov);

    if (!archivo_movimientos.is_open()) {
        movimientos_cliente.cantidadMovimientos = 0;    
        return;    
    }

    string linea_mov;
    movimientos_cliente.cantidadMovimientos = 0;

    while (getline(archivo_movimientos, linea_mov) && movimientos_cliente.cantidadMovimientos < MAX_MOVIMIENTOS) {
        stringstream ss_mov(linea_mov);
        
        Movimiento m;

        string campo_mov;
        getline(ss_mov, campo_mov, ','); m.fecha.dia = stoi(campo_mov);
        getline(ss_mov, campo_mov, ','); m.fecha.mes = stoi(campo_mov);
        getline(ss_mov, campo_mov, ','); m.fecha.anio = stoi(campo_mov);
        getline(ss_mov, campo_mov, ','); m.importe = stof(campo_mov);
        m.detalle = leerCampoCSV(ss_mov);

        movimientos_cliente.movimientos[movimientos_cliente.cantidadMovimientos] = m;
        movimientos_cliente.cantidadMovimientos++; 
    }
    archivo_movimientos.close();
}

void guardarClientesCSV(const tContenedor& contenedor) {
    ofstream archivo(FILE_CLIENTES);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo principal de clientes para guardar.\n";
        return;
    }

    for (int i = 0; i < contenedor.Lista.counterCliente; ++i) {
        const tCliente& c = contenedor.Lista.clientes[i];
        archivo << c.codigo << ","
                << escaparParaCSV(c.nombre) << ","
                << escaparParaCSV(c.direccion) << ","
                << escaparParaCSV(c.telefono) << ","
                << c.reservas << "\n";
        guardarMovimientosCSV(c.codigo, c.movimiento);
    }

    archivo.close();
    cout << "Clientes y sus movimientos guardados correctamente.\n";
}

void cargarClientesCSV(tContenedor& contenedor) {
    ifstream archivo(FILE_CLIENTES);
    if (!archivo.is_open()) {
        cout << "Archivo de clientes no encontrado. Se iniciará con una lista vacía.\n";
        contenedor.Lista.counterCliente = 0; 
        return;
    }

    string linea;
    contenedor.Lista.counterCliente = 0; 

    while (getline(archivo, linea) && contenedor.Lista.counterCliente < MAX_CLIENTES) { 
        stringstream ss(linea);
        string campo;

        tCliente c; 

        // Usar leerCampoCSV para cada campo que puede tener comas
        getline(ss, campo, ','); c.codigo = stoi(campo);
        c.nombre = leerCampoCSV(ss);
        c.direccion = leerCampoCSV(ss);
        c.telefono = leerCampoCSV(ss);
        getline(ss, campo, ','); c.reservas = (campo == "1");

        cargarMovimientosCSV(c.codigo, c.movimiento); 

        contenedor.Lista.clientes[contenedor.Lista.counterCliente] = c;
        contenedor.Lista.counterCliente++; 
    }

    archivo.close();
    cout << "Clientes y sus movimientos cargados correctamente desde el archivo.\n"; 
}

// --- Funciones de lógica ---

int buscarClientePorCodigo(const tContenedor& contenedor, int codigo) {
    for (int i = 0; i < contenedor.Lista.counterCliente; ++i) {
        if (contenedor.Lista.clientes[i].codigo == codigo) 
            return i;
    }
    return -1;
}

float calcularSaldo(const tCliente& cliente) {
    float saldo = 0;
    for (int i = 0; i < cliente.movimiento.cantidadMovimientos; ++i) {
        saldo += cliente.movimiento.movimientos[i].importe;
    }
    return saldo;
}

void agregarMovimiento(tCliente& cliente) {
    if (cliente.movimiento.cantidadMovimientos >= MAX_MOVIMIENTOS) {
        cout << "No se pueden agregar más movimientos a este cliente. Límite: " << MAX_MOVIMIENTOS << ".\n";
        return;
    }
    cout << "Ingrese datos del movimiento:\n";
    Fecha f = pedirFecha();
    float importe = validarFloat("Importe (positivo = pago, negativo = cargo): ");

    cout << "Detalle: ";
    string detalle;
    getline(cin, detalle);

    cliente.movimiento.movimientos[cliente.movimiento.cantidadMovimientos].fecha = f;
    cliente.movimiento.movimientos[cliente.movimiento.cantidadMovimientos].importe = importe;
    cliente.movimiento.movimientos[cliente.movimiento.cantidadMovimientos].detalle = detalle;
    cliente.movimiento.cantidadMovimientos++;

    cout << "Movimiento agregado.\n";
}

void altaCliente(tContenedor& contenedor) {
    if (contenedor.Lista.counterCliente >= MAX_CLIENTES) {
        cout << "No hay espacio para más clientes. Límite: " << MAX_CLIENTES << ".\n";
        return;
    }
    tCliente& nuevo = contenedor.Lista.clientes[contenedor.Lista.counterCliente];
    
    if (contenedor.Lista.counterCliente == 0) { 
        nuevo.codigo = 100; 
    } else {
        int max_codigo = 0;
        for (int i = 0; i < contenedor.Lista.counterCliente; ++i) {
            if (contenedor.Lista.clientes[i].codigo > max_codigo) {
                max_codigo = contenedor.Lista.clientes[i].codigo;
            }
        }
        nuevo.codigo = max_codigo + 1; 
    }

    cout << "Nombre: ";
    string temp_linea;
    getline(cin, temp_linea);
    stringstream ss_nombre(temp_linea);
    getline(ss_nombre, nuevo.nombre);

    cout << "Dirección: ";
    getline(cin, nuevo.direccion);
    cout << "Teléfono: ";
    getline(cin, nuevo.telefono);
    nuevo.reservas = validarBool("¿Tiene reservas?");
    
    nuevo.movimiento.cantidadMovimientos = 0;

    contenedor.Lista.counterCliente++;
    guardarClientesCSV(contenedor);
    cout << "Cliente agregado con éxito.\n";
}

void listarClientes(const tContenedor& contenedor) {
    if (contenedor.Lista.counterCliente == 0) { 
        cout << "No hay clientes para mostrar.\n";
        return;
    }
    cout << left << setw(6) << "Cod"
             << setw(20) << "Nombre"
             << setw(25) << "Dirección"
             << setw(15) << "Teléfono"
             << setw(10) << "Reservas"
             << setw(10) << "Saldo" << "\n";
    cout << string(86, '-') << "\n";
    for (int i = 0; i < contenedor.Lista.counterCliente; ++i) {
        const tCliente& c = contenedor.Lista.clientes[i];
        cout << setw(6) << c.codigo
             << setw(20) << c.nombre
             << setw(25) << c.direccion
             << setw(15) << c.telefono
             << setw(10) << (c.reservas ? "Sí" : "No")
             << setw(10) << fixed << setprecision(2) << calcularSaldo(c) << "\n";
    }
}

void modificarCliente(tContenedor& contenedor) {
    int codigo = validarINT("Código a modificar: ");
    int pos = buscarClientePorCodigo(contenedor, codigo);
    if (pos == -1) {
        cout << "Cliente no encontrado.\n";
        return;
    }
    tCliente& cliente_a_modificar = contenedor.Lista.clientes[pos];

    cout << "Nuevo nombre (actual: " << cliente_a_modificar.nombre << "): ";
    string temp_linea;
    getline(cin, temp_linea);
    stringstream ss_nombre(temp_linea);
    getline(ss_nombre, cliente_a_modificar.nombre);
    
    cout << "Nueva dirección (actual: " << cliente_a_modificar.direccion << "): ";
    getline(cin, cliente_a_modificar.direccion);
    cout << "Nuevo teléfono (actual: " << cliente_a_modificar.telefono << "): ";
    getline(cin, cliente_a_modificar.telefono);
    cliente_a_modificar.reservas = validarBool("¿Tiene reservas?");
    guardarClientesCSV(contenedor);
    cout << "Cliente modificado.\n";
}

void eliminarCliente(tContenedor& contenedor) {
    int codigo = validarINT("Código a eliminar: ");
    int pos = buscarClientePorCodigo(contenedor, codigo);
    if (pos == -1) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    string nombre_archivo_mov_a_eliminar = "movimientos_cliente_" + to_string(contenedor.Lista.clientes[pos].codigo) + ".csv";
    if (remove(nombre_archivo_mov_a_eliminar.c_str()) != 0) {
        // No es error crítico si no se elimina
    }

    for (int i = pos; i < contenedor.Lista.counterCliente - 1; ++i) {
        contenedor.Lista.clientes[i] = contenedor.Lista.clientes[i + 1];
    }
    contenedor.Lista.counterCliente--;

    guardarClientesCSV(contenedor);
    cout << "Cliente eliminado.\n";
}

void mostrarEstadoCuenta(const tCliente& cliente) { 
    cout << "Estado de cuenta para " << cliente.nombre << " (Código: " << cliente.codigo << "):\n";
    cout << left << setw(12) << "Fecha"
             << setw(12) << "Importe"
             << "Detalle" << "\n";
    cout << string(50, '-') << "\n";

    if (cliente.movimiento.cantidadMovimientos == 0) {
        cout << "No hay movimientos para este cliente.\n";
    } else {
        for (int i = 0; i < cliente.movimiento.cantidadMovimientos; ++i) {
            Fecha f = cliente.movimiento.movimientos[i].fecha;
            stringstream fecha_str;
            fecha_str << setfill('0') << setw(2) << f.dia << "/"
                      << setw(2) << f.mes << "/"
                      << setfill(' ') << setw(4) << f.anio;

            cout << left << setw(12) << fecha_str.str()
                 << setw(12) << fixed << setprecision(2) << cliente.movimiento.movimientos[i].importe
                 << cliente.movimiento.movimientos[i].detalle << "\n";   
        }
    }
    cout << string(50, '-') << "\n";
    cout << "Saldo total: " << fixed << setprecision(2) << calcularSaldo(cliente) << endl; 
}

void menu(tContenedor& contenedor) {
    int opcion;
    do {
        clearConsole();
        cout << "==========================================="  <<endl;
        cout << "\n     --- Sistema Polaco Discos ---\n";
        cout << "\n==========================================="  <<endl;
        cout << "1. Alta cliente\n";
        cout << "2. Listar clientes\n";
        cout << "3. Modificar cliente\n";
        cout << "4. Eliminar cliente\n";
        cout << "5. Agregar movimiento a cliente\n";
        cout << "6. Mostrar estado de cuenta cliente\n";
        cout << "0. Salir\n";
        cout << "==========================================="  <<endl;

        opcion = validarINT("Opción: ");

        switch (opcion) {
            case 1: altaCliente(contenedor); break;
            case 2: listarClientes(contenedor); break;
            case 3: modificarCliente(contenedor); break;
            case 4: eliminarCliente(contenedor); break;
            case 5: {
                int codigo = validarINT("Código del cliente para agregar movimiento: ");
                int pos = buscarClientePorCodigo(contenedor, codigo);
                
                if (pos == -1) {
                    cout << "Cliente no encontrado.\n";
                } else {
                    agregarMovimiento(contenedor.Lista.clientes[pos]);
                    guardarClientesCSV(contenedor);
                }
                cout << "Presione Enter para continuar...";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            case 6: {
                int codigo = validarINT("Código del cliente para mostrar estado de cuenta: ");
                int pos = buscarClientePorCodigo(contenedor, codigo);
                if (pos == -1) {
                    cout << "Cliente no encontrado.\n";
                } else {
                    mostrarEstadoCuenta(contenedor.Lista.clientes[pos]);
                }
                cout << "Presione Enter para continuar...";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
                cout << "Presione Enter para continuar...";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    } while (opcion != 0);
}

int main() {
    setlocale(LC_ALL, "");
    tContenedor contenedor;
    cargarClientesCSV(contenedor);
    menu(contenedor);
    return 0;
}
               
