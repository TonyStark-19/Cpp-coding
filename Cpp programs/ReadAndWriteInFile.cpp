#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fileName = "ReadAndWriteFile";
    string text;

    ofstream outFile(fileName);
    if (!outFile)
    {
        cout << "Error opening file for writing!" << endl;
    }

    cout << "Enter text to write to the file (type 'STOP' to end) : " << endl;
    while (true)
    {
        getline(cin, text);
        if (text == "STOP")
        {
            break;
        }
        outFile << text << endl;
    }

    outFile.close();

    cout << "Text written to " << fileName << " Successfully." << endl;

    ifstream inFile(fileName);
    if (!inFile)
    {
        cerr << "Error opening file for reading!" << endl;
    }

    cout << "Content of " << fileName << " : " << endl;
    while (getline(inFile, text))
    {
        cout << text << endl;
    }

    inFile.close();

    return 0;
}