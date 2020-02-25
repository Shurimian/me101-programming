// Chamath Wijesekera  - ME 101
// One Link Manipulator

#define _USE_MATH_DEFINES

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

bool checkTol (double target, double actual, double tolerance)
{
    if(abs(target - actual) < tolerance)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

double degToRad(double angleDegrees)
{
    return angleDegrees * (M_PI / 180);
}

bool canReachTarget(double radius, double angle, double targetX, double targetY)
{
    const double TOL_X = 0.2;
    const double TOL_Y = 0.5;

    angle = degToRad(angle);

    double armX = radius * cos(angle);
    double armY = radius * sin(angle);

    if(checkTol(targetX, armX, TOL_X) && checkTol(targetY, armY, TOL_Y))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    double radius = 0;
    double angle = 0;
    
    do
    {
        cout << "Enter length of robot arm, angle in degrees: ";
        cin >> radius >> angle;
    } while (angle < 0 || angle > 360 || radius <= 0);

    if(canReachTarget(radius, angle, 25.0, 37.5))
    {
        cout << "Robot can reach target.\n";
    }
    else
    {
        cout << "Robot can't reach target.\n";
    }
    
}