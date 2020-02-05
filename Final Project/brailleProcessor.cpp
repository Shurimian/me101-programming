// ME101 - Final Project - Text to Braille Program





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

int main()
{
    map<char, string> braille;
    
    braille['a'] = "100000";
    braille['b'] = "110000";
    braille['c'] = "100100";
    braille['d'] = "100110";
    braille['e'] = "100010";
    braille['f'] = "110100";
    braille['g'] = "110110";
    braille['h'] = "110010";
    braille['i'] = "010100";
    braille['j'] = "010110";
    braille['k'] = "101000";
    braille['l'] = "111000";
    braille['m'] = "101100";
    braille['n'] = "101110";
    braille['o'] = "101010";
    braille['p'] = "111100";
    braille['q'] = "111110";
    braille['r'] = "111010";
    braille['s'] = "011100";
    braille['t'] = "011110";
    braille['u'] = "101001";
    braille['v'] = "111001";
    braille['w'] = "010111";
    braille['x'] = "101101";
    braille['y'] = "101111";
    braille['z'] = "101011";
    braille['1'] = "100000";
    braille['2'] = "110000";
    braille['3'] = "100100";
    braille['4'] = "100110";
    braille['5'] = "100010";
    braille['6'] = "110100";
    braille['7'] = "110110";
    braille['8'] = "110010";
    braille['9'] = "010100";
    braille['0'] = "010110";
    braille[','] = "010000";
    braille['.'] = "010011";
    
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
            fout << processingChar; 
            fout << braille[processingChar] << endl;
            currentChar++;
        }
        currentChar++;
    }
    
    fout.close();
    cout << "Done!";
    return EXIT_SUCCESS;
}

