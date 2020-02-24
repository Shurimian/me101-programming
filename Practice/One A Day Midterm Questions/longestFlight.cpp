#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double timeToHours(int time)
{
    return time / 100 + (time % 100 / 60.0);
}


int main()
{
    ifstream fin("flight.dat");
    ofstream fout("longFlight.txt");

    string flightCode = " ";
    string cityName = " ";
    int intermediateStops = 0;
    int departTime = 0;
    int arriveTime = 0;
    string longestFlight = "";
    double longestFlightTime = 0;

    while (fin >> flightCode >> cityName >> intermediateStops)
    {
        double flightDuration = 0;
        if (intermediateStops == 0)
        {
            fin >> departTime >> arriveTime;
            if (departTime > arriveTime)
            {
                flightDuration = 24 - timeToHours(departTime) + timeToHours(arriveTime);
            }
            else
            {
                flightDuration = timeToHours(arriveTime) - timeToHours(departTime);
            }

            fout << fixed << setprecision(2)
                 << left << setw(8)  << flightCode 
                 << setw(20) << cityName 
                 << setw(6)  << flightDuration << endl;
            if (flightDuration > longestFlightTime)
            {
                longestFlightTime = flightDuration;
                longestFlight = flightCode;
            }
        }
        else
        {
            int otherArrivals = 0;
            fin >> departTime >> arriveTime;
            for (int arrivals = 0; arrivals < intermediateStops; arrivals++)
            {
                fin >> otherArrivals;
            }
        }
        
    }
    fout << "The longest flight was " << longestFlight << " at " << longestFlightTime << " hours\n";
}