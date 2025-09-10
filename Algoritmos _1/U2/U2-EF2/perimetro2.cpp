#include <iostream>
#include <limits>
using namespace std;

// Function prototypes
void perimetroCuad();
void perimetroRect();
void perimetroTrian();
void pauseConsole();
void clearConsole();
// Inicamos el main
int main() {
    int opcion;
    bool repetir = true;

    do {
        clearConsole();

        cout << "\n\n\t\t\tMENU in.ignore(numeric_limits<streamsize>::max(), '\n');.ignore(numeric_limits<streamsize>::max(), '\n');ALCULAR PERIMETRO" << endl;
        cout << "\t\t\t-----------------------" << endl;
        cout << "\n\t1. Cuadrado" << endl;
        cout << "\t2. Rectangulo" << endl;
        cout << "\t3. Triangulo" << endl;
        cout << "\t0. SALIR" << endl;

        cout << "\n\tIngrese una opcion: ";
        
        // Validar opcion
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar numeros demasido grandes
            cout << "\tEntrada inválida. Ingrese un número valido: "; // Salida por comsolaopcion incorrecta
        }
         // Elegir tipoi de figura para clacualr perimetro
        switch (opcion) {
            case 1:
                perimetroCuad();
                break;
            case 2:
                perimetroRect();
                break;
            case 3:
                perimetroTrian();
                break;
            case 0:
                repetir = false;
                break;
            default:
                cout << "\n\tOpción inválida. Intente nuevamente." << endl;
                pauseConsole();
                break;
        }
    } while (repetir);

    return 0;
}
// Inincializacion de funciones
void perimetroCuad() { //perimetro del cuadrado
    clearConsole();
    int lado;
    int resultado;

    cout << "\n\t Perimetro de Cuadrado";
    cout << "\n\t========================";
    
    cout << "\n\tIngrese longitud de un lado: ";
    while (!(cin >> lado)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tEntrada inválida. Ingrese un número: ";
    }

    resultado = lado * 4;
    cout << "\t--------------------------" << endl;
    cout << "\tResultado: " << resultado << endl;

    pauseConsole();
}

void perimetroTrian() {
    clearConsole();
    int lado1, lado2, lado3;
    int resultado;

    cout << "\n\tPerimetro Triangulo";
    cout << "\n\t====================";
    
    cout << "\n\tIngrese longitud lado 1: ";
    while (!(cin >> lado1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tEntrada inválida. Ingrese un número: ";
    }
    
    cout << "\tIngrese longitud lado 2: ";
    while (!(cin >> lado2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tEntrada inválida. Ingrese un número: ";
    }
    
    cout << "\tIngrese longitud lado 3: ";
    while (!(cin >> lado3)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tEntrada inválida. Ingrese un número: ";
    }

    resultado = lado1 + lado2 + lado3;
    cout << "\t--------------------------" << endl;
    cout << "\tResultado: " << resultado << endl;

    pauseConsole();
}

void perimetroRect() {
    clearConsole();
    int largo, ancho;
    int resultado;

    cout << "\n\tPerimetro Rectangulo";
    cout << "\n\t=====================";
    
    cout << "\n\tIngrese el largo: ";
   
    
    cout << "\tIngrese el ancho: ";
   
    cout << "\t--------------------------" << endl;
    cout << "\tResultado: " << resultado << endl;

    pauseConsole();
}
// Funciones auxiliares

void clearconsole ()
{        
  //system("cls"); // Para Windows
   system("clear"); // Para Linux/Mac
}

  //system("pause"); // Para Windows
  void pauseConsole() {
    cout << "\n\tPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
  //system("pause"); // Para Windows 
 }

