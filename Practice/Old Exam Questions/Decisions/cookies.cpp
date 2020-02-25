// Chamath Wijesekera  - ME 101
// Cookies

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    char initial = ' ';
    char hunger = ' ';
    string cookie = "";

    cout << "Enter an initial, hunger (y/n), and cookie: ";
    cin >> initial >> hunger >> cookie;

    initial = tolower(initial);
    hunger = tolower(hunger);

    // Eat when hungry case
    
    if (initial == 'm' && hunger == 'y')
    {
        cout << "Will eat\n";
    }
    else if ((initial == 'r' || initial == 't') && (cookie == "mint"))
    {
        cout << "Will eat\n";
    }
    else
    {
        cout << "Will not eat\n";
    }
}