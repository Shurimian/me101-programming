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