// Chamath Wijesekera - ME 101
// Tutorial 5 - Radians to Degrees

#define _USE_MATH_DEFINES

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

double radiansToDegrees (double radians)
{
    const double RADIANS_TO_DEGREES = 180 / M_PI;
    return radians * RADIANS_TO_DEGREES;
}



int main()
{
    double radianInput = 0;
    cout << "Enter an angle in radians: ";
    cin >> radianInput;
    cout << radiansToDegrees(radianInput);
}
