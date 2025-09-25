#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>
#include <string>

using namespace std;

class Article 
{
    public:
        Article(string code, string name, float price);
        ~Article();
        string getCode();
        string getName();
        float getPrice();
    private:
        string code;
        string name;
        float price;
};

#endif
