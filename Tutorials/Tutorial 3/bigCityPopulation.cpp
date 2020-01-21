// Chamath Wijesekera - ME 101
// Tutorial 3 - Big City Population

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("city.txt");

    if(!fin)
    {
        cout << "File not found.";
        system("PAUSE");
        return EXIT_FAILURE;
    }

    ofstream fout("bigcity.txt");

    int cityCount = 0;
    fin >> cityCount;

    for (int i = 0; i < cityCount; i++ )
    {
        string city = "";
        int cityPop = 0;
        
        fin >> city >> cityPop;

        if (cityPop >= 100000)
        {
            fout << city << " " << cityPop << endl;
        }
        
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}