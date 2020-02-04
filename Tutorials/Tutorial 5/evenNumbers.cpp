// Chamath Wijesekera - ME 101
// Tutorial 5 - Even Numbers

#include <cstdlib>
#include <iostream>

using namespace std;

bool isEven (int number)
{
    return number % 2 == 0;
}


int main ()
{
    cout << "Enter a number:";
    int inputNumber = 0;
    cin >> inputNumber;

    if (isEven(inputNumber))
    {
        cout << "Even";
    }
    else 
    {
        cout << "Odd";
    }
}