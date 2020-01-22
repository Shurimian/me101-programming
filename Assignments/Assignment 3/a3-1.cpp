// Chamath Wijesekera and Nathan Shen - ME 101
// Assignment 3 Question 1

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char running = ' ';
    do
    { 
        int people = 0;
        double mealCost = 0;
        const double TAX = 0.15;
        double grandTotal = 0;
        double costPerPerson = 0;
        
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
        while (running != 'y' && running != 'n' && running != 'Y' && running != 'N');
    
    } while (running == 'y' || running == 'Y');
    
    cout << "Goodbye." << endl;
    
    system("PAUSE");
    return  EXIT_SUCCESS;
}


/*
Enter the cost of the meal: 100
Enter the number of people to split the bill with: 5
The cost per person is $23.00
Would you like to do another calculation? (y/n) y
Enter the cost of the meal: 56.34
Enter the number of people to split the bill with: 99
The cost per person is $0.65
Would you like to do another calculation? (y/n) y
Enter the cost of the meal: -1
Enter the cost of the meal: 0
Enter the cost of the meal: 30
Enter the number of people to split the bill with: -1
Enter the number of people to split the bill with: 0
Enter the number of people to split the bill with: 9000
The cost per person is $0.00
Would you like to do another calculation? (y/n) n
Goodbye.
Press any key to continue . . . 
*/