#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float initVelocity = 0;
    float launchAngle = 0;
    float elevChange = 0;
    
    cout << "Enter initial velocity (m/s): ";
    cin >> initVelocity;
    cout << "Enter launch angle (degrees): ";
    cin >> launchAngle;
    cout << "Enter the change in elevation from launch to landing (m): ";
    cin >> elevChange;
    
    // TODO ToF Calculations
    
    cout << "Possible times of flight (s):\n "
         //<<  ToF 1
         << endl
         //<<  ToF 2
         << endl;

    return 0;
}