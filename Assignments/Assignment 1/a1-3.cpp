/*
 Chamath Wijesekera
 ME101 - Assignment 1-3
 Mini-Lecture "Input Multiple Values with cin" used as reference for numbers input.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "Please enter four integers separated by spaces: ";
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	cin >> num1 >> num2 >> num3 >> num4;
    cout << "The sum of these numbers is: " << num1 + num2 + num3 + num4 << endl;
    cout << "The mean of these numbers is: " << (num1 + num2 + num3 + num4) / 4.0 << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
Please enter four integers separated by spaces: 1 2 3 4
The sum of these numbers is: 10
The mean of these numbers is: 2.5
Press any key to continue . . .
*/

/*
Please enter four integers separated by spaces: 99 2 589 3
The sum of these numbers is: 693
The mean of these numbers is: 173.25
Press any key to continue . . .
*/

/*
Please enter four integers separated by spaces: 0 0 0 0
The sum of these numbers is: 0
The mean of these numbers is: 0
Press any key to continue . . .
*/

/*
Please enter four integers separated by spaces: -4 -892 -6 -2
The sum of these numbers is: -904
The mean of these numbers is: -226
Press any key to continue . . .
*/
