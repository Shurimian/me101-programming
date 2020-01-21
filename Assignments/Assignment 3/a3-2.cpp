// Chamath Wijesekera - ME 101
// Assignment 3 Question 2

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileIn("December_2019.txt");

    if (!fileIn)
    {
        cout << "File not Found" << endl;
        system("PAUSE");
        return EXIT_FAILURE;
    }

    double monthHigh = -100;
    double monthLow = 100;

    for (int day = 1; day <= 31; day++)
    {
        double dayHigh = 0;
        double dayLow = 0;

        fileIn >> dayHigh;
        fileIn >> dayLow;

        if (dayHigh > monthHigh)
        {
            monthHigh = dayHigh;
        }

        if (dayLow < monthLow)
        {
            monthLow = dayLow;
        }
    }
    cout << "The highest daily temperature in December was " << monthHigh << " degrees Celsius." << endl;
    cout << "The lowest daily temperature in December was " << monthLow << " degrees Celsius." << endl;

    fin.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
