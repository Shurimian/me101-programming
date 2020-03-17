// ME101 - Final Project - Text to Braille Program
// Converts text file into "machine code" for easier processing.



/* 
KEY
newLine - @
newPage - # 
space - !
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

// Map for character to machine code mappings

int main()
{
    map<char, string> braille;
    
    braille['a'] = "1 0 0 0 0 0 ";
    braille['b'] = "1 1 0 0 0 0 ";
    braille['c'] = "1 0 0 1 0 0 ";
    braille['d'] = "1 0 0 1 1 0 ";
    braille['e'] = "1 0 0 0 1 0 ";
    braille['f'] = "1 1 0 1 0 0 ";
    braille['g'] = "1 1 0 1 1 0 ";
    braille['h'] = "1 1 0 0 1 0 ";
    braille['i'] = "0 1 0 1 0 0 ";
    braille['j'] = "0 1 0 1 1 0 ";
    braille['k'] = "1 0 1 0 0 0 ";
    braille['l'] = "1 1 1 0 0 0 ";
    braille['m'] = "1 0 1 1 0 0 ";
    braille['n'] = "1 0 1 1 1 0 ";
    braille['o'] = "1 0 1 0 1 0 ";
    braille['p'] = "1 1 1 1 0 0 ";
    braille['q'] = "1 1 1 1 1 0 ";
    braille['r'] = "1 1 1 0 1 0 ";
    braille['s'] = "0 1 1 1 0 0 ";
    braille['t'] = "0 1 1 1 1 0 ";
    braille['u'] = "1 0 1 0 0 1 ";
    braille['v'] = "1 1 1 0 0 1 ";
    braille['w'] = "0 1 0 1 1 1 ";
    braille['x'] = "1 0 1 1 0 1 ";
    braille['y'] = "1 0 1 1 1 1 ";
    braille['z'] = "1 0 1 0 1 1 ";
    braille['1'] = "1 0 0 0 0 0 ";
    braille['2'] = "1 1 0 0 0 0 ";
    braille['3'] = "1 0 0 1 0 0 ";
    braille['4'] = "1 0 0 1 1 0 ";
    braille['5'] = "1 0 0 0 1 0 ";
    braille['6'] = "1 1 0 1 0 0 ";
    braille['7'] = "1 1 0 1 1 0 ";
    braille['8'] = "1 1 0 0 1 0 ";
    braille['9'] = "0 1 0 1 0 0 ";
    braille['0'] = "0 1 0 1 1 0 ";
    braille[','] = "0 1 0 0 0 0 ";
    braille['.'] = "0 1 0 0 1 1 ";
    
    string inputFileName = " ";
    
    cout << "Enter name of input file - must be in same directory as script (ex. Input.txt)\n";
    cin >> inputFileName;

    ifstream fin(inputFileName);

    if (!fin)
    {
        cout << "File not found.\n";
        return EXIT_FAILURE;
    }

    ofstream fout("output.txt");
    // TODO - Add ofstream directly into robot

    const int LINE_LENGTH = 20;
    const int LINES_PER_PAGE = 10;
    
    string currentWord = " ";
    int lineNumber = 0;
    int pageNumber = 0;

    while (fin >> currentWord)
    {   
        int wordLength = 0;
        int currentChar = 0;
        char separatorSymbol = '!';
        wordLength = currentWord.length();
        if (wordLength > LINE_LENGTH)
        {
            cout << "Error: words must not exceed the line character length of " << LINE_LENGTH << endl;
            return EXIT_FAILURE;
        }

        if (wordLength + currentChar > LINE_LENGTH)
        {
            lineNumber++;
            currentChar = 0;
            separatorSymbol = '@';
        }

        if (lineNumber > LINES_PER_PAGE)
        {
            pageNumber++;
            lineNumber = 0;
            separatorSymbol = '#';
        }

        fout << separatorSymbol << endl;


        for (int wordChar = 0; wordChar < wordLength; wordChar++)
        {
            char processingChar = tolower(currentWord[wordChar]);
            fout << processingChar << " "; 
            fout << braille[processingChar] << endl;
            currentChar++;
        }
        currentChar++;
    }
    
    fout.close();
    cout << "Done!";
    return EXIT_SUCCESS;
}

