#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    cout << (1.0 + 6) + 8 / 3 + 2 % 3 << endl;
    // Guess - 11

    // To test the code before the function is fully coded

    double x = 19.8765, y = -3.2;
    int z = 5;
    cout << fixed << setprecision(3);
    cout << setw(8) << x << endl << y << endl << z << endl;
    /* Guess:
          19.877
        -3.200
        5
    */

   int a = 4, b = -5;
   int c = a-- * 2;
   b *= ++a;
   cout << a << " " << b << " " << c << endl;
   // Guess - 4 -20 8

}

/*
ROBOTC Code

task main()
{
    while (sensorValue[S1] > -360)
    {}
}
*/