/*
Para el Archivo del ejercicio (a) 
contar la cantidad de palabras que hay x línea, luego
mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void error(string message, string message2 = "")
{
    cerr << message << ' ' << message2 << endl;
    exit(EXIT_FAILURE);
}

fstream openFile(string path)
{
    fstream in;
    in.open(path);
    bool isCorruptFile = (!in.is_open() || !in.good()); 
    if (isCorruptFile) error("Error opening file");
    return in;
}

void closeFile(fstream& file)
{
    if (file.is_open()) file.close();  
}

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

void showWordsOf(fstream& file)
{
    int sentecesNumber = 0;
    int totalWords = 0;
    
    while (!file.eof())
    {
        string sentence;    
        getline(file, sentence);
        int wordsPerSentence = countWords(sentence);
        cout << "La frase número " << sentecesNumber + 1 << " tiene " << wordsPerSentence << " palabras" << endl;

        totalWords += wordsPerSentence; //totalWords = totalWords + wordsPerSentence;
        sentecesNumber++;
    }

    cout << "Cantidad total de palabras " << totalWords << endl;
    float averageOfWords = float(totalWords) / float(sentecesNumber);
    cout << "Promedio de palabras por línea " << averageOfWords << endl;
}

int main()
{
    /*
        IMPORTANTE PRESTAR ATENCIÓN AL PASO POR REFERENCIA
        EN LAS FUNCIONES showQuotesOf y closeFile
        NO SE PUEDE INCIALIZAR UN OBJETO fstream CON OTRO
        Y LUEGO PASARLO POR VALOR PORQUE fstream TIENE
        UN CONSTRUCTOR COPIA ELIMINADO, POR ESO NO SE PUEDE COPIAR
    */
    fstream textFile = openFile("QuotesOfBjarne.txt");
    showWordsOf(textFile);
    closeFile(textFile);
    return 0;
}