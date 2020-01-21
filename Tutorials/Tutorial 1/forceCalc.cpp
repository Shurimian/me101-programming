#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	const float GRAVITY = 9.81;
	cout << "Input mass of object in kg: ";
	double mass = 0;
	cin >> mass;
	cout << "The gravitational force exerted is " << mass * GRAVITY << " Newtons." << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
