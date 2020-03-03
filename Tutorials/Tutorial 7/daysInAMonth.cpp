// Chamath Wijesekera - ME 101
// How Many Days in a Month

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int month = 0;
    int year = 0;
    cout << "Enter a month (1-12) and year (1901-1920): ";
    cin >> month >> year;

    if (month == 1 && year % 4 == 0)
    {
        cout << "29\n";
    }
    else
    {
        cout << days[month-1];
    }
    


}