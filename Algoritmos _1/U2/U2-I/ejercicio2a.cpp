#include <iostream>
using namespace std;

int main() 
{
    // Ejercicio 2a - Uso de int resultado erróneo
    int a = 5;
    int b = 4;
    int c = 2.5;  // 2.5 es tomado como 2 al ser int
    float c_f = 2.5;

    int result = a * b * c;
    
    cout << "El volumen de la habitación, calculado con int, es de:  " 
         << result << " metros cúbicos." << endl; 
    
    //  float 
    
    float result2  = a * b * c_f;
    
    cout << "El volumen de la habitación, calculado con float, es de:  " 
         << result2 << " metros cúbicos." << endl;
    
    return 0;
}