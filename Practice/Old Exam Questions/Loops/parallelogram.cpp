// Chamath Wijesekera  - ME 101
// Parallelogram

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number ";
    int number = 0;
    cin >> number;

    for (int row = 1; row <= number; row++)
    {
        for (int spaces = number; spaces > row; spaces--)
        {
            cout << ' ';
        }

        for (int hashes = 0; hashes < 3; hashes++)
        {
            cout << '#';
        }
        cout << endl;
    }
}