#include <iostream>
#include "Article.hpp"         // las rutas de directorio estaran indicadas en el archivo build.sh al momento de generar el ejecutable
#include "Customer.hpp"
#include "Order.hpp"

using namespace std;

int main()
{   
    // Crear algunos artículos:
    Article* article1 = new Article("A001", "Facial cream", 15.99);
    Article* article2 = new Article("A002", "Lipstick", 7.99);
    Article* article3 = new Article("A003", "Aqua di perfum", 9.99);

    // Crear algunos clientes:
    Customer* customer1 = new Customer("C001", "Juan", "Perez", "123 Main Street");
    Customer* customer2 = new Customer("C002", "María", "Rodriguez", "456 Secondary Street");

    // Crear pedidos para clientes:
    Order* orderCustomer1 = new Order("O001", customer1);
    orderCustomer1->add(article1);
    orderCustomer1->add(article2);
    
    Order* orderCustomer2 = new Order("O002", customer2);
    orderCustomer2->add(article2);   
    orderCustomer2->add(article3);   
    
    Order* orderCustomer3 = new Order("O003", customer1);
    orderCustomer3->add(article2);   
    orderCustomer3->add(article3);   
    
    //Mostrar pedidos:
    orderCustomer1->show(); 
    orderCustomer2->show(); 
    orderCustomer3->show();
     

    // Liberar la memoria
    delete article1;
    delete article2;
    delete article3;
    delete customer1;
    delete customer2;
    delete orderCustomer1;
    delete orderCustomer2;
    delete orderCustomer3;

    return 0;
}