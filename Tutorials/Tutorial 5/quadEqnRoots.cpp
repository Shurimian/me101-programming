// Chamath Wijeskera - ME 101
// Quadratic Equation Roots

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

double findDiscriminant (double a, double b, double c)
{
    return pow(b, 2) - 4 * a * c;
}

string roots (double a, double b, double c)
{
    double discriminant = findDiscriminant(a, b, c);

    if (a != 0 && discriminant > 0)
    {
        return "Two unique real\n";
    }
    else if (a != 0 && discriminant == 0)
    {
        return "Two identical real\n";
    }
    else if (a == 0 && b != 0)
    {
        return "One real\n";
    }
    else if (a != 0 && discriminant < 0)
    {
        return "Two imaginary\n";
    }
    
    return "Invalid\n";
}

int main ()
{
    cout << "Enter the a b c coefficients: ";
    double a = 0;
    double b = 0;
    double c = 0;
    cin >> a >> b >> c;
    cout << roots(a, b, c);
}