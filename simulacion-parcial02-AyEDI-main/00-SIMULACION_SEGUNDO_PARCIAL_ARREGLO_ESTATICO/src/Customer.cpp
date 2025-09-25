#include "Customer.hpp"

Customer::Customer(string code, string name, string surname, string address) 
: code(code), name(name), surname(surname), address(address) 
{
    //usamos la lista de inicializadores que es más eficiente.
}

Customer::~Customer()   // solo a modo de prueba
{
    cout << "Cliente destruido" << endl;
}

string Customer::getCode() 
{
    return code;
}

string Customer::getName() 
{
    return name;
}

string Customer::getSurname() 
{
    return name;
}

string Customer::getAddress() 
{
    return address;
}
