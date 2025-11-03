#pragma once

class Rectangulo{
/*Atributos*/
private:
float h;
float b;
//Interfaz
public:
 
/*Métodos*/
Rectangulo(/*Arg*/);
~Rectangulo();



void SetAltura(float );
float GetAltura()const;
void SetBase(float b);
float GetBase ()const;
float Area()const;
float Perimetro()const;


};