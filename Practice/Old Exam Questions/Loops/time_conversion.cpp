// Chamath Wijesekera  - ME 101
// Time Conversion

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int minutes = 0;
    int seconds = 0;
    int input = 0;

    do
    {
        cout << "Enter a time in seconds: ";
        cin >> input;
    } while (input < 0 || input > 3600);
    
    
    

    minutes = input / 60;
    seconds = input % (minutes * 60);

    cout << "Conversion Result: " << minutes << " minutes and " << seconds << " seconds.\n";
}