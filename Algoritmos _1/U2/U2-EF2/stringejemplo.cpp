#include <iostream>
#include <string>
using namespace std;

int main() {
    string entradaCompleta;
    string parte1, parte2;
    
    cout << "Ingrese dos palabras separadas por espacio: ";
    getline(cin, entradaCompleta); // Lee toda la línea
    
    // Alternativamente para leer directamente las dos partes:
    // cin >> parte1 >> parte2;
    // entradaCompleta = parte1 + " " + parte2;
    
    cout << "Cadena combinada: " << entradaCompleta << endl;
    
    return 0;
}
