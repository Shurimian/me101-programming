// Chamath Wijesekera - ME 101
// Tutorial 3 - Polar to Cartesian

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    char running = 'N';

    do
    {
        const float DEG_TO_RAD = M_PI / 180;
        float radius = 0;
        float angleDegrees = 0;
        
        cout << "Enter a radius and an angle in degrees: ";
        cin >> radius >> angleDegrees;

        float angleRadians = angleDegrees * DEG_TO_RAD;
        float x = radius * cos(angleRadians);
        float y = radius * sin(angleRadians);
        
        cout << "x: " << x << " y: " << y << endl;
        cout << "Would you like to do another calculation? (y/n): ";
        cin >> running;
    } while (running == 'Y' || running == 'y');
    
     system("PAUSE");
    return EXIT_SUCCESS;
}