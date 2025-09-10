/*c. Para el Archivo del ejercicio (a) contar la cantidad de palabras que hay x línea, luego
mostrar la cantidad total y el promedio de palabras x línea.*/
#include <cstdio>
#include <iostream>
#include <fstream>//biblioteca standard de C++ q incluye ifstream y ofstream
#include <string>
using namespace std;

//Funcion contar palabras
int contarPalabras(string);

int main(){
    ifstream inputFile;
    inputFile.open("frasesDeBjarme.txt");

    if (!inputFile.is_open()){
        cerr << "No se pudo abrir el Archivo." << endl;
        return 1;
    }

  string sentence;
  int sentencesNumber=0;
  int totalWords=0;
   while (getline(inputFile, sentence)) {
      
    if (sentence.empty()){ 
       continue;
           }
    int wordsPerSentence = contarPalabras(sentence);
    cout << "la frase número " << sentencesNumber+1 << " contiene un total de " << wordsPerSentence
    << " palabras.\n"; 
   
   
    totalWords += wordsPerSentence;
        sentencesNumber++;
   
   
    }

     cout << "La cantidad total de palabras es: " << totalWords << ".\n";
     float promedioDePalabras= float(totalWords)/(sentencesNumber);
     cout << "El promedio de palabras por línea es de: " << promedioDePalabras
     << ". \n";
     

      
    inputFile.close();
    return 0;
}

int contarPalabras(string sentence){
 int i =0;
 int counter=1;
 while (i < sentence.length()) {

  if (sentence[i] == ' ')
  {
counter ++;
    }

 i++;
 
  }return counter;
}  

