/*
Para el Archivo del ejercicio (a) 
contar la cantidad de palabras que hay x línea, luego
mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countWords(string sentence)
{
    int i = 0; 
    int counter = 1;

    while (i < sentence.length())
    {
        if (sentence[i] == ' ')
        {
            counter++;
        }
        i++;
    }
    return counter;
}

int main()
{
    ifstream in;
    in.open("QuotesOfBjarne.txt");
    if (!in){ cerr << "Error opening file" << endl; exit(EXIT_FAILURE); }

    int sentecesNumber = 0;
    int totalWords = 0;
    
    while (!in.eof())
    {
        string sentence;
        getline(in, sentence);
        int wordsPerSetence = countWords(sentence);
        cout << "La frase número " << sentecesNumber+1 << " tiene " << wordsPerSetence << " palabras" << endl;

        totalWords += wordsPerSetence;
        sentecesNumber++;
    }

    cout << "Cantidad total de palabras " << totalWords << endl;
    float averageOfWords = float(totalWords) / float(sentecesNumber);
    cout << "Promedio de palabras por línea " << averageOfWords << endl;

    return 0;
}