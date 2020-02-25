// Chamath Wijesekera  - ME 101
// Speed Conversion

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("results.txt");
    
    const double FURLONGS_PER_FORTNIGHT_CONV = 1.663e-4;
    char repeat = 'n'; 
    
     do
     {
        double speedMPerS = 0;
        
        do
        {
            cout << "Enter a speed in meters/second: ";
            cin >> speedMPerS;
        } while (speedMPerS <= 0);
        
        fout << "The value is " << speedMPerS / FURLONGS_PER_FORTNIGHT_CONV 
             << " furlongs per fortnight\n";
     
        do
        {
            cout << "Repeat?: ";
            cin >> repeat; 
            repeat = tolower(repeat);
        } while (repeat != 'y' && repeat != 'n');     

     } while (repeat == 'y');
    fout.close();
}