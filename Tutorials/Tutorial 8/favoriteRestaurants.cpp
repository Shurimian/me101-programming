// Chamath Wijesekera - ME 101
// Favorite Restaurants

#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

const int RESTAURANTS = 4;
const int STUDENTS = 200;
const int RATINGS_RANGE = 5;

void tallyRatings (ifstream &fin, int tallyArray[RESTAURANTS][RATINGS_RANGE])
{
    for (int count = 0; count < STUDENTS; count++)
    {
        for (int restaurant = 0; restaurant < RESTAURANTS; restaurant++)
        {
            int rating = 0;
            fin >> rating;
            tallyArray[restaurant][rating - 1]++;
        }
    }
}

int mostCommonRating (int restaurant, int tallyArray[RESTAURANTS][RATINGS_RANGE])
{
    int mostCommonRating = 0;

    for (int rating = 0; rating < RATINGS_RANGE; rating++)
    {
        if (tallyArray[restaurant - 1][rating] > tallyArray[restaurant - 1][mostCommonRating])
        {
            mostCommonRating = rating;
        }
    }
    return mostCommonRating + 1;
}


int main()
{
    ifstream fin("restaurant.txt");
    int tallyArray[RESTAURANTS][RATINGS_RANGE] = {0};

    tallyRatings(fin, tallyArray);

    for (int restaurant = 1; restaurant <= RESTAURANTS; restaurant++)
    {
        cout << "Restaurant " << restaurant << ": " << mostCommonRating(restaurant, tallyArray) << endl;
    }

    fin.close();
    return EXIT_SUCCESS;
}