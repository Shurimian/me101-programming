#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, char> braille;
    
    braille["a100000"] = 'a';
    braille["b110000"] = 'b';
    braille["c100100"] = 'c';
    braille["d100110"] = 'd';
    braille["e100010"] = 'e';
    braille["f110100"] = 'f';
    braille["g110110"] = 'g';
    braille["h110010"] = 'h';
    braille["i010100"] = 'i';
    braille["j010110"] = 'j';
    braille["k101000"] = 'k';
    braille["l111000"] = 'l';
    braille["m101100"] = 'm';
    braille["n101110"] = 'n';
    braille["o101010"] = 'o';
    braille["p111100"] = 'p';
    braille["q111110"] = 'q';
    braille["r111010"] = 'r';
    braille["s011100"] = 's';
    braille["t011110"] = 't';
    braille["u101001"] = 'u';
    braille["v111001"] = 'v';
    braille["w010111"] = 'w';
    braille["x101101"] = 'x';
    braille["y101111"] = 'y';
    braille["z101011"] = 'z';
    braille[",010000"] = ',';
    braille[".010011"] = '.';

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