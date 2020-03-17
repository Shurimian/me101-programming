/*
Braille to movement translation
Function: writes a file with coordinates of the next indentation relative to current position
NOTE! This program doesn't take into account new lines or paper margins
Legend for output file:
R -- reset letter
! -- space
Caitlin Ho
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

void letterPath (ifstream & fin, ofstream & fout);
void resetLetter (int currentX, int currentY, ofstream & fout);
void spacePath (ofstream & fout);

int main()
{
    ifstream fin ("brailleTranslateOutput.txt");
    ofstream fout ("brailleMovementOutput.txt");

    if (!fin)
    {
        cout <<"ERROR. FILE NOT READ"<<endl;
        system("PAUSE");
	    return EXIT_SUCCESS;
    }
    else
    {
        char reading;
        while (fin >> reading)
        {
            if (reading == '!')
            //line is a space
            {
                spacePath(fout);
            }
            else
            {
                letterPath(fin,fout);
            }

        }

    }

} 




void spacePath(ofstream & fout)
{
    fout <<"! 2 0"<<endl;
}

//takes print head to the top left corner of next letter
void resetLetter (int currentX, int currentY, ofstream & fout)
{
    const int X_START = 2, Y_START = 0;
    //starting position of next letter relative to current letter's origin is (2,0)
    int xMvmt = 0, yMvmt = 0;

    xMvmt = X_START - currentX;
    yMvmt = Y_START - currentY;

    fout <<"R " << xMvmt << " " <<yMvmt<<endl;

}

//gets the print path for one letter
void letterPath(ifstream & fin, ofstream & fout)
{
    int xGrid [6] = {0, 0, 0, 1, 1, 1};
    int yGrid [6] = {0, -1, -2, 0, -1, -2};
    //parallel arrays with x and y coordinates of all possible points of indentation

    int currentX = 0, currentY = 0, nextX = 0, nextY = 0, currentBox = 0, xMvmt = 0, yMvmt = 0;


    for (int index = 0; index < 6; index ++)//creates path for ONE letter; one letter will have
    {
        fin >> currentBox;
        //read the 1 or 0

        if (currentBox == 1)
        //if there needs to be an indent
        {
            nextX = xGrid[index];
            nextY = yGrid[index];
            //finds the coordinates of the indent

            xMvmt = nextX - currentX;
            yMvmt = nextY - currentY;
            //gets difference in x and y from current position to the indent

            currentX = nextX;
            currentY = nextY;
            //set current x and y to where you just moved to

            fout << xMvmt << " " << yMvmt<<" +"<<endl;
            //output movement and indent symbol
        }
        
    }

    resetLetter (nextX, nextY,fout);
    //call reset function; send current position's x and y points

}

/* Test case output:

*/
