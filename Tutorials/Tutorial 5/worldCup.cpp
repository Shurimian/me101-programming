// Chamath Wijesekera - ME 101
// Tutorial 5 - World Cup

#include <cstdlib>
#include <iostream>

using namespace std;

bool isWorldCup (int year)
{
    return (year == 1930 || year == 1934 || year == 1938 || (year - 1950) % 4 == 0);
}

int main ()
{
    cout << "Enter a year: ";
    int inputYear = 0;
    cin >> inputYear;

    if (isWorldCup(inputYear))
    {
        cout << "There will/was/will be a world cup\n";
    }
    else
    {
        cout << "No world cup this year\n";
    }
}