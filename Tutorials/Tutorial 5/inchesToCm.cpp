// Chamath Wijesekera - ME 101
// Tutorial 5 - Inches to Centimeters


#include <cstdlib>
#include <iostream>

using namespace std;

double inchToCm (double inches)
{
    const double INCH_TO_CM = 2.54;
    return inches * INCH_TO_CM;
}

int main()
{
    double inchInput = 0;
    do 
    {
        cout << "Enter length in Inches:";
        cin >> inchInput;
    } while (inchInput <= 0);
    cout << inchToCm(inchInput);
}