// Chamath Wijesekera  - ME 101
// E7 Humidity

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("humidity.txt");

    double lowestReading = 1000;
    double reading = 0;
    while (fin >> reading)
    {
        if (reading != -1)
        {
            if (reading < lowestReading)
            {
                lowestReading = reading;
            }
        }
    }
    cout << "The lowest reading was " << lowestReading << endl;
    fin.close();
    return EXIT_SUCCESS;
}