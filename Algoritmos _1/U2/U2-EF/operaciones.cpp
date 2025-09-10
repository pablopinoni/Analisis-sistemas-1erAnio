#include <iostream>
#include <cstdlib>
using namespace std;


int main() {
    float num1, num2;
    char op;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el operador (+, -, *, /): ";
    cin >> op;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    switch(op) {
        case '+':
            cout << "Resultado Suma: " << num1 + num2 <<endl;
            break;
        case '-':
            cout << "Resultado Resta: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Resultado Multiplicacion: " << num1 * num2 << endl;
            break;
        case '/':
            if(num2 != 0)
                cout << "Resultado Multiplicacion: " << num1 / num2<< endl;
            else
                cout << "Error: No se puede dividir por cero";
            break;
        default:
            cout << "Operador invalido!";
    }

    return 0;
}