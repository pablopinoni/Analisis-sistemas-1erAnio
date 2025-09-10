/* menú de Opciones de 4 productos a) Simple b)medio
c)calidad d)Premiun ,luego nos deberá mostrar en menú de tipo de envio: 1)
normal 2) express 3) Fast Delivery.
A posteriori deberá mostrar x consola el producto seleccionado y el tipo de
envío que eligió.
PD. Usar Funciones, manteniendo un Main lo “mas pequeño posible”,
desacoplando las funcionalidades. Trabajar con la visibilidad de los operadores
vistos, while Swtch If … . */

#include <iostream>
using namespace std;

// enumeraciones 
enum producto { simple=1, medio, calidad, premium};
enum envio { normal=1, express, fastDelivery};

// Funciones    

//string pedido();
void menuProductos();
void menuEnvios();
void armarCadena();

//Variables globales
 typedef string tOrden;
 tOrden envio, producto;
 int envioElegido =0;
 int productoElegido=0;


int main() {
 
  //Llamado a las funciones    
    menuProductos();
    menuEnvios();
    armarCadena();

cout << "\n========================================================" << endl;
cout << "\n\tProducto: " << producto << "\n\tEnvío: " << envio << ".\n"<< endl;






    return 0;
}




//Declaracion de las funciones

void menuProductos() {

 cout << "\n========================================================" << endl;
cout << "Seleccione Producto: " << endl;
    cout << "Simple (1)" << endl; 
    cout << "Medio(2)" << endl; 
    cout << "Calidad (3)" << endl; 
    cout << "Premium (4)" << endl; 
    cin  >> productoElegido;

    switch (productoElegido){
     case simple:
           cout << "Has elegido nivel normaL." << endl;
            break;
        case medio:
            cout << "Has elegido nivel medio." << endl;
            break;
        case calidad:
            cout << "Has elegido nivel calidad. " << endl;
            break;
        case premium:
            cout << "Has elegido nivel premium. " << endl;
            break;
        default:
            cout << "Opción inválida." << endl;
            break;
    }
}


void menuEnvios() {
   
    
       cout << "\n========================================================" << endl;
       cout << "Seleccione envío: " << endl;      
       cout << "Normal(1)" << endl; 
       cout << "Express (2)" << endl; 
       cout << "Fast Delivery (3)" << endl; 
       cin  >> envioElegido;
   
       switch (envioElegido){
        case normal:
              cout << "Has elegido envio normal." << endl;
               break;
           case express:
               cout << "Has elegido envio express." << endl;
               break;
           case fastDelivery:
               cout << "Has elegido envio fast delivery. " << endl;
               break;
           
           default:
               cout << "Opción inválida." << endl;
               break;
       }
   }






void armarCadena(){
    switch (productoElegido) {
        case simple: producto = "Simple"; break;
        case medio: producto = "Medio"; break;
        case calidad: producto = "Calidad"; break;
        case premium: producto = "Premium"; break;
        default: producto = "Desconocido"; break;
    }

      switch (envioElegido) {
        case normal: envio = "Normal"; break;
        case express: envio = "Express"; break;
        case fastDelivery: envio = "Fast Delivery"; break;
        default: envio = "Desconocido"; break;
    }
}
