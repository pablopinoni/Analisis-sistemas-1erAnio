/*
Para el Archivo del ejercicio (a) 
contar la cantidad de palabras que hay x línea, luego
mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Prototipo de variables
ifstream openFile(string);
int ContadorDePalabras(string frase);
void showPalabrasOf(ifstream file);



int main()
{
    showPalabrasOf(openFile("/home/pablo/ISFT/Algoritmos /U4/U4-1/frasesDeBjarme.txt"));
    return 0;
}



ifstream openFile(string)

{
    ifstream in;
    in.open("/home/pablo/ISFT/Algoritmos /U4/U4-1/frasesDeBjarme.txt");

    if (!in) // SAlida avisando que no se pudo abrir el archivo
    {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    return in;
}
ifstream file;

    while (i < frase.length())
    {
        if (frase[i] == ' ')
        {
            counter++;
        }
        i++;
    
    return counter;
}

void showPalabrasOf(ifstream file)
{
    int sentecesNumber = 0;
    int totalPalabras = 0;

    while (!file.eof())
    {
        string frase;
        getline(file, frase);
        int palabrasPorFrase = ContadorDePalabras(frase);
        cout << "La frase número " << sentecesNumber + 1 << " tiene " << palabrasPorFrase << " palabras" << endl;

        totalPalabras += palabrasPorFrase;
        sentecesNumber++;
    }

    cout << "Cantidad total de palabras " << totalPalabras << endl;
    float promedioDePalabras = float(totalPalabras) / float(sentecesNumber);
    cout << "Promedio de palabras por línea " << promedioDePalabras << endl;
}
