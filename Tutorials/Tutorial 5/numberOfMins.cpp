// Chamath Wijesekera - ME 101
// Number of Minutes

#include <cstdlib>
#include <iostream>

using namespace std;

double numberOfMinutes (double minutes, double seconds)
{
    const double SECONDS_IN_MINUTES = 60;
    
    return minutes + (seconds / SECONDS_IN_MINUTES);
}

int main ()
{
    char redo = ' ';
    do 
    {
        double minutesInput = 0;
        double secondsInput = 0;
        
        do
        {
            cout << "Enter a time in minutes and seconds:";
            cin >> minutesInput >> secondsInput;
        } while (minutesInput <= 0 && secondsInput <= 0);

        cout << numberOfMinutes (minutesInput, secondsInput) << endl;
        cout << "Redo?: ";
        cin >> redo;    
        
    } while (redo == 'y');
}