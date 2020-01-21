/*
 Chamath Wijesekera
 ME101 - Assignment 1-2
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    const float KM_CONV = 1.852;
    const float CABLE_CONV = 10;
    
	cout << "Provide a Value in Nautical Miles: ";
	double nautMiles = 0;
	cin >> nautMiles;
	
    cout << nautMiles << " Nautical Miles is..." << endl;
    cout << nautMiles * KM_CONV << " Kilometers" << endl;
    cout << nautMiles * CABLE_CONV  << " Cable Lengths" << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
Provide a Value in Nautical Miles: 5
5 Nautical Miles is...
9.26 Kilometers
50 Cable Lengths
Press any key to continue . . .
*/
