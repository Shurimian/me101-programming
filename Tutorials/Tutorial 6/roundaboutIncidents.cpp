// Chamath Wijesekera - ME 101
// Tutorial 6 - Roundabout Incidents
// Rounding to nearest 10 adapted from: 
// https://stackoverflow.com/questions/44110606/rounding-off-a-number-to-the-next-nearest-multiple-of-5/44110700

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int numberOfStars(int value)
{
    return ((value + 9) / 10);
}

int main()
{
    ifstream fin("round.txt");
    ofstream fout("graph.txt");

    if (!fin)
    {
        cout << "File not found" << endl;
        return EXIT_FAILURE;
    }

    string roundName = " ";
    int incidents = 0;
    int totalIncidents = 0;
    string worstRoundaboutName = " ";
    int worstRoundaboutIncidents = -1;
    
    while (fin >> roundName >> incidents)
    {
        fout << setw(20) << left << roundName << " ";
        
        for (int count = 0; count < numberOfStars(incidents); count++)
        {
            fout << '*';
        }
        
        fout << endl;

        if (incidents > worstRoundaboutIncidents)
        {
            worstRoundaboutIncidents= incidents;
            worstRoundaboutName = roundName;
        }
        
        totalIncidents += incidents;
    }
    fout << endl << "Total incidents: " << totalIncidents << endl
         << "Worst roundabout was " << worstRoundaboutName << " with " << worstRoundaboutIncidents << " incidents.";
    
    fin.close();
    fout.close();
    return EXIT_SUCCESS;
}