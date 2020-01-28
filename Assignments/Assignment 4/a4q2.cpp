// Chamath Wijesekera - ME 101
// Assignment 4 Question 2
// cmath reference from http://www.cplusplus.com/reference/cmath/ acknowledged for hypot() function

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("taxi.txt");
    ofstream fout("taxiEarnings.txt");

    const double TRIP_CHARGE = 12;
    const double COST_PER_KM = 2.3;

    bool returnTrip = false;
    int tripNum = 0;
    int stops = 0;
    double currentX = 0;
    double currrentY = 0;
    double prevX = 0;
    double prevY = 0;
    double cumulDist = 0;
    double cumulCost = 0;
    double longestTripDist = 0;
    double cheapestTripCost = 0;
    

    while (fin >> tripNum >> returnTrip >> stops)
    {
        double stopDist = 0;
        double tripDist = 0;
        double tripCost = 0;

        for (trip = 0; trip < stops; trip++)
        {
            
        }
        








        if (trip <= 5 || (trip - 5)%10 == 0)
        {
            fout << fixed << setprecision(2);
            fout << tripNum << " " << returnTrip << " " << stops << " "
                 << tripDist << " " << tripCost << " "  << cumulDist << " "
                 << cumulCost << endl;
        }
    }

    fout <<




    fin.close()
    fout.close()

    system("PAUSE")
    return EXIT_SUCCESS 
}