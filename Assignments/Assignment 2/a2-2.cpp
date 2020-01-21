// Chamath Wijesekera and Tarj Tandel
// Assignment 2 Question 2

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter an integer: ";
    int number = 0;
    cin >> number;
	
	int hundreds = abs(number) % 1000;
	int thousands = abs(number) / 1000;
	
	if (number < 0)
	{
		cout << '-';
	}
	
	if (thousands > 0) 
	{
		cout << thousands << ',';
		
		if (hundreds < 10)
		{
			cout << "00";
		}
		else if (hundreds < 100)
		{
			cout << "0";
		}
	}

	cout << hundreds << endl;
	
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
Enter an integer: 1
1
Press any key to continue . . .
*/

/*
Enter an integer: 1001
1,001
Press any key to continue . . .
*/

/*
Enter an integer: 100001
100,001
Press any key to continue . . .
*/

/*
Enter an integer: 123456
123,456
Press any key to continue . . .
*/

/*
Enter an integer: -123456
-123,456
Press any key to continue . . .
*/



