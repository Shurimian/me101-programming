// Chamath Wijesekera - ME 101
// Sending Thank You Cards

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int daysSinceBirth (int month, int day)
{
    return month % 9 * 30 + day;
}

int main()
{
    ifstream fin("gift.txt");
    ofstream fout("note.txt");

    string person = "";
    string gift = "";
    int month = 0;
    int day = 0;
    
    string longestWaitPerson = "";
    string longestWaitGift = "";
    int longestWait = 100000;

    while (fin >> person >> gift >> month >> day)
    {
        int waitDays = daysSinceBirth(month, day);
        if (waitDays < longestWait)
        {
            longestWait = waitDays;
            longestWaitPerson = person;
            longestWaitGift = gift;
        }

        fout << person << ", thank you for the " << gift 
             << ", sorry it took " << waitDays << " days.\nMichael" 
             << endl << endl;
    }
    cout << longestWaitPerson << " has been waiting the longest.\n";
    fin.close();
    fout.close();
}