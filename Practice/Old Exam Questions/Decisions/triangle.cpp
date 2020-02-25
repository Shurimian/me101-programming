// Chamath Wijesekera  - ME 101
// Triangles

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter 3 side lengths in descending order ";
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    cout << "The triangle is ";

    if (a >= b && b >= c && c > 0)
    {
        if (a == b && b == c)
        {
            cout << "equilateral" << endl;
        }
        else if (a == b)
        {
            cout << "isosceles" << endl;
        }
        else 
        {
            cout << "scalene" << endl;
        }
    }
    else
    {
        cout << "invalid" << endl;
    }
    return 0;
}