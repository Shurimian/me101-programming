// Chamath Wijesekera and Tarj Tandel
// Assignment 2 Question 3

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int birthYear = 0;
    int birthMonth = 0;
    int birthDay = 0;
    int currentYear = 0;
    int currentMonth = 0;
    int currentDay = 0;
    int age = 0;

    cout << "Enter your birthday (year month day): ";
    cin >> birthYear >> birthMonth >> birthDay;
    cout << "Enter the current date (year month day): ";
    cin >> currentYear >> currentMonth >> currentDay;

    age = currentYear - birthYear;
    
    if (currentMonth == birthMonth && currentDay < birthDay)
    {
    	age--;
    }
    
    if (currentMonth < birthMonth)
    {
        age--;
    }

    cout << "You are " << age << " years old." << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}


/*
Case 1 - Year Carry-Over
Enter your birthday (year month day): 2000 12 31
Enter the current date (year month day): 2020 1 1
You are 19 years old.
Press any key to continue . . .
*/

/*
Case 2 - Same Day
Enter your birthday (year month day): 2000 12 31
Enter the current date (year month day): 2020 12 31
You are 20 years old.
Press any key to continue . . .
*/

/*
Case 3 - Same Month, Different Day
Enter your birthday (year month day): 2001 09 21
Enter the current date (year month day): 2020 09 1
You are 18 years old.
Press any key to continue . . .
*/

/*
Case 4 - Different Month, Same Day
Enter your birthday (year month day): 2001 09 21
Enter the current date (year month day): 2020 10 21
You are 19 years old.
Press any key to continue . . .
*/
