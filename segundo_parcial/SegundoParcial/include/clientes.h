#pragma once
#include <string>

class Cliente{
    //Atributos
    private:
    std::string code;
    std::string name;
    std::string address;

    //Metodos 
    public:
    //Cosntructor
    Cliente(const std::string& code, const std::string& name, const std::string& address);
    //Destructor
   // ~Cliente(); no usamos memoria dinámica en esta versión comparar con version de nico

    //Getters
    std::string getCode()const;
    std::string getName()const;
    std::string getAddress()const;

};