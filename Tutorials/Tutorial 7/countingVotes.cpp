// Chamath Wijesekera - ME 101
// Counting Votes

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("election.txt");
    int candidate[6] = {0};
    int spoiledBallots = 0;
    int vote = 0;
    int highestVotes = -1;
    int highestCandidate = 0;
    while (fin >> vote)
    {
        if(vote <= 6 && vote > 0)
        {
            candidate[vote - 1]++;
        }
        else
        {
            spoiledBallots++;
        }
        
    }

    for (int row = 0; row < 6; row++)
    {
        cout << "Candidate " << row + 1 << setw(5) 
             << candidate[row] << endl;

        if (candidate[row] > highestVotes)
        {
            highestVotes = candidate[row];
            highestCandidate = row + 1;
        }
    }
    cout << "Highest Votes: " << highestVotes << " for Candidate "
         << highestCandidate << endl
         << "Spoiled Ballots: " << spoiledBallots << endl;

    fin.close();
}