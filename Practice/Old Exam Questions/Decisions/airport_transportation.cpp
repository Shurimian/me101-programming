// Chamath Wijesekera  - ME 101
// Airport Transportation

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    char workPaying = ' ';
    int daysTravelling = 0;
    const int TAXI_COST = 100;
    
    cout << "Is work paying for travel? (y/n): ";
    cin >> workPaying;
    workPaying = tolower(workPaying);
    cout << "Enter days Chris is travelling: ";
    cin >> daysTravelling;


    if (workPaying == 'y')
    {
        int selfDriveCost = 25 * daysTravelling;
        if(selfDriveCost > TAXI_COST)
        {
            cout << "Chris will take the taxi.\n";
        }         
        else
        {
            cout << "Christ will Park'n'Fly.\n";
        }
    }
    else if (workPaying == 'n')
    {
        cout << "Chris will get dropped off by a friend.\n";
    }
    else
    {
        cout << "Invalid input.";
    }
}