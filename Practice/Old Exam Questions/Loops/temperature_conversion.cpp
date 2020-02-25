// Chamath Wijesekera  - ME 101
// Temperature Conversion

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double fahrToCels(double tempFahrenheit)
{
    return (tempFahrenheit - 32) * (5.0 / 9.0);
}


int main()
{
    ifstream fin("dec.txt");
    ofstream fout("Hawaii.txt");

    int warmestDay = 0;
    double warmestDayTemp = -1000;

    
    for (int day = 1; day <= 31; day++)
    {
        double dayTemp = 0;
        fin >> dayTemp;

        if (dayTemp > warmestDayTemp)
        {
            warmestDayTemp = dayTemp;
            warmestDay = day;
        }
        fout << fixed << setprecision(2) << fahrToCels(dayTemp) << endl;
    }
    fout << "The warmest day was Dec " << warmestDay << " at " << fahrToCels(warmestDayTemp) << " degrees Celsius." << endl;

    fin.close();
    fout.close();

}