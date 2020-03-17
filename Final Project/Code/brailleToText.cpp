#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, char> braille;
    
    braille["a 1 0 0 0 0 0 "] = 'a';
    braille["b 1 1 0 0 0 0 "] = 'b';
    braille["c 1 0 0 1 0 0 "] = 'c';
    braille["d 1 0 0 1 1 0 "] = 'd';
    braille["e 1 0 0 0 1 0 "] = 'e';
    braille["f 1 1 0 1 0 0 "] = 'f';
    braille["g 1 1 0 1 1 0 "] = 'g';
    braille["h 1 1 0 0 1 0 "] = 'h';
    braille["i 0 1 0 1 0 0 "] = 'i';
    braille["j 0 1 0 1 1 0 "] = 'j';
    braille["k 1 0 1 0 0 0 "] = 'k';
    braille["l 1 1 1 0 0 0 "] = 'l';
    braille["m 1 0 1 1 0 0 "] = 'm';
    braille["n 1 0 1 1 1 0 "] = 'n';
    braille["o 1 0 1 0 1 0 "] = 'o';
    braille["p 1 1 1 1 0 0 "] = 'p';
    braille["q 1 1 1 1 1 0 "] = 'q';
    braille["r 1 1 1 0 1 0 "] = 'r';
    braille["s 0 1 1 1 0 0 "] = 's';
    braille["t 0 1 1 1 1 0 "] = 't';
    braille["u 1 0 1 0 0 1 "] = 'u';
    braille["v 1 1 1 0 0 1 "] = 'v';
    braille["w 0 1 0 1 1 1 "] = 'w';
    braille["x 1 0 1 1 0 1 "] = 'x';
    braille["y 1 0 1 1 1 1 "] = 'y';
    braille["z 1 0 1 0 1 1 "] = 'z';
    braille[", 0 1 0 0 0 0 "] = ',';
    braille[". 0 1 0 0 1 1 "] = '.';

    int pageNumber = 1;
    string inputLine = " ";
    
    ifstream fin("output.txt");
    ofstream fout("translation.txt");

    while (fin >> inputLine)
    {   
        if (inputLine == "!")
        {
            fout << ' ';
        }
        else if (inputLine == "@")
        {
            fout << '\n';
        }
        else if (inputLine == "#")
        {
            fout << "\n\nNEWPAGE\n\n";
        }
        else
        {
            fout << braille[inputLine];
        }
    }

    fout.close();
    cout << "Done!";
    return EXIT_SUCCESS;
}