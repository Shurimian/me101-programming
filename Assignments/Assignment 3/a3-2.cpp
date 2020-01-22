// Chamath Wijesekera and Nathan Shen - ME 101
// Assignment 3 Question 2

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("December_2019.txt");

    if (!fin)
    {
        cout << "File not Found" << endl;
        system("PAUSE");
        return EXIT_FAILURE;
    }

    double monthHigh = -100;
    double monthLow = 100;

    for (int day = 1; day <= 62; day++)
    {
        double temp = 0;

        fin >> temp;

        if (temp > monthHigh)
        {
            monthHigh = temp;
        }

        if (temp < monthLow)
        {
            monthLow = temp;
        }
    }
    cout << "The highest daily temperature in December was " << monthHigh << " degrees Celsius." << endl;
    cout << "The lowest daily temperature in December was " << monthLow << " degrees Celsius." << endl;

    fin.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
The highest daily temperature in December was 10.2 degrees Celsius.
The lowest daily temperature in December was -17.9 degrees Celsius.
Press any key to continue . . . 
*/