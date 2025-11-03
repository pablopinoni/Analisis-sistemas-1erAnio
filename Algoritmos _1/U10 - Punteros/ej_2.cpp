#include <iostream>
using namespace std;

int main(){
    int dato=5;
    int *p1, *p2;
    p1 = &dato;
    p2=p1;
    cout << *p2;
return 0;
}
