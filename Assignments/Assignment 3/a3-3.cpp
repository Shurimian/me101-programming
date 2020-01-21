// Chamath Wijesekera - ME 101
// Assignment 3 Question 3
// Ronald Trang Acknowledged - Attempts at debugging for End of File while loop.

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("CHE_102_grades.txt");

    if (!fin)
    {
        cout << "File not Found" << endl;
        system("PAUSE");
        return EXIT_FAILURE;
    }

    int studentId = 0,
        studentCount = 0,
        highestStudentId = 0,
        lowestStudentId = 0;
    double markSum = 0,
           studentMark = 0,
           highestStudentMark = -1000,
           lowestStudentMark = 1000;

    while (fin >> studentId >> studentMark)
    {   
        if (studentMark > highestStudentMark)
        {
            highestStudentMark = studentMark;
            highestStudentId = studentId;
        }
        else if (studentMark < lowestStudentMark)
        {
            lowestStudentMark = studentMark;
            lowestStudentId = studentId;
        }

        markSum += studentMark;
        studentCount++;
    }
    
    cout << fixed << setprecision(2)
		 << "There are " << studentCount << " students in total\n"
         << highestStudentId << " had the highest mark of " << highestStudentMark << " percent\n"
         << lowestStudentId << " had the lowest mark of " << lowestStudentMark << " percent\n"
         << "The mean grade across all students was " << markSum / studentCount << " percent\n";

    fin.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
