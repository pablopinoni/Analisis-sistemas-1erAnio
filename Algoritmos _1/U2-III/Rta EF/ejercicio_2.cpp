#include <iostream>
using namespace std;

//Funciones
int Sumar();
int Restar();
int Multiplicar();
float Dividir();


// Funciones auxiliares

void MostrarMenuSuma();
void MostrarMenuResta();
void MostrarMenuMutl();
void MostrarMenuDiv();
void clearConsole();



int main() 
{

int opcion;

       
    do{    
             
     clearConsole();

            cout << "\n\n\tCALCULADORA\t\n" << endl;
            cout << "Ingrese una opción válida (0-4): " << endl; 
            cout << "Seleccione una operación; " << endl;
            cout << "1. Sumar" << endl;
            cout << "2. Restar" << endl;
           cout << "3. Multiplicar" << endl;
           cout << "4. Dividir" << endl;
           cout << "0. Salir" << endl;
           cout << "Ingrese una opción válida (0-4): ";
           cin >> opcion;
           
    
         
          switch (opcion){
          case 1:
              MostrarMenuSuma(); 
           break;

          case 2:
            MostrarMenuResta(); 
            break;

          case 3:
           MostrarMenuMutl() ; 
            break;

         case 4:
           MostrarMenuDiv(); 
           break;
    
       case 0:   
         cout << "SAliendo" << endl;
         break;    
         
    default: cout << "Opcion incorrecta. " << endl;
         break;
          }

    }
            
    
    while ( opcion !=0);

    return 0;

    cin.ignore();
    cin.get();
    

    
}




void MostrarMenuSuma()  {
  int num1, num2, resultado;

  

    cout << "Ingrese primer número: " << endl;
    cin >> num1;
    cout << "Ingrese segundo numero:" << endl;
    cin >> num2;

    resultado = (num1 + num2);

  cout << " La suma de " << num1 << " y " << num2 << " es " << resultado << endl;

  cin.ignore();
  cin.get();
  
      
}

void MostrarMenuResta(){
    int num1, num2, resultado;
   
     
  
   cout << "Ingrese primer numero: " << endl;
   cin >> num1;
   cout << "Ingrese segundo numero: "  << endl;
   cin >> num2;
  
    resultado = (num1 - num2);
  
    cout << " La Resta de " << num1 << " y " << num2 << " es " << resultado << endl;
  
  
    cin.ignore();
    cin.get();

  }



void MostrarMenuMutl(){
    int num1, num2;
   
      
  
   cout << "Igrese primer numero:" << endl;
   cin >> num1;
   cout << "Igrese segundo numero:"<< endl;
   cin >> num2;
  
   int resultado = (num1 * num2);
  
    cout << " EL Producto de " << num1 << " y " << num2 << " es " << resultado << endl;
  
    cin.ignore();
    cin.get();
    
  }


  void MostrarMenuDiv(){
    float num1, num2, resultado;
   
   
   cout << "Ingrese el primer numero:\n" << endl;            
    cin >>  num1;
    cout << "Igrese segundo numero:\n" << endl;
    cin >> num2;

    
      if ( num2  == 0) {
     cout << "No se puede dividir por cero." << endl;
     cin.ignore();
     cin.get();
             }
    
      else {
  
    resultado = (num1 /num2);

  cout << " EL Cociente entre " << num1 << " y " << num2 << " es " << resultado << endl;
  cin.ignore();
  cin.get();
      }
  }
 
  void clearConsole() { 
    #ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}