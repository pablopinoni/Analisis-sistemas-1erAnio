// Hacer un programa en C++ que pida dos números enteros. El programa pedirá de nuevo el
//segundo número mientras no sea mayor que el primero. El programa terminará
//escribiendo los dos números.



#include <iostream>
using namespace std;


int main () {
///Declaro Variables
int n1;
int n2;


cout << "Ingrese un numero entero:  " <<endl;
cin >> n1;
do {
cout << "Ingrese un segundo numero entero: " << endl;
cin >> n2;
  }  
 

while ( n1 > n2 + 1); {
    cout << "Ingrese un segundo numero entero: " << endl;
    cin >> n2;
       

  }

  if ( n2 > n1); {

    cout << "¡¡¡Correcto!!!\n" << n1 << " y " << n2 << "." <<  endl;
    return 0;
  }


return 0;


}