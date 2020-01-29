#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("allStudent.txt");

    if (!fin)
    {
        cout << "File not found";
        system("PAUSE");
        return EXIT_FAILURE;
    }

    const int PERFECT_GRADE = 10;

    int perfectGrades = 0;

    for (int student = 0; student < 25; student++)
    {
        
        int grade = 0;
        int prevGrade = 0;
        int gradesIncreased = 0;
        fin >> prevGrade;

        if (prevGrade == PERFECT_GRADE)
        {
            perfectGrades++;  
        }
        
        for (int quiz = 0; quiz < 4; quiz++)
        {
            fin >> grade;

            if (grade > prevGrade)
            {
                gradesIncreased++;
            }

            if (grade == PERFECT_GRADE)
            {
                perfectGrades++;
            }
            
            prevGrade = grade;
        
        }

        cout << gradesIncreased << endl;
    }

    cout << "Perfect Grades: " << perfectGrades << endl;

    fin.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}