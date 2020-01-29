#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("oneStudent.txt");

    if (!fin)
    {
        cout << "File not found";
        system("PAUSE");
        return EXIT_FAILURE;
    }

    int grade = 0;
    int prevGrade = 0;

    fin >> prevGrade;

    while (fin >> grade)
    {
        if (grade > prevGrade)
        {
            cout << "Grade Increased\n";
        }
        else if (grade < prevGrade)
        {
            cout << "Grade Decreased\n";
        }
        else
        {
            cout << "No Grade Change\n";
        }

        prevGrade = grade;
    }

    fin.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}