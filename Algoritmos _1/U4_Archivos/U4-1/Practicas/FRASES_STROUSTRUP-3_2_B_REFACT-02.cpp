/*
Para el ejercicio anterior, Abrir el archivo y mostrar las frases x pantalla, con cada frase
en una línea, con Interlineado.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//STROUSTRUP:
// void error(const char* message, const char* message2 = "")
// {
//     cerr << message << ' ' << message2 << endl;
//     exit(1);
// }

void error(string message, string message2 = "")
{
    cerr << message << ' ' << message2 << endl;
    exit(EXIT_FAILURE);
}

ifstream openFile(string path)
{
    ifstream in;
    in.open(path);
    if (!in) error("Error opening file");
    return in;
}

void closeFile(ifstream& file)
{
    if (file.is_open()) file.close();  
}

void showQuotesOf(ifstream& file)
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
    /*
        IMPORTANTE PRESTAR ATENCIÓN AL PASO POR REFERENCIA
        EN LAS FUNCIONES showQuotesOf y closeFile
        NO SE PUEDE INCIALIZAR UN OBJETO ifstream CON OTRO
        Y LUEGO PASARLO POR VALOR PORQUE ifstream TIENE
        UN CONSTRUCTOR COPIA ELIMINADO, POR ESO NO SE PUEDE COPIAR
    */
    ifstream textFile = openFile("QuotesOfBjarne.txt");
    showQuotesOf(textFile);
    closeFile(textFile);
    return 0;
}