// Chamath Wijesekera - ME 101
// Tutorial 5 - Polygons

#define _USE_MATH_DEFINES

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;


double angleOfSep(int sides, int vertexNumber)
{
    double anglePerSide = 2 * M_PI / sides;
    return anglePerSide * vertexNumber;
}

void verticesLocation (double radius, int sides, double x, double y)
{
    for (int vertex = 0; vertex < sides; vertex++)
    {
        cout << x + (radius * cos(angleOfSep(sides, vertex)))  << ", " << y + (radius * sin(angleOfSep(sides, vertex))) << endl; 
    }   
}


int main()
{
    double inputX = 0;
    double inputY = 0;
    double inputRad = 0;
    int inputSides = 0;

    do
    {
        cout << "Enter center (x y), radius, and number of sides: ";
        cin >> inputX >> inputY >> inputRad >> inputSides;
    } while (inputRad < 0 || inputSides < 3);

    verticesLocation(inputRad, inputSides, inputX, inputY);

}