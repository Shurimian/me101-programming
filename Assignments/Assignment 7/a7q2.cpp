// Chamath Wijesekera and Bara Husseini - ME 101
// Assignment 7 Question 2

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_FILE_SAMPLES = 12000;


double calcYoungsMod(int measurementCount, double strains[], double stresses[])
{
    int fivePercentOfSamples = measurementCount * 0.05;
    double sumSlope = 0;

    for (int count = 0; count < fivePercentOfSamples; count++)
    {
        sumSlope += (stresses[count + 1] - stresses[count]) / (strains[count + 1] - strains[count]);
    }

    return sumSlope / fivePercentOfSamples;
}

double calcYieldStrength(double youngsMod, double strains[], double stresses[])
{
    const double YIELD_STRENGTH_TOLERANCE = 1;
    
    double interceptDiff = 0;
    double curveStress = 0;
    double modulusStress = 0;
    double yInt = -(youngsMod * 0.002);
    int index = 0;

    do
    {
        curveStress = stresses[index];
        modulusStress = youngsMod * strains[index] + yInt;
        interceptDiff = abs(curveStress - modulusStress);
        index++;
    } while (interceptDiff > YIELD_STRENGTH_TOLERANCE);

    return stresses[index];
}


int main()
{    
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

    string ignore = "";
    fin >> ignore >> ignore;

    int index = 0;
    
    while (index < MAX_FILE_SAMPLES && fin >> strain[index] >> stressMPa[index])
    {   
        if (stressMPa[index] > ultimateTensileStr)
        {
            ultimateTensileStr = stressMPa[index];
        }

        index++;
    }

    double youngsMod = calcYoungsMod(index, strain, stressMPa);
    double yieldStrength = calcYieldStrength(youngsMod, strain, stressMPa);

    cout << fixed << setprecision(3)
         << "The Ultimate Tensile Strength is: " << ultimateTensileStr << " MPa\n"
         << "The Young's Modulus is: " << youngsMod << " MPa\n"
         << "The Yield Strength is: " << yieldStrength << " MPa\n"; 

    fin.close();
    return EXIT_SUCCESS;
}

/* 
Enter name of input file (ex. Sample1.txt): Sample1.txt
The Ultimate Tensile Strength is: 386.832 MPa
The Young's Modulus is: 8813.724 MPa
The Yield Strength is: 324.328 MPa

Enter name of input file (ex. Sample1.txt): Sample2.txt
The Ultimate Tensile Strength is: 309.157 MPa
The Young's Modulus is: 9121.793 MPa
The Yield Strength is: 301.333MPa

Enter name of input file (ex. Sample1.txt): Sample3.txt
The Ultimate Tensile Strength is: 386.832 MPa
The Young's Modulus is: 4901.723 MPa
The Yield Strength is: 357.846MPa
*/
