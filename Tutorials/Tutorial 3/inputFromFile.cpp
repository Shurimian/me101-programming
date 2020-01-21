// Chamath Wijesekera - ME 101
// Tutorial 3 - Input from File


#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("info.txt");

    if (!fin)
    {
        cout << "File not found.";
        system("PAUSE");
        return EXIT_FAILURE;
    }

    string print = "";
    while (fin >> print)
    {
        cout << print << endl;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}