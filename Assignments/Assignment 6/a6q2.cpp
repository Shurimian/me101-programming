// Chamath Wijesekera and Nathan Shen - ME 101
// Assignment 6 Question 2

#define _USE_MATH_DEFINES

#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int timeInMinutes (int timeIn24h)
{
    int minutes = timeIn24h % 100;
    int hours = timeIn24h / 100;
    return hours * 60 + minutes;
}

double coordsToDist (double coordX, double coordY)
{
    return hypot(coordX, coordY);
}

double coordsToAngle (double coordX, double coordY)
{
    return atan2(coordY, coordX) * (180 / M_PI);
}

int main()
{
    ifstream fin("wascally_wabbits.txt");
    ofstream fout("output.txt");

    if (!fin)
    {
        cout << "File not found." << endl;
        return EXIT_FAILURE;
    }

    fout << "   time    dist   angle\n";

    int time24 = 0;
    double coordX = 0;
    double coordY = 0;
    int shortestSightingInterval = 1000;
    int prevSighting = -1000;

    while (fin >> time24 >> coordX >> coordY)
    {        
        int sightingInterval = 0;
        int currentSighting = timeInMinutes(time24);

        fout << fixed << setprecision(2) 
             << setw(7) << currentSighting << " "
             << setw(7) << coordsToDist(coordX, coordY) << " " 
             << setw(7) << coordsToAngle(coordX, coordY) << endl;

        sightingInterval = currentSighting - prevSighting;
        
        if (sightingInterval < shortestSightingInterval)
        {
            shortestSightingInterval = sightingInterval;
        }

        prevSighting = currentSighting;
    }

    fout << "\nThe shortest interval between sightings was " << shortestSightingInterval << " minutes.\n";
    
    fin.close();
    fout.close();
    return EXIT_SUCCESS;
}

/*
   time    dist   angle
     12   82.75  174.73
     32   76.84   -7.40
     48  121.01  174.26
     55  121.06   -5.97
     96  217.00 -179.68
    108   64.01  179.02
    115   36.36  -21.63
    266  306.02 -179.27
    322   10.52  122.18
    327  272.47 -177.45
    415   42.68   10.26
    479   19.72  157.34
    541   37.18  -11.79
    602  291.40    1.49
    742   64.01   -0.98
    890   10.52   57.82
   1004   19.72 -157.34
   1132   42.68 -169.74
   1222    2.20   90.00
   1271   13.00  180.00
   1424    2.20    0.00
   1439    2.20  -90.00

The shortest interval between sightings was 5 minutes.
*/