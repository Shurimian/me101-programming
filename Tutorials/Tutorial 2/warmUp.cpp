//Chamath Wijesekera - ME101
// Warm Up

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number";
    int number = 0;
    cin >> number;
    if (number % 2 == 0)
    {
        cout << "This number is even." << endl;
    }
    else
    {
        cout << "This number is odd." << endl;
    };
    
	system("PAUSE");
	return EXIT_SUCCESS;	

}