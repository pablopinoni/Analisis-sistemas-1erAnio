#include <iostream>
using namespace std;

float result1(float x0, float x1, float m1);

int main() {
    float x0, x1, x2, m1, m2, b1;
    float y1;

    cout << "Ingrese el valor de X: " << endl;
    cin >> x0;
    cout << "Ingrese el valor de X1: " << endl;
    cin >> x1;
    cout << "Ingrese el valor de X2: " << endl;
    cin >> x2;
    cout << "Ingrese el valor de M1: " << endl;
    cin >> m1;
    cout << "Ingrese el valor de M2: " << endl;
    cin >> m2;
    cout << "Ingrese el valor de B: " << endl;
    cin >> b1;

    y1 = result1(x0, x1, m1);  // llamado a la funcio


    cout << "En la ecuacion y = m(x - x1) = "  << 
    m1 << "*(" << x0 << '-' << x1 << ')' << endl;
    cout << "y = " << y1 << endl;  // Corrected output operator and variable

    return 0;
}

float result1(float x0, float x1, float m1) {
    float y1 = m1 * (x0 - x1);
    return y1;
}