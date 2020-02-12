// Chamath Wijesekera - ME 101
// One a Day Midterm - ION Usage Statistics

#include <cstdlib>
#include <fstream>
#include <iostream>


using namespace std;

int main()
{
    ifstream fin("ION_time.txt");

    if (!fin)
    {
        cout << "File not found.\n";
        return EXIT_FAILURE;
    }

    int inputValue = 0;
    bool isNorthbound = true;
    int longestNorthboundWait = -1;
    int totalSum = 0;
    int totalCount = 0;
    int prevTrain = 0;

    while (fin >> inputValue)
    {         
        isNorthbound = inputValue;
        int waitTime = 0;
        int prevTrain = 0;
        for (int count = 0; count < 15; count++)
        {
            fin >> inputValue;
            waitTime = inputValue - prevTrain;
            if (isNorthbound)
            {
                if (waitTime > longestNorthboundWait)
                {
                    longestNorthboundWait = waitTime;
                }
            }
        
            totalSum += waitTime;
            prevTrain = inputValue;
            totalCount++;
        
        }
        
    }

    cout << "Longest time between Northbound trains: " << longestNorthboundWait << " minutes" << endl
         << "Average wait time between trains: " << double(totalSum) / totalCount << " minutes" << endl;
    fin.close();
    return EXIT_SUCCESS;
}