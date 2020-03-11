// Chamath Wijesekera and Emily Tou - ME 101
// Assignment 8 Question 1

/* 
ARRAY IMPLEMENTATIONN 

Parking Current
    Composed of two 1D arrays consisting of 50 items each to represent the parking spaces. Each array stores data as follows:
        Array 1 - Occupation
          1 = staff
          0 = student
          -1 = empty 
        Array 2 - Name

Parking Add / Parking Remove
    Composed of a 2D array consisting of two rows. Each row stores data as follows:
        Array 1 - Occupation
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

int main()
{
  // Current Parking
  int currentTitle[PARKING_SPACES] = {-1};
  string currentName[PARKING_SPACES] = {""};

  // Add/Remove Parking
  int addRemoveTitle[MAX_IN_OUT] = {0};
  string addRemoveName[MAX_IN_OUT] = {""};
}


// Question b)
void populateCurrentParking(ifstream &fin, int occupations[], string names[])
{
  int index = 0;
  int occupation = 0;
  string name = "";

  while (fin >> occupation >> name >> index)
  {
    occupations[index - 1] = occupation;
    names[index - 1] = name;
  }
  
}

//question (c)
void populatearray(ifstream & fin, int occupation[25], string name[25])
{
  int occupation = 0;
  int index = 0;
  string name = 0;
  while (fin >> occupation >> name)
  {
  ocupation[index] = occupation;
  name[index] = name;
  index++;
  }
}

//question (d)
void deleteparkingspace(string onepersonname, int occupation[25], string name[25])
{
  int index = 0;
  while(index < 25)
  {
  if (onepersonname == name[index])
  {
    name[index] = "";
  }
  index++;
  }
}

// Question e)
int lowestValidSpace(int titleArray[], int title)
{
  int validSpace = -1;

  for (int index = 0; index < PARKING_SPACES; index++)
  {
    if(titleArray[index] = -1)
    {
      if(title = 1)
      {
        validSpace = index;
      }
      else if (title = 0 && index > 25)
      {
        validSpace = index;
      }
    }
  }
  return validSpace;
}

//question (f)
void assignapproproiateparking(int occupation[25], string name[25], string onepersonname, int status)
{
     int assignparkingspace = lowestValidSpace(int occupation, string name, int status);
     occupation[assignedparkingspace] = status;
     name[assignedparkingspace] = name;
}

// Question g)

void reassignSpots(int titleArray[], string nameArray[])
{
  int spaceReassignedTo = 0;
  for (int index = 25; index < 49; index++)
  {
    if(titleArray[index] = 1)
    {
      spaceReassignedTo = lowestValidSpace(titleArray, 1);
    }
  }
}




// Question h)
void outputData(ofstream &fout, int titleArray[], string nameArray[])
{
  for (int index = 0; index < PARKING_SPACES; index++)
  {
    if(titleArray[index] != -1)
    {
      cout << titleArray[index] << nameArray[index] << index << endl;
    }  
  }
}
