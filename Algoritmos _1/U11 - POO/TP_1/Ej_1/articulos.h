#pragma once

class Articulo{
/*Atributos*/
//Encapsulamiento
private:
float costoBase;
//Interfaz
public:
/*Métodos*/
Articulo(/*Arg*/);
~Articulo();
void SetCostoBase(float CB);
float GetCostoBase()const;
float PVPMayor()const;
float PVPDetail()const;


};