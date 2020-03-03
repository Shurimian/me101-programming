// Chamath Wijesekera - ME 101
// The Highest Mountain

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("mountain.txt");
    string mountainNames[10];
    double mountainHeight[10] = {0};
    int mountainCount = 0;
    double maxHeight = -1;
    fin >> mountainCount;
    cout << "Mountain                      % Max Height\n";

    for (int count = 0; count < mountainCount; count++)
    {
        fin >> mountainNames[count] >> mountainHeight[count];
        if (mountainHeight[count] > maxHeight)
        {
            maxHeight = mountainHeight[count];
        }
    }

    for (int index = 0; index < mountainCount; index++)
    {
        cout << left << setw(30) << mountainNames[index] << setw(5) 
             << mountainHeight[index] / maxHeight * 100 << endl;
    }

    fin.close();

}