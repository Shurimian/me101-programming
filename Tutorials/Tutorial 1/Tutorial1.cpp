#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "Enter a year ";
	
	int year = 0;
	cin >> year;
	
	cout << "Happy " << year << endl
		 << "Goodbye " << year - 1 << endl;
		 
	system("PAUSE");
	return EXIT_SUCCESS;	
}
