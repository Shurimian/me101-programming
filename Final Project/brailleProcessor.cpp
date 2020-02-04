// ME101 - Final Project - Text to Braille Program

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

map<char, string> brailleLookupTable;

int main()
{
    string inputFileName = " ";
    
    cout << "Enter name of input file - must be in same directory as script (ex. Input.txt)\n";
    cin >> inputFileName;

    ifstream fin(inputFileName);
    // TODO - Add ofstream directly into robot

    fin >> noskipws;
    string currentWord = " ";

    const int LINE_LENGTH = 10;
    const int LINES_PER_PAGE = 10;
    
    int currentWord = 0;
    int currentLine = 0;
    int currentPage = 0;
    int wordLength = 0;
    int currentChar = 0;

    while (fin >> currentWord)
    {
        wordLength = currentWord.length();

        for (int wordChar = 0, wordChar < wordLength, wordChar++)
        {
            currentWord[wordChar]
        }
    }

    // Process input
        // Process word
        // Check if line in space
            //Process char
        // Space

}



