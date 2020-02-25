// Chamath Wijesekera  - ME 101
// Bicycle Cops in Park

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

double distanceBetween (double x1, double x2, double y1, double y2)
{
    double xDiff = abs(x2 - x1);
    double yDiff = abs(y2 - y1);
    return hypot(xDiff, yDiff);
}

double rescueTime (double x, double y, double xpol, double ypol, double speed)
{
    double distance = distanceBetween(x, y, xpol, ypol);
    return distance / speed;
}

int main()
{
    ifstream fin("police.txt");

    double helpX = 0;
    double helpY = 0;

    fin >> helpX >> helpY;

    double polX = 0;
    double polY = 0;
    double polSpeed = 0;

    while(fin >> polX >> polY >> polSpeed)
    {
        
        cout << fixed << setprecision(2)
             << "Police Officer @ " << polX << ", " << polY 
             << ". Time to respond: " 
             << rescueTime(helpX, helpY, polX, polY, polSpeed) * 60 
             << " minutes.\n";
    }
}