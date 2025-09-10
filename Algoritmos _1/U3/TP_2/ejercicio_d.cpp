/*Hacer un programa en C++ que lea dos números x e y, luego hacer
la diferencia x - y; si la diferencia es menor o igual a 10, entonces
escribir todos los números comprendidos entre y y x*/

#include <iostream>
using namespace std;

int main(){

int x=14;
int y= 7;
int diferencia= x -y;

cout << x <<" - " << y << " = " << diferencia << endl;
   
  if (diferencia <=10) {
  cout << "los numeros entre " << x << " y " << y << " son: " << endl;
     
  for (int i= y+1; i < x ; i++)
      
       
    {  
       cout << i <<" ";
         }
cout << endl;
}
       else{ cout << "La diferencia es mayor a diez" << endl;

   

       }    
               











    return 0;
}
