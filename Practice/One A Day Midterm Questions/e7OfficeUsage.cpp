#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("office.txt");

    int officeHoursTotal = 0;
    int officeCount = 0;
    int officeNumber = 0;
    char occupantType = ' ';

    while(fin >> officeNumber >> occupantType)
    {
        int officeOccupiedCount = 0;
        int occupants = 0;
        if(occupantType = 'F')
        {
            for (int count = 0; count < 11; count++)
            {
                fin >> occupants;
                if(occupants > 0)
                {
                    officeOccupiedCount++;
                }
            }
            cout << officeNumber << " Was occupied " << officeOccupiedCount / 11.0 * 100.0 << "% of the time.\n";
            officeHoursTotal += officeOccupiedCount;
        }
        else if(occupantType = 'G')
        {
            for (int count = 0; count < 15; count++)
            {
                fin >> occupants;
                if(occupants > 0)
                {
                    officeOccupiedCount++;
                }
            } 
            cout << officeNumber << " Was occupied " << officeOccupiedCount / 15.0 * 100.0 << "% of the time.\n";
            officeHoursTotal += officeOccupiedCount;
        }  
        else
        {
            cout << "Invalid file structure\n";
            return EXIT_FAILURE;
        }
        
        officeCount++;
    }   
    cout << "Average hours occupied: " << float(officeHoursTotal) / officeCount << endl; 
    fin.close();
    return EXIT_SUCCESS;
}