#pragma once
#include <iostream>
#include <string>

using std::string;

class Customer{

   public:
         Customer(string code, string name, string surname, string address );
        
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