#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

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

//question (f)
void assignapproproiateparking(int occupation[25], string name[25], string onepersonname, int status)
{
     int assignparkingspace = lowestValidSpace(int occupation, string name, int status);
     occupation[assignedparkingspace] = status;
     name[assignedparkingspace] = name;
}

