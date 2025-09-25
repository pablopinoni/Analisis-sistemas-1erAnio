#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer 
{
    public:
        Customer(string code, string name, string surname, string address);
        ~Customer();
        string getCode();
        string getName();
        string getSurname();
        string getAddress();
    private:
        string code;
        string name;
        string surname;
        string address;
};

#endif
