// Chamath Wijesekera - ME 101
// Assignment 4 Question 2
// cmath reference from http://www.cplusplus.com/reference/cmath/ acknowledged for hypot() function

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    // Init file I/O

    ifstream fin("taxi.txt");
    ofstream fout("taxiReport.txt");

    // Vars declaration
    
    const double COST_PER_STOP = 12;
    const double COST_PER_KM = 2.3;

    bool returnTrip = false;
    int tripNum = 0;
    int tripStops = 0;
    double cumulDist = 0;
    double cumulCost = 0;
    double longestTripDist = -1;
    double cheapestTripCost = 1e6;


    // Setting up headings on output file 

    fout << "Trip"
         << setw(9) << "Return"
         << setw(9) << "Stops"
         << setw(7) << "Dist"
         << setw(10) << "Cost"
         << setw(10) << "TotDist"
         << setw(10) << "TotCost"
         << endl;

    // Main loop to scan through file

    while (fin >> returnTrip >> tripStops)
    {
        double tripDist = 0;
        double tripCost = 0;
        double currentX = 0;
        double currentY = 0;
        double prevX = 0;
        double prevY = 0;

        // Adding up trip length from stops

        for (int stops = 0;  stops < tripStops; stops++)
        {
            fin >> currentX >> currentY;
            tripDist += hypot(currentX - prevX, currentY - prevY);
            prevX = currentX;
            prevY = currentY;
        }

        // Using trip length to calculate cost

        tripCost = (tripDist * COST_PER_KM) + (tripStops * COST_PER_STOP);
        
        if (returnTrip)
        {
            double returnTripDist = hypot(currentX, currentY);
            tripCost += returnTripDist * COST_PER_KM;
            tripDist += returnTripDist;
        }

        // Checking for longest and cheapest trip

        if (tripDist > longestTripDist)
        {
            longestTripDist = tripDist;
        }

        if (tripCost < cheapestTripCost)
        {
            cheapestTripCost = tripCost;
        }

        // Adding cost, distance, trips to grand totals

        cumulCost += tripCost;
        cumulDist += tripDist;
        tripNum++;

        // Printing lines on output file - first five then every ten after

        if (tripNum <= 5 || (tripNum - 5)%10 == 0)
        {
            fout << fixed << setprecision(2)
                 << setw(3) << tripNum 
                 << setw(8) << returnTrip 
                 << setw(8) << tripStops 
                 << setw(10) << tripDist 
                 << setw(10) << tripCost 
                 << setw(10) << cumulDist 
                 << setw(10) << cumulCost << endl;
        }
    }

    // Printing final statistics
    
    fout << endl
         << "Cumulative Distance: " << cumulDist << "km\n"
         << "Cumulative Revenue: $" << cumulCost << endl
         << "Length of Longest Trip: " << longestTripDist << "km\n"
         << "Cost of least expensive trip: $" << cheapestTripCost << endl;


    // Shutting down
    
    fin.close();
    fout.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}