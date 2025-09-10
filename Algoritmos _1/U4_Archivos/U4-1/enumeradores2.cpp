#include <iostream>
using namespace std;

typedef enum { enero, febrero, marzo, abril, mayo,
   junio, julio, agosto, septiembre, octubre,
   noviembre, diciembre } tMes;

typedef enum { lunes, martes, miercoles, jueves,
   viernes, sabado, domingo } tDiaSemana;

string cadMes(tMes mes);
string cadDia(tDiaSemana dia);

int main() {
   tDiaSemana hoy = lunes;
   int dia = 04;
   tMes mes = enero;
   int anio = 2021;
// Mostramos la fecha
   cout << "Hoy es: " << cadDia(hoy) << " " << dia
        << " de " << cadMes(mes) << " de " << anio
        << endl;

   cout << "Pasada la medianoche..." << endl;
   dia++;
   int i = int(hoy);
   i++;
   hoy = tDiaSemana(i);

   // Mostramos la fecha
   cout << "Hoy es: " << cadDia(hoy) << " " << dia
        << " de " << cadMes(mes) << " de " << anio
        << endl;

   return 0;
}
string cadMes(tMes mes) {
   string cad = "error";

   if (mes == enero) {
      cad = "enero";
   }
   if (mes == febrero) {
      cad = "febrero";
   }
   //.
   if (mes == diciembre) {
      cad = "diciembre";
   }

   return cad;
}
string cadDia(tDiaSemana dia){
   string cad;

  if (dia == lunes) {
      cad = "lunes";
   }
   if (dia == martes) {
      cad = "martes";
   }
  //..
   if (dia == domingo) {
      cad = "domingo";
   }

   return cad;
}