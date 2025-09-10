#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

ifstream openFile(const string& path)
{
    ifstream in(path);

    if (!in)
    {
        cerr << "Error opening file: " << path << endl;
        exit(EXIT_FAILURE);
    }

    return in;
}

int countWords(const string& sentence)
{
    istringstream iss(sentence);
    string word;
    int count = 0;
    while (iss >> word)
    {
        count++;
    }
    return count;
}

void showWordsOf(ifstream& file)  // ¡Pasar por referencia!
{
    int sentenceNumber = 0;
    int totalWords = 0;
    string sentence;

    while (getline(file, sentence))
    {
        int wordsPerSentence = countWords(sentence);
        cout << "La frase número " << (sentenceNumber + 1) << " tiene " << wordsPerSentence << " palabras" << endl;

        totalWords += wordsPerSentence;
        sentenceNumber++;
    }

    cout << "\nCantidad total de palabras: " << totalWords << endl;
    if (sentenceNumber > 0)
    {
        float averageOfWords = float(totalWords) / sentenceNumber;
        cout << "Promedio de palabras por línea: " << averageOfWords << endl;
    }
    else
    {
        cout << "No hay líneas para procesar." << endl;
    }
}

int main()
{
    ifstream file = openFile("/home/pablo/ISFT/Algoritmos /U4/U4-1/frasesDeBjarme.txt");
    showWordsOf(file);
    return 0;
}
