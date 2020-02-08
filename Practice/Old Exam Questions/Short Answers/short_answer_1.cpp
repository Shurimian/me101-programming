#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    cout << pow(3.375, 1/3) << endl;
    // Guess - 1
    cout << atan2(1, 1) * 180 / M_PI << endl;
    // Guess - 45
    cout << 4 % 6 * 5 / 2 << endl;
    // Guess - 10

    int a = 3, b = -4;
    int c = ++b * a--;
    b *= a + 2;
    cout << a << " " << b << " " << c << endl;
    // Guess - a = 2, b = -12, c = -9

    cout << "Enter a number ";
    int number = 0;
    cin >> number;

    for (int row = 1; row <= number; row++)
    {
        cout << setw(row);
        for (int col = 0; col < 3; col++)
        {
            cout << '*';
        }
        cout << endl;
    }

}


/* ROBOTC Code

task main()
{
    while (!getButtonPress(buttonLeft))
    {}

    while (getButtonPress(buttonLeft))
    {}
}

*/