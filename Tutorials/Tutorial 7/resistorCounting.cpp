// Chamath Wijesekera - ME 101
// Resistor Counting

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    ifstream fin("resist.txt");

    map<string, int> colors;
    
    colors["black"]  = 0;
    colors["brown"]  = 1;
    colors["red"]    = 2;
    colors["orange"] = 3;
    colors["yellow"] = 4;
    colors["green"]  = 5;
    colors["blue"]   = 6;
    colors["violet"] = 7;
    colors["gray"]   = 8;
    colors["white"]  = 9;

    

}