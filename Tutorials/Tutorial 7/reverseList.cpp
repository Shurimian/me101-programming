// Chamath Wijesekera - ME 101
// Reverse a List of Names

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    const int NAMES_COUNT = 67;
    
    ifstream fin("MMEList.txt");
    string names[NAMES_COUNT];
    int nameCount = NAMES_COUNT - 1;
    while (fin >> names[nameCount])
    {
        nameCount--;
    }

    for (int index = 0; index < NAMES_COUNT; index++)
    {
        cout << names[index] << endl;
    }

    fin.close();
    return EXIT_SUCCESS;
}