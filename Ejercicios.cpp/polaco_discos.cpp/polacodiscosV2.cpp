#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include <iomanip>

using namespace std;

const int MAX_CLIENTES = 45;
const int MAX_MOVIMIENTOS = 50;
const string FILE_CLIENTES = "clientes_polaco_discos.csv";
const string FILE_MOVIMIENTOS = "movimientos_polaco_discos.csv";

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Movimiento {
    Fecha fecha;
    float importe;
    // más adelante: string descripcion;
};

struct Cliente {
    int codigo;
    string nombre;
    string direccion;
    string telefono;
    bool reservas;
    Movimiento movimientos[MAX_MOVIMIENTOS];
    int cantidadMovimientos;
};

// Funciones auxiliares

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

Fecha pedirFecha() {
    Fecha f;
    f.dia = validarINT("Día: ");
    f.mes = validarINT("Mes: ");
    f.anio = validarINT("Año: ");
    return f;
}

// Funciones para manejar clientes y movimientos

int buscarClientePorCodigo(Cliente clientes[], int cantidad, int codigo) {
    for (int i = 0; i < cantidad; ++i) {
        if (clientes[i].codigo == codigo) return i;
    }
    return -1;
}

float calcularSaldo(const Cliente& cliente) {
    float saldo = 0;
    for (int i = 0; i < cliente.cantidadMovimientos; ++i) {
        saldo += cliente.movimientos[i].importe;
    }
    return saldo;
}

void agregarMovimiento(Cliente& cliente) {
    if (cliente.cantidadMovimientos >= MAX_MOVIMIENTOS) {
        cout << "No se pueden agregar más movimientos a este cliente.\n";
        return;
    }
    cout << "Ingrese datos del movimiento:\n";
    Fecha f = pedirFecha();
    float importe = validarFloat("Importe (positivo = pago, negativo = cargo): ");

    cliente.movimientos[cliente.cantidadMovimientos].fecha = f;
    cliente.movimientos[cliente.cantidadMovimientos].importe = importe;
    cliente.cantidadMovimientos++;

    cout << "Movimiento agregado.\n";
}

void altaCliente(Cliente clientes[], int& cantidad) {
    if (cantidad >= MAX_CLIENTES) {
        cout << "No hay espacio para más clientes.\n";
        return;
    }

    Cliente nuevo;
    nuevo.codigo = validarINT("Código: ");
    if (buscarClientePorCodigo(clientes, cantidad, nuevo.codigo) != -1) {
        cout << "Ya existe un cliente con ese código.\n";
        return;
    }
    cout << "Nombre: ";
    getline(cin, nuevo.nombre);
    cout << "Dirección: ";
    getline(cin, nuevo.direccion);
    cout << "Teléfono: ";
    getline(cin, nuevo.telefono);
    nuevo.reservas = validarBool("¿Tiene reservas?");
    nuevo.cantidadMovimientos = 0;

    clientes[cantidad++] = nuevo;
    cout << "Cliente agregado con éxito.\n";
}

void listarClientes(const Cliente clientes[], int cantidad) {
    cout << left << setw(6) << "Cod"
         << setw(20) << "Nombre"
         << setw(25) << "Dirección"
         << setw(15) << "Teléfono"
         << setw(10) << "Reservas"
         << setw(10) << "Saldo" << "\n";
    cout << string(86, '-') << "\n";
    for (int i = 0; i < cantidad; ++i) {
        cout << setw(6) << clientes[i].codigo
             << setw(20) << clientes[i].nombre
             << setw(25) << clientes[i].direccion
             << setw(15) << clientes[i].telefono
             << setw(10) << (clientes[i].reservas ? "Sí" : "No")
             << setw(10) << fixed << setprecision(2) << calcularSaldo(clientes[i]) << "\n";
    }
}

void modificarCliente(Cliente clientes[], int cantidad) {
    int codigo = validarINT("Código a modificar: ");
    int pos = buscarClientePorCodigo(clientes, cantidad, codigo);
    if (pos == -1) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    cout << "Nuevo nombre (actual: " << clientes[pos].nombre << "): ";
    getline(cin, clientes[pos].nombre);
    cout << "Nueva dirección (actual: " << clientes[pos].direccion << "): ";
    getline(cin, clientes[pos].direccion);
    cout << "Nuevo teléfono (actual: " << clientes[pos].telefono << "): ";
    getline(cin, clientes[pos].telefono);
    clientes[pos].reservas = validarBool("¿Tiene reservas?");
    cout << "Cliente modificado.\n";
}

void eliminarCliente(Cliente clientes[], int& cantidad) {
    int codigo = validarINT("Código a eliminar: ");
    int pos = buscarClientePorCodigo(clientes, cantidad, codigo);
    if (pos == -1) {
        cout << "Cliente no encontrado.\n";
        return;
    }
    for (int i = pos; i < cantidad - 1; ++i) {
        clientes[i] = clientes[i + 1];
    }
    cantidad--;
    cout << "Cliente eliminado.\n";
}

void mostrarEstadoCuenta(const Cliente& cliente) {
    cout << "Estado de cuenta para " << cliente.nombre << " (Código: " << cliente.codigo << "):\n";
    cout << left << setw(12) << "Fecha"
         << setw(12) << "Importe" << "\n";
    cout << string(24, '-') << "\n";
    for (int i = 0; i < cliente.cantidadMovimientos; ++i) {
        Fecha f = cliente.movimientos[i].fecha;
        cout << setw(2) << (f.dia < 10 ? "0" : "") << f.dia << "/"
             << setw(2) << (f.mes < 10 ? "0" : "") << f.mes << "/"
             << setw(4) << f.anio
             << "    " << fixed << setprecision(2) << cliente.movimientos[i].importe << "\n";
    }
    cout << "Saldo total: " << fixed << setprecision(2) << calcularSaldo(cliente) << "\n";
}

void menu() {
    Cliente clientes[MAX_CLIENTES];
    int cantidad = 0;

    int opcion;
    do {
        cout << "\n--- Sistema Polaco Discos ---\n";
        cout << "1. Alta cliente\n";
        cout << "2. Listar clientes\n";
        cout << "3. Modificar cliente\n";
        cout << "4. Eliminar cliente\n";
        cout << "5. Agregar movimiento a cliente\n";
        cout << "6. Mostrar estado de cuenta cliente\n";
        cout << "0. Salir\n";
        opcion = validarINT("Opción: ");

        switch (opcion) {
            case 1: altaCliente(clientes, cantidad); break;
            case 2: listarClientes(clientes, cantidad); break;
            case 3: modificarCliente(clientes, cantidad); break;
            case 4: eliminarCliente(clientes, cantidad); break;
            case 5: {
                int codigo = validarINT("Código del cliente: ");
                int pos = buscarClientePorCodigo(clientes, cantidad, codigo);
                if (pos == -1) {
                    cout << "Cliente no encontrado.\n";
                } else {
                    agregarMovimiento(clientes[pos]);
                }
                break;
            }
            case 6: {
                int codigo = validarINT("Código del cliente: ");
                int pos = buscarClientePorCodigo(clientes, cantidad, codigo);
                if (pos == -1) {
                    cout << "Cliente no encontrado.\n";
                } else {
                    mostrarEstadoCuenta(clientes[pos]);
                }
                break;
            }
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}
