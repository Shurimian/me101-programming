// Chamath Wijesekera - ME 101
// Assignment 5 Question 3
// Original Cell Stucture Program Code by Chamath Wijesekera and Tarj Tandel

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

double volSC(double radius)
{
    return pow(2.0 * radius, 3.0);
}

double volBCC(double radius)
{
    return pow(((4.0 * radius) / sqrt(3.0)), 3.0);
}

double volFCC(double radius)
{
    return pow(((4.0 * radius) / sqrt(2.0)), 3.0);
}

int main()
{
    string cellStructure = " ";
    double atomicRad = 0;

    do
    {
        cout << "Enter the type of cell structure (SC, BCC, or FCC): ";
        cin >> cellStructure;

    } while (cellStructure != "SC" && cellStructure != "sc" && 
             cellStructure != "BCC" && cellStructure != "bcc" && 
             cellStructure != "FCC" && cellStructure != "fcc");
    
    do
    {
        cout << "Enter radius in Angstroms: ";
        cin >> atomicRad;
    } while (atomicRad <= 0);

    if (cellStructure == "SC" || cellStructure == "sc")
    {
        cout << "The volume of this SC cell is " << volSC(atomicRad) << endl;
    }
    else if (cellStructure == "BCC" || cellStructure == "bcc")
    {
        cout << "The volume of this BCC cell is " << volBCC(atomicRad) << endl;
    }
    else
    {
        cout << "The volume of this FCC cell is " << volFCC(atomicRad) << endl;
    }

    return EXIT_SUCCESS;   
}




