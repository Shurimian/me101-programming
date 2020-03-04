// Chamath Wijesekera and Bara Husseini - ME 101
// Assignment 7 Question 2

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double calcYoungsMod(int measurementCount, double strains[], double stresses[])
{
    int fivePercentOfSamples = round(measurementCount * 0.05);
    double sumStress = 0;
    double sumStrain = 0;
    
    for (int count = 0; count < fivePercentOfSamples; count++)
    {
        sumStrain += strains[count];
        sumStress += stresses[count];
    }

    return (sumStress / fivePercentOfSamples) / (sumStrain / fivePercentOfSamples);
}

double calcYieldStrength(double youngsMod, double strains[], double stresses[], int pointTwoIndex)
{
    const double YIELD_STRENGTH_TOLERANCE = 1;
    
    double interceptDiff = 0;
    double curveStress = 0;
    double modulusStress = 0;
    int index = pointTwoIndex;
    
    do
    {
        curveStress = stresses[index];
        modulusStress = youngsMod * (strains[index] - 0.002);
        
        interceptDiff = abs(curveStress - modulusStress);
        index++;

    } while (interceptDiff > YIELD_STRENGTH_TOLERANCE);

    return stresses[index];
}


int main()
{
    const int MAX_FILE_SAMPLES = 12000;
    
    string inputFileName = " ";
    cout << "Enter name of input file (ex. Sample1.txt): ";
    cin >> inputFileName;

    ifstream fin(inputFileName);

    if(!fin)
    {
        cout << "Error: File not found.";
        return EXIT_FAILURE;
    }

    double strain[MAX_FILE_SAMPLES] = {0};
    double stressMPa[MAX_FILE_SAMPLES] = {0};
    double ultimateTensileStr = -1;
    double pointTwoStrainIndex = 0;

    string ignore = "";
    fin >> ignore >> ignore;

    int index = 0;
    
    while (fin >> strain[index] >> stressMPa[index])
    {   
        if (stressMPa[index] > ultimateTensileStr)
        {
            ultimateTensileStr = stressMPa[index];
        }

        const double POINT_TWO_TOLERANCE = 0.0001;

        if (abs(strain[index] - 0.002) < POINT_TWO_TOLERANCE)
        {
            pointTwoStrainIndex = index;
        }
        
        index++;
    }

    double youngsMod = calcYoungsMod(index, strain, stressMPa);
    double yieldStrength = calcYieldStrength(youngsMod, strain, stressMPa, pointTwoStrainIndex);

    cout << fixed << setprecision(3)
         << "The Ultimate Tensile Strength is: " << ultimateTensileStr << " MPa\n"
         << "The Young's Modulus is: " << youngsMod << " MPa\n"
         << "The Yield Strength is: " << yieldStrength << "MPa\n"; 

    fin.close();
    return EXIT_SUCCESS;
}

