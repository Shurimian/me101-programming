#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    const float GRAVITY = 9.81;
    const float DAUGHTER_DIST = 1.6;
    float daughterMass = 0;
    float davidMass = 0;

    cout << "Enter the Daughter's weight (kg): ";
    cin >> daughterMass;
    
    cout << "Enter David's weight (kg): ";
    cin >> davidMass;

    float daughterTorque = daughterMass * GRAVITY * DAUGHTER_DIST;
    
    cout << "David would need to sit " << daughterTorque / (GRAVITY * davidMass) << " m from the fulcrum\n";

    return 0;
}