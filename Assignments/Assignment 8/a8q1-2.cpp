// Chamath Wijesekera and Emily Tou - ME 101
// Assignment 8 Question 1

/* 
ARRAY IMPLEMENTATIONN 

Parking Current
    Composed of two 1D arrays consisting of 50 items each to represent the parking spaces. Each array stores data as follows:
        Array 1 - Status
          1 = staff
          0 = student
          -1 = empty 
        Array 2 - Name

Parking Add / Parking Remove
    Composed of a 2D array consisting of two rows. Each row stores data as follows:
        Array 1 - Status
          1 = staff
          0 = student
        Array 2 - Name

Empty parking spots will be represented as "-1" in the current parking occupation array 
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const int PARKING_SPACES = 50;
const int MAX_IN_OUT = 25;

// Question b)
void populateCurrentParking(ifstream &fin, int statuses[], string names[])
{
    int index = 0;
    int status = 0;
    string name = "";

    while (fin >> status >> name >> index)
    {
        statuses[index - 1] = status;
        names[index - 1] = name;
        index++;
    }
}

//question (c)
void populateAddRemove(ifstream &fin, int statuses[], string names[])
{
    int status = -1;
    int index = 0;
    string name = "";
    while (fin >> status >> name)
    {
        statuses[index] = status;
        names[index] = name;
        index++;
    }
}

//question (d)
void deleteParking(string name, int statuses[], string names[])
{
    for (int index = 0; index < PARKING_SPACES; index++)
    {
        if (name == names[index])
        {
            names[index] = "";
            statuses[index] = -1;
        }
    }
}

// Question e)
int lowestValidSpace(int statuses[], int status)
{
    int validSpace = -1;

    for (int index = 0; index < PARKING_SPACES; index++)
    {
        cout << index << endl;
        if (statuses[index] = -1)
        {
            if (status == 1)
            {
                validSpace = index;
                cout << validSpace << " " << index << endl;
                return validSpace;

            }
            else if (status == 0 && index > 25)
            {
                validSpace = index;
                return validSpace;
            }
        }
    }
    return validSpace;
}

//question (f)
void assignParking(int statuses[], string names[], string name, int status)
{
    int assignedSpace = lowestValidSpace(statuses, status);
    if (assignedSpace != -1)
    {
        statuses[assignedSpace] = status;
        names[assignedSpace] = name;
    }
}

// Question g)
void reassignSpots(int statuses[], string names[])
{
    int spaceReassignedTo = -1;
    for (int index = 25; index < 49; index++)
    {
        cout << index << endl;
        if (statuses[index] = 1)
        {
            spaceReassignedTo = lowestValidSpace(statuses, 1);
            if (spaceReassignedTo < 25)
            {
                deleteParking(names[index], statuses, names);
                assignParking(statuses, names, names[index], statuses[index]);
            }
        }
    }
}

// Question h)
void outputData(ofstream &fout, int statuses[], string names[])
{
    for (int index = 0; index < PARKING_SPACES; index++)
    {
        if (statuses[index] != -1)
        {
            fout << left
                 << setw(3) << statuses[index] 
                 << setw(20)<< names[index] 
                 << index + 1 << endl;
        }
    }
}

// Question i)
int main()
{
    ifstream finCurrent("parking_current.txt");
    ifstream finAdd("parking_add.txt");
    ifstream finRemove("parking_remove.txt");

    if (!finCurrent || !finAdd || !finRemove)
    {
        cout << "A file was not found.";
        return EXIT_FAILURE;
    }

    ofstream fout("parking_update.txt");

    // Current Parking
    int currentStatuses[PARKING_SPACES] = {-1};
    string currentNames[PARKING_SPACES] = {""};

    // Add/Remove Parking
    int addRemoveStatuses[MAX_IN_OUT] = {-1};
    string addRemoveNames[MAX_IN_OUT] = {""};

    populateCurrentParking(finCurrent, currentStatuses, currentNames);
    populateAddRemove(finRemove, addRemoveStatuses, addRemoveNames);
    finRemove.close();

    for (int index = 0; index < MAX_IN_OUT; index++)
    {
        deleteParking(addRemoveNames[index], currentStatuses, currentNames);
    }

    reassignSpots(currentStatuses, currentNames);

    int test[MAX_IN_OUT] = {1};

    for (int i = 0; i < MAX_IN_OUT; i++)
    {
        cout << test[i] << endl;
    }


}

