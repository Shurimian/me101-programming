#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    cout << 80 / 10 % 10 / 3 + 1.5 * 4 / 8 << endl;
    // 2.75

    cout << int(14 > 8 > -1) << endl;
    // Guess - 1

    cout << cos(1 / 4 * M_PI) << endl;
    // Guess - 0

    int a = 5, b = -2;
    b *= --a;
    int c = a + b++;
    cout << a << " " << b << " " << c << endl;
    // Guess - 4 -7 -4
}