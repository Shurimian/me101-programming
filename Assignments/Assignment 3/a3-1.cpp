// Chamath Wijesekera - ME 101
// Assignment 3 Question 1

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char running = ' ';
    while (running != 'n')
    { 
        int people = 0;
        double mealCost = 0;
        const double TAX = 0.15;
        double grandTotal = 0;
        double costPerPerson = 0;
        running = ' ';
        
        do
        {
            cout << "Enter the cost of the meal: ";
            cin >> mealCost;
        } while (mealCost <= 0);

        do
        {
            cout << "Enter the number of people to split the bill with: ";
            cin >> people; 
        } while (people <= 0);

        grandTotal = mealCost + (mealCost * TAX);

        costPerPerson = grandTotal / people;

        cout << fixed << setprecision(2);
        cout << "The cost per person is $" << costPerPerson << endl;

        do
        {
            cout << "Would you like to do another calculation? (y/n) ";
            cin >> running;
        }
        while (running != 'y' && running != 'n');
    
    }
    
    system("PAUSE");
    return  EXIT_SUCCESS;
}
