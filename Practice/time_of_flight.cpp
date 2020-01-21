#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float initVelocity = 0;
    float launchAngle = 0;
    float elevChange = 0;
    
    cout << "Enter initial velocity: ";
    cin >> initVelocity;
    cout << "Enter launch angle: ";
    cin >> launchAngle;
    cout << "Enter the change in elevation from launch to landing: ";
    cin >> elevChange;
    
    // TODO ToF Calculations
    
    cout << "Time of flight 1: "
         //<<  ToF 1
         << "\nTime of flight 2: "
         //<<  ToF 2
         << endl;

    return 0;
}