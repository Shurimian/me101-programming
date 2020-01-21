// Chamath Wijesekera - ME 101;
// Tutorial 3 - Many Times Tables

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int inputNumber = 0;
    cout << "Enter a number between 1 and 15: ";
    cin >> inputNumber;

    for (int row = 1; row <= inputNumber; row++)
    {
        for (int col = 1; col <= inputNumber; col++)
        {
            cout << setw(3) << row * col << " ";
        }
        cout << endl;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}