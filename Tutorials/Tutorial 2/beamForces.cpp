#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double TOLERANCE = 0;
    
    cout << "Provide the left force in Newtons and its distance in meters from the center: ";
    double forcel = 0;
    double distl = 0;
    cin >> forcel >> distl;
    cout << "Provide the right force in Newtons and its distance in meters from the center: ";
    double forcer = 0;
    double distr = 0;
    cin >> forcer >> distr;

    if (forcel >= 0 && forcer >= 0 && distl >= 0 && distr >= 0)
    {
        double torquel = distl * forcel;
        double torquer = distr * forcer;

        if(fabs(torquel - torquer) <= TOLERANCE)
        {
            cout << "The torques are balanced." << endl;
        }
        else if (torquel > torquer)
        {
            cout << "It will tip to the left" << endl;
        }
        else 
        {
            cout << "It will tip to the right" << endl;
        }
    }
    else
    {
        cout << "Invalid Inputs. Please try again.";
    }
    





    system("PAUSE");
    return EXIT_SUCCESS;

}
