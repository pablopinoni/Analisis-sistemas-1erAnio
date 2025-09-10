#include <iostream>
using namespace std;

int main() {
    int opcion;
    double valor, resultado;

    cout << "CONVERSOR DE UNIDADES" << endl;
    cout << "1. Centímetros a pulgadas" << endl;
    cout << "2. Celsius a Farenheit" << endl;
    cout << "3. Libras a kilogramos" << endl;
    cout << "Elige una opción (1-3): ";
    cin >> opcion;

    if (opcion == 1) {
        cout << "Ingresa la cantidad en centímetros: ";
        cin >> valor;
        resultado = valor / 2.54;
        cout << valor << " cm = " << resultado << " pulgadas" << endl;
    } else {
        if (opcion == 2) {
            cout << "Ingresa la temperatura en grados Celsius: ";
            cin >> valor;
            resultado = (valor * 9 / 5) + 32;
            cout << valor << " °C = " << resultado << " °F" << endl;
        } else {
            if (opcion == 3) {
                cout << "Ingresa la cantidad en libras: ";
                cin >> valor;
                resultado = valor * 0.453592;
                cout << valor << " libras = " << resultado << " kilogramos" << endl;
            } else {
                cout << "Opción no válida." << endl;
            }
        }
    }

    return 0;
}
