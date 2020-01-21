// Chamath Wijesekera - ME101
// Luggage Allowance

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    const float WEIGHT_LIMIT_KG = 23;
    const float LBS_TO_KG = 0.453592;
    cout << "Enter suitcase weight: ";
    double weight = 0;
    string unit = "";
    cin >> weight >> unit;
    if (weight > 0)
    {
        if (unit == "lbs" || unit == "lb" || unit == "pounds" || unit == "pound")
        {
            weight *= LBS_TO_KG;
        }

        if (weight <= 23)
        {
            cout << "Your bag meets the weight requirements" << endl;
        }
        else
        {
            cout << "Your bag is too heavy and does not meet the weight requirement." << endl;
        }
    }
    else
    {
        cout << "Invalid Weight" << endl;
    }
    
    system("PAUSE");
	return EXIT_SUCCESS;
}
