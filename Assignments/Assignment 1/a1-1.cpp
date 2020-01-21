/*
 Chamath Wijesekera
 ME101 - Assignment 1-1
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "Provide a Side Length : ";
	int side_length = 0;
	cin >> side_length;
	
    cout << "The square of " << side_length << " is " << side_length * side_length << endl;
    cout << "& the cube of " << side_length << " is " << side_length * side_length * side_length << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
Provide a Side Length : 2
The square of 2 is 4
& the cube of 2 is 8
Press any key to continue . . .
*/
