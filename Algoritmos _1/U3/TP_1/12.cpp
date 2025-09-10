#include <iostream>
#include <string>
using namespace std;

int main() {
    // Datos del pedido
    int mesa, entrada, principal, postre;
    string mozo;
    
    // Pedir datos
    cout << "=== SISTEMA DE PEDIDOS ===" << endl;
    cout << "Numero de mesa: ";
    cin >> mesa;
    
    cout << "Nombre del mozo: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, mozo);
    
    cout << "\nCODIGOS DE PLATOS" << endl;
    cout << "Entradas: 1 (Ensalada), 2 (Sopa)" << endl;
    cout << "Principales: 3 (Bife), 4 (Pasta)" << endl;
    cout << "Postres: 5 (Flan), 6 (Helado)" << endl;
    
    cout << "\nCodigo de entrada: ";
    cin >> entrada;
    
    cout << "Codigo principal: ";
    cin >> principal;
    
    cout << "Codigo postre: ";
    cin >> postre;
    
    // Mostrar comanda
    cout << "\n=== COMANDA PARA COCINA ===" << endl;
    cout << "Mesa: " << mesa << endl;
    cout << "Mozo: " << mozo << endl;
    cout << "Entrada: ";
    if(entrada == 1) cout << "Ensalada";
    else if(entrada == 2) cout << "Sopa";
    else cout << "Codigo invalido";
    
    cout << "\nPrincipal: ";
    if(principal == 3) cout << "Bife";
    else if(principal == 4) cout << "Pasta";
    else cout << "Codigo invalido";
    
    cout << "\nPostre: ";
    if(postre == 5) cout << "Flan";
    else if(postre == 6) cout << "Helado";
    else cout << "Codigo invalido";
    
    return 0;
}