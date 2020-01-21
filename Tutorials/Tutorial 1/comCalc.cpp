/*
Chamath Wijesekera
Arrays from http://www.cplusplus.com/doc/tutorial/arrays/ used
Alex Rejep Consulted
Loop from Tutorial 1 Slides modified
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "Enter the number of particles in the system: ";
	int n = 0;
	cin >> n;
	
	double mass[n] = {};
	double dist[n] = {};
	
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the mass of particle " << i + 1 << ": ";
		cin >> mass[i];
		cout << "Enter the distance of particle from reference " << i + 1 << ": ";
		cin >> dist[i];		
	}
	
	double massDistMult = 0;
	double totalMass = 0;
	
	for (int j = 0; j < n; j++)
	{
		massDistMult += (mass[j] * dist[j]);
		totalMass += mass[j];
	}
	
	double comRad = massDistMult / totalMass;
	
	cout << "The distance from the reference of the center of mass is: " << comRad << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;	
}
