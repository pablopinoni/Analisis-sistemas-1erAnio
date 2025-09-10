/*
Para el ejercicio anterior, Abrir el archivo y mostrar las frases x pantalla, con cada frase
en una línea, con Interlineado.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile;
    inputFile.open("QuotesOfBjarne.txt");

    //if (!in) throw "Error opening file";
    if (!inputFile)
    {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    while (!inputFile.eof())
    {
        string line;
        getline(inputFile, line);
        cout << line << endl;
        cout << endl;
    }

    inputFile.close();

    return 0;
}
