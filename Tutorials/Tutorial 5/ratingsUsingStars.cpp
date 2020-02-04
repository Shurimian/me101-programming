// Chamath Wijesekera - ME 101
// Ratings Using Stars

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void intToStars (int integer)
{
    for (int count = 0; count < integer; count++)
    {
        cout << '*';
    }
    cout << endl;
}

int main()
{
    ifstream fin("ratings.txt");

    if (!fin)
    {
        cout << "File not found.\n";
        return EXIT_FAILURE;
    }

    string movieName = " ";
    int movieRating = 0;

    while (fin >> movieName >> movieRating)
    {
        cout << movieName << ": "; 
        intToStars(movieRating);
        cout << endl;
    }

    fin.close();
}