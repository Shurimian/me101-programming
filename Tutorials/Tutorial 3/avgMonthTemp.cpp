// Chamath Wijesekera - ME 101
// Tutorial 3 - Average Monthly Temperature

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("February.txt");

    if (!fin)
    {
        cout << "File not found.";
        system("PAUSE");
        return 1;
    }

    float dayTemp = 0;
    float tempSum = 0;
    int dayCount = 0;
    
    
    while (fin >> dayTemp)
    {
        tempSum += dayTemp;
        dayCount++;
    }

    cout << fixed << setprecision(2) 
         << "The average temperature for the month was " << tempSum / dayCount << " Celsius.\n";

    system("PAUSE");
    return 0;
}