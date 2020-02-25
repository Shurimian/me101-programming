// Chamath Wijesekera  - ME 101
// Inside Outside Circle

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double radius = 0;
    double x = 0;
    double y = 0;
    cout << "Enter radius of circle, point (x,y)";
    cin >> radius >> x >> y;

    double pointDistance = hypot(x, y);
    string result = "";

    if (pointDistance > radius)
    {
       result = "outside"; 
    }
    else if (pointDistance == radius)
    {
        result = "on";
    }
    else
    {
        result = "within";
    }

    cout << "The point is " << result << " the circle.\n";
}