#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileIn("CHE_102_grades.txt");

    if (!fileIn)
    {
        cout << "File not Found" << endl;
        system("PAUSE");
        return EXIT_FAILURE;
    }
    
    string test = "";
    double mark = 0;
    for (int i = 0; i < 1; i++)
    {
    	fileIn >> test;
    	fileIn >> mark;
    	cout << test << mark;
	}
}
