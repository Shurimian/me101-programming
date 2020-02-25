// Chamath Wijesekera  - ME 101
// Grade Check

#include <cstdlib>
#include <iostream>

using namespace std;

double findCourseGrade (double midtermGrade, double finalGrade)
{
    double option1 = (0.3 * midtermGrade) + (0.7 * finalGrade);
    double option2 = (0.1 * midtermGrade) + (0.9 * finalGrade);
    return max(option1, option2);
}

void isStudentOkay (double courseGrade, char robotReturned)
{
    if (courseGrade > 50 && robotReturned == 'y')
    {
        cout << "Student is okay\n";
    }
    else
    {
        cout << "Student is not okay\n";
    }
}



int main()
{
    double midtermGrade = 0;
    double finalGrade = 0;
    char robotReturned = ' ';
    robotReturned = tolower(robotReturned);
    
    cout << "Enter midterm grade, final grade, and whether robot returned (y/n): ";
    cin >> midtermGrade >> finalGrade >> robotReturned;
    double courseGrade = findCourseGrade(midtermGrade, finalGrade);
    isStudentOkay(courseGrade, robotReturned);
}