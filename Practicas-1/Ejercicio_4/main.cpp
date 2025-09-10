//Plantila Menú de Opciones
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Prototipos de las funciones
void mostrarMenuPrincipal();
void mostrarMenuOperacionesBasicas();
void mostrarMenuOperacionesVariadas();

// Funciones del submenú operaciones
void sumar(); 
void restar();
void multiplicar();
void dividir();

// Funciones del submenú Operaciones Variadas
 void convertirNumeroADia();
 void sumarPrimerosNumeros();
 void factorial();
 void invertirNumero4Cifras();

 int main()
 {
     mostrarMenuPrincipal();
     return 0;
}

void pauseConsole()
{
    cin.ignore();
    cin.get();
}

void clearConsole()
{
    #ifdef __unix__
        system("clear");
    #elif __APPLE__   
        system("clear");    
    #elif defined(_WIN32)  ||  defined(WIN32) ||  defined(WIN64) 
        system("cls"); 
    #endif //Defined
    }

void mostrarMenuPrincipal()
{
    int opcion;
    bool repetir = true;

    do
    {
        clearConsole();
       
       cout << "\n\n\t\t\t  ||MENU PRINCIPAL||" << endl;
       cout << "\t\t            ==============" << endl;
       cout << "\n\t1. Operaciones basicas" << endl;
       cout << "\t2. Operaciones variadas" << endl;
       cout << "\t0. SALIR" << endl;

       cout << "\n\tIngrese una opcion  ";
       cin >> opcion;

       switch (opcion)
       {
            case 1: 
                 mostrarMenuOperacionesBasicas();
                 break;

            case 2:      
                 mostrarMenuOperacionesVariadas(); 
                 break;
                 
            case 0:       
                 repetir = false;
                 break;            
        }
    } while (repetir);
}    
 
//Definiciones de las Funciones
void mostrarMenuOperacionesBasicas()
{
     int opcion;
     bool repetir = true;

    do
    {
        clearConsole();

        cout << "\n\n\t\t\tMENU OPERACIONES BASICAS" << endl;
        cout << "\t\t-----------------" << endl;
        cout << "\n\t1. Sumar" << endl;
        cout << "\t2. Restar" << endl;
        cout << "\t3. Multiplicar" << endl;
        cout << "\t4. Dividir." << endl;
        cout << "\t0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion:  ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                 sumar();
                 break;

            case 2:
                 restar();
                 break;
                 
            case 3:
                 multiplicar();
                 break;
                 
            case 4:
                 dividir();
                 break;  
       
            case 0:
                 repetir = false;
                 break;   
        }        
     } while (repetir);
}   

void mostrarMenuOperacionesVariadas()
{
    int opcion;
    bool repetir = true;

    do
    {
        clearConsole();
       
       cout << "\n\n\t\t\tMENU OPERACIONES VARIADAS" << endl;
       cout << "\t\t------------" << endl;
       cout << "\n\t1. Numero y dia" << endl;
       cout << "\t2. Suma de los primeros n numeros naturales" << endl;
       cout << "\t3. Factorial de un numero" << endl;
       cout << "\t4. Invertir un numero de 4 cifras" <<endl;
       cout << "\t0. REGRESAR" << endl;
      
       cout << "\n\tIngrese una opcion  ";
       cin >> opcion;

       switch (opcion)
       {
            case 1: 
                 convertirNumeroADia();
                 break;

            case 2:      
                 sumarPrimerosNumeros(); 
                 break;
          
            case 3:      
                 factorial(); 
                 break;

            case 4:      
                 invertirNumero4Cifras();                         
                 break;   
   
            case 0:       
                 repetir = false;
                 break;            
        }
    } while (repetir);
}    
    
void sumar()
{
     clearConsole();
     
     int numero1, numero2;
     float resultado;

    cout << "\n\tSUMA DE DOS NUMEROS";
    cout << "\n\t===================";
    
    cout << "\tIngrese primer numero:  ";
    cin >> numero1;

    cout << "\tIngrese segundo numero:  ";
    cin >> numero2;

    cout << "\t----------------" << endl;
    resultado = numero1 + numero2; 
    cout << "\tResultado: "  << resultado << endl;

    pauseConsole();
}

void restar()
{
      clearConsole();

     int numero1, numero2;
     float resultado;

      cout << "\n\tRESTA DE DOS NUMEROS";
      cout << "\n\t=====================\n";
      
      cout << "\n|tIngrese primer numero: ";
      cin >> numero1;

      cout << "\n\tIngrese segundo numero: ";
      cin >> numero2;

      cout << "\t--------------------------" <<endl;
      resultado = numero1 - numero2;
      cout << "\tResultado: " << resultado << endl;

      pauseConsole();
}

void multiplicar()
{
      clearConsole();

     int numero1, numero2;
     float resultado;

      cout << "\n\tPRODUCTO DE DOS NUMEROS";
      cout << "\n\t=========================\n";
      
      cout << "\n\tIngrese primer numero: ";
      cin >> numero1;

      cout << "\n\tIngrese segundo numero: ";
      cin >> numero2;

      cout << "\t--------------------------" <<endl;

      
      resultado = numero1 * numero2;
      cout << "\tResultado: " << resultado << endl;

      pauseConsole();
}

void dividir()
{
      clearConsole();

     int numero1, numero2;
     float resultado;

      cout << "\n\tCOCIENTE DE DOS NUMEROS";
      cout << "\n\t========================\n";
      
      cout << "\n\tIngrese primer numero: ";
      cin >> numero1;

      cout << "\n\tIngrese segundo numero: ";
      cin >> numero2;

      cout << "\t--------------------------" <<endl;
      
      if (numero2 ==0)
      {
          cout << "\tResultado: no se puede dividir por cero." << endl;
      }
     else
     {
      resultado = numero1 / (numero2 * 1.0);
      cout << "\tResultado: " << resultado << endl;
     }

      pauseConsole();
}

void convertirNumeroADia()
{     
     clearConsole();

     cout << "\n\tCONVIERTE NUMERO A DIA     ";
     cout << "\n\t=======================\n";
     
     int dia;
     cout << "\tIngrese el numero de dia: "; 
     cin >>  dia; // 1,2,3,4,5,6,7

     switch (dia) // En caso de que la variable DIA tome el valor:
     {
          case 1 :
              cout << "\tLunes" <<endl;
              break;   

          case 2:
              cout << "\tMartes" <<endl;
              break;        

          case 3: 
              cout << "\tMiercoles" <<endl;
              break;   
              
          case 4:
              cout << "\tJueves" <<endl;
              break;   
              
          case 5:
              cout << "\tViernes" <<endl;
              break;   
          
          case 6:
              cout << "\tSabado" <<endl;
              break;   
              
          case 7:
              cout << "\tDomingo" <<endl;
              break;   
     }

          pauseConsole();       
} 

void sumarPrimerosNumeros()
{
    clearConsole();

    int n;
    int suma;

    cout <<"\n\tSUMA DE LOS PRIMEROS N NUMEROS";
    cout << "\n\t=============================="; 

    cout << "\n\tIngrese numero n: ";
    cin >> n;

    suma = n * (n + 1) / 2;

    cout <<"\tLa suma de los primeros n numeros es = " << suma << endl;
   
    pauseConsole();
}

void factorial()
{
     clearConsole();

     int numero,i;
     float factorial; 

     cout <<"\n\tFACTORIAL DE UN NUMERO";
     cout << "\n\t=============================="; 

     cout << "\n\tIngrese numero: ";
     cin >> numero;

     factorial = 1;
     for (i = 1; i <= numero; i++)
     { 
          factorial =  factorial * i;
     }

     cout << "\t" << numero << "! = " << factorial << endl;

pauseConsole();
}

void invertirNumero4Cifras()
{
     clearConsole();

     int nume;
     int u, d, c, um;
     int a, b;
     int resultado;

     cout <<"\n\tINVERTIR NUMERO DE 4 CIFRAS";
     cout << "\n\t=============================="; 

     cout << "\n\tIngrese un numero de cuatro cifras: ";
     cin >> nume; // 1234

     um = nume / 1000; // 1
     a= nume / 100;   // 12
     c = a % 10;     // 2
     b = nume /10;  // 123
     d = b % 10;   // 3
     u = nume % 10; // 4
     resultado = u * 1000 + d * 100 + c * 10 + um;  

     cout << "\t" << u << " " << d << " " <<  c << " " << um << endl; 
     cout <<"\tEl numero invertido es: " << resultado << endl;

     pauseConsole();

}