#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>
#include "Article.hpp"
#include "Customer.hpp"
#include <string>

#define MAX_ITEMS 256

using namespace std;

class Order
{
    public:
        Order(string code, Customer* customer);
        ~Order(); //Destructor
        string getCode();
        void add(Article* _article);
        void show();
    private:
        string code;
        Customer* customer;
        Article* articles[MAX_ITEMS];  // Arreglo fijo de MAX_ITEMS punteros a Article
        int numArticles;
};

#endif