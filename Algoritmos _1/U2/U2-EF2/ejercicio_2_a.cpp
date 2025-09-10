//* Realice un programa que lea de la entrada estándar los siguientes datos de
//una persona: Edad: dato de tipo entero. Sexo: dato de tipo carácter. Altura en
//metros: dato de tipo real. Tras leer los datos, el programa debe mostrarlos en
//*la salida estándar.
#include <iostream>
#include <string>
using namespace std;
int edad;
char sexo;
float alt;
string datosPersonales(int edad, char sexo, float alt);

int main ()
{ cout <<"Ingrese su edad (AA): " <<  endl; 
  cin >> edad;
  cout <<"Ingrese la letra corresponmdiente a su sexo ( F / M ): " <<  endl;
  cin >>  sexo;
  cout <<"Ingrese su altura con punto separando los metros de los cm (Ejemplo 1.74): " <<  endl;
  cin >>  alt;
  cout << "--------------------" << endl;

 cout << datosPersonales(sexo, edad, alt) << endl;

 return 0;

}

string datosPersonales(int edad, char sexo, float alt) {
  string resultado = "\nDatos Personales:\n";
  resultado += "Edad: " + to_string(edad) + " años\n";
  resultado += "Sexo: " + to_string(sexo) + "\n";
  resultado += "Altura: " + to_string(alt) + " metros\n";
   return resultado;
}