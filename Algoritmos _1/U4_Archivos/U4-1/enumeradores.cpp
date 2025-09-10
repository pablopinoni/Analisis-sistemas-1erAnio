//codigo uno
#include <iostream>
using namespace std;

int main()
{
    cout << "enumeradores!" << endl;
    enum Dia {lunes=1,martes,miercoles,jueves,viernes,sabado,domingo};

    Dia hoy;
    hoy = lunes;
    cout << "Dia:" << hoy << endl;
    if (hoy == lunes)
        {
            cout << "es lunes";
        }
    else
        {
        cout << "No es lunes";
        }


    return 0;
}

//codigo dos



