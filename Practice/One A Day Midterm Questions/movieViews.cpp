// Chamath Wijesekera - ME 101
// Movie Views

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream fin("movieViews.txt");

    string lowestViewsGenre = " ";
    int lowestViewsNumber = 1e6;
    string genre = " ";

    while (fin >> genre)
    {
        int views = 0;
        int viewsSum = 0;
        int viewsCount = 0;
        while (fin >> views && views != -1)
        {
            viewsSum += views;
            viewsCount++;
        }
        
        double avgViews = viewsSum / viewsCount;
        if (avgViews < lowestViewsNumber)
        {
            lowestViewsNumber = avgViews;
            lowestViewsGenre = genre;
        }
    }
    cout << lowestViewsGenre << ": " << lowestViewsNumber * 1000 << endl;
}