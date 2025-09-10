/*
Para el ejercicio anterior, Abrir el archivo y mostrar las frases x pantalla, con cada frase
en una línea, con Interlineado.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream openFile(string path)
{
    ifstream in;
    in.open(path);

    if (!in) 
    {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    return in;
}

void showQuotesOf(ifstream file)
{
    while (!file.eof())
    {
        string line;
        getline(file, line);
        cout << line << endl;
        cout << endl;
    }
}

int main()
{
    showQuotesOf(openFile("QuotesOfBjarne.txt"));
    return 0;
}