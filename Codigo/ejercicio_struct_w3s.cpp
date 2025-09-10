 /*Create a structure to represent a student. It should have the following members:

    name (string)
    age (int)
    grade (char)

Then:

    Create one variable of the structure.
    Assign values to its members.
    Print the values to the screen.

*/
#include <iostream>
#include <string>
#include<fstream>
#include <iomanip>
using namespace std;
//Enumeraciones

struct tSPersona
{ string nombre;
    int edad;
   char grado;
};




int main(){

    tSPersona persona1;
    persona1.nombre = "Lemmy";
    persona1.edad = 28;
    persona1.grado = 'C';



 tSPersona persona2;
    persona2.nombre= "Matias";
    persona2.edad= 38;
    persona2.grado= 'D';


 tSPersona persona3;
    persona3.nombre= "Cata";
    persona3.edad= 27;
    persona3.grado= 'A';


 tSPersona persona4;
    persona4.nombre= "Tony";
    persona4.edad= 24;
    persona4.grado= 'B';


cout << persona1.nombre << ", " << persona1.edad << " años, Grado: " << persona1.grado << ".\n";
cout << persona2.nombre << ", " << persona2.edad << " años, Grado: " << persona2.grado << ".\n";
cout << persona3.nombre << ", " << persona3.edad << " años, Grado: " << persona3.grado << ".\n";
cout << persona4.nombre << ", " << persona4.edad << " años, Grado: " << persona4.grado << ".\n";



    return 0;
}