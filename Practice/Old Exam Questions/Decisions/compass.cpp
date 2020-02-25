// Chamath Wijesekera  - ME 101
// Compass

#define _USE_MATH_DEFINES

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x = 0, y = 0;
    string direction = "";
    cout << "Enter a location (x,y)";
    cin >> x >> y;

    double angle = atan2(y, x) * (180 / M_PI);

    if (angle >= 45 && angle <= 135)
    {
        // North
        direction = "North";
    }
    else if (angle > -45 && angle < 45)
    {
        
        // East
        direction = "East";
    }
    else if (angle >= -135 && angle <= -45)
    {
        // South
        direction = "South";
    }
    else
    {
        // West
        direction = "West";
    }

    cout << "This location is " << direction << " of the origin.\n";
}