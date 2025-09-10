 #include <iostream>
#include <string>
#include<fstream>
#include <iomanip>
using namespace std;

int main (){

typedef int  tArray[5];
tArray listado ={1,2,3,4,5};

for (int i = 0; i < 5; i++)
{
 cout << listado[i] << endl;

}



    return 0;
}