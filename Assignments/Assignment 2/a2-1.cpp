// Chamath Wijesekera and Tarj Tandel
// Assignment 2 Question 1

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string cellStructure = "";
    double radius = 0;
    double volume = 0;

    cout << "Enter the type of cell structure (SC, BCC, or FCC): ";
    cin >> cellStructure;
    cout << "Enter radius in Angstroms: ";
    cin >> radius;

    if (cellStructure != "SC" && cellStructure != "sc" && 
        cellStructure != "BCC" && cellStructure != "bcc" && 
        cellStructure != "FCC" && cellStructure != "fcc")
    {
        cout << "Invalid Cell Structure! Please try again." << endl;
    }
    else if (radius <= 0)
    {
        cout << "Invalid radius. Please try again." << endl;
    }
    else
    {
        if (cellStructure == "sc" || cellStructure == "SC")
        {
            volume = pow(2 * radius, 3);    
        }
        else if (cellStructure == "bcc" || cellStructure == "BCC")
        {
            volume = pow(((4 * radius) / sqrt(3)), 3);
        }
        else
        {
            volume = pow(((4 * radius) / sqrt(2)), 3);
        }
        
        cout << "The resulting volume is " << volume << endl;
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}


/*
Enter the type of cell structure (SC, BCC, or FCC): SC
Enter radius in Angstroms: 2
The resulting volume is 64
Press any key to continue . . .
*/

/*
Enter the type of cell structure (SC, BCC, or FCC): BCC
Enter radius in Angstroms: 3
The resulting volume is 332.554
Press any key to continue . . .
*/

/*
Enter the type of cell structure (SC, BCC, or FCC): FCC
Enter radius in Angstroms: 5.5
The resulting volume is 3764.64
Press any key to continue . . .
*/

/*
Enter the type of cell structure (SC, BCC, or FCC): ABC
Invalid Cell Structure! Please try again.
Press any key to continue . . .
*/

/*
Enter the type of cell structure (SC, BCC, or FCC): SC
Enter radius in Angstroms: -1
Invalid radius. Please try again.
Press any key to continue . . .
*/

