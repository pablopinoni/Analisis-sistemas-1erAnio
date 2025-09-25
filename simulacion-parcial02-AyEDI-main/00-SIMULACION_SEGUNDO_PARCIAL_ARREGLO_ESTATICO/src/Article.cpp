#include "Article.hpp" 
#include <string>
#include <iostream>

using namespace std;

//https://es.stackoverflow.com/questions/80314/duda-con-lista-de-inicializadores-en-c
Article::Article(string code, string name, float price) 
: code(code), name(name), price(price) 
{
    //usamos anteriormente la lista de inicializadores para cada dato.
}

Article::~Article()   // solo a modo de prueba
{
    cout << "Articulo destruido" << endl;
}

string Article::getName()
{
    return name;
}

string Article::getCode()
{
    return code;
}

float Article::getPrice()
{
    return price;
}

