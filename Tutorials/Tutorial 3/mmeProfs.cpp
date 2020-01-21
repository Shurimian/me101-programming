// Chamath Wijesekera - ME 101
// Tutorial 3 - MME Profs

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("MMENames.txt");

    if (!fin)
    {
        cout << "File not found.\n";
        system("PAUSE");
        return EXIT_FAILURE;
    }

    int nameCount = 0;
    string nameMatch = " ";
    bool nameExists = false;
    fin >> nameCount;

    cout << "Enter a last name: ";
    cin >> nameMatch;

    for (int i = 0; i < nameCount; i++)
    {
        string name = " ";
        fin >> name;

        if (name == nameMatch)
        {
            nameExists = true;
            break;
        }
    }

    if (nameExists)
    {
        cout << nameMatch << " exists in the database.\n";
    }
    else
    {
        cout << nameMatch << " does not exist in the database.\n";
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
