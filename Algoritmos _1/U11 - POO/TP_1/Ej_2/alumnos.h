#pragma once
#include <string>



class Alumno{
/*Atributos*/
//Encapsulamiento
private:
std::string cedula;
std::string nombre;
float nota_1;
float nota_2;
float nota_3;
 

//Interfaz
public:
/*Métodos*/
Alumno(/*Arg*/);
~Alumno();
void SetCedula(std::string ced);
std::string GetCedula()const;
void SetName(std::string nom); 
std::string GetName()const;
void SetNota1(float n1);
float GetNota1()const;
void SetNota2(float n2);
float GetNota2()const;
void SetNota3(float n3);
float GetNota3()const;
float NotaFinal()const;
std::string AproRepro()const;

};