
#include "../include/clientes.h"
#include <iostream>
//Constructor
Cliente::Cliente(const std::string& code, const std::string& name, const std::string& address):
code(code),
name(name),
address(address){


    std::cout  << "Cliente inicializado" << std::endl;
 };

std::string Cliente::getCode()const{

    return this->code;

}


std::string Cliente::getName()const{

return  this->name;

}
std::string Cliente::getAddress()const{

return  this->address;

}