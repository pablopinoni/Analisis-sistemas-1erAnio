#pragma once
#include <string>

class Persona{
/*Atributos*/
private:
std::string nombre;
int dia;
int mes;
int anio;
int diaAct;
int mesAct;
int anioAct;
//Interfaz
public:
 
/*Métodos*/
Persona(/*Arg*/);
~Persona();



void SetNombre(std::string nom);
std::string GetNombre()const;
void SetDia(int d);
int GetDia()const;
void SetMes(int m);
int GetMes()const;
void SetAnio(int a);
int GetAnio()const;
int CalcEdad()const;
void SetDiaAct(int d);
int GetDiaAct()const;
void SetMesAct(int m);
int GetMesAct()const;
void SetAnioAct(int a);
int GetAnioAct()const;

};