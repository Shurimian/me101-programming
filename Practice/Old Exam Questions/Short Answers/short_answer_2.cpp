#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    cout << 14 / 3 * sqrt(100) + 5 % 3 << endl;
    // Guess - 42
    
    cout << fixed << setprecision(3);
    // 3 Decimal Places
    
    int up = 5;
    int down = up++;
    down *= -1;
    cout << --down << " " << up << endl;
    // Guess - down = -6, up = 6 
}