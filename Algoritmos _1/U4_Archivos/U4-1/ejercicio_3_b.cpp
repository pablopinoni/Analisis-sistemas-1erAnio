#include <iostream>
#include <fstream>
#include <string>a
using namespace std;

int main()
{
    ifstream inputFile("frasesDeBjarme.txt");

    if (!inputFile)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        cout << line << endl << endl; // Interlineado
    }

    inputFile.close();
    return 0;
}
