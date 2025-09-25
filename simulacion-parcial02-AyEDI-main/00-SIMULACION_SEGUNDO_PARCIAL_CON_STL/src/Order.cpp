#include <Order.hpp>

Order::Order(string code, Customer* customer)
{
    this->code = code;
    this->customer = customer;
}

void Order::attach(Article* article)
{
    this->articleList.push_front(article);
}

void Order::detach(Article* article)
{
    this->articleList.remove(article);
}

void Order::show()
{
    cout << "Cliente:" << this->customer->getName() << endl; 
    for (Article* article : articleList)
    {
        cout << "Código de Articulo:" << article->getCode() << endl; 
        cout << "Nombre de Articulo:" << article->getName() << endl; 
        cout << endl;
        cout << endl;
    } 
}


