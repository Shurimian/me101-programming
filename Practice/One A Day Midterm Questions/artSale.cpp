#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("floor.txt");
    ofstream fout("output.txt");

    fout << "Name                Perim   Space Cost   Artist Total\n"
         << fixed << setprecision(2);

    string prevArtist = " ";
    string artist = " ";
    int sides = 0;
    double artistCost = 0;
    const double TAX = 0.13;
    
    while(fin >> artist >> sides)
    {
        double cost = 0;
        int quality = 0;
        double perimeterLength = 0;
        for (int side = 0; side < sides; side++)
        {
            double perimeterPiece = 0;
            fin >> perimeterPiece;
            perimeterLength += perimeterPiece;
        }
        
        cost += perimeterLength * 75;

        fin >> quality;
        cost += 50 * quality;

        cost += cost * (1 + TAX);
        
        fout << left<< setw(20) << artist
             << setw(8)  << perimeterLength
             << setw(13) << cost;
        
        if (artist == prevArtist)
        {
            artistCost += cost;
            fout << setw(10) << artistCost << endl;
        }
        else
        {
            artistCost = cost;
            fout << setw(10) << artistCost << endl;
        }  
        prevArtist = artist; 
    }
    fin.close();
    fout.close();
}