// Chamath Wijesekera - ME 101
// Olympic Medal Chart

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void drawMedals(char medalType, int medalQuantity)
{
    for (int count = 0; count < medalQuantity; count++)
    {
        cout << medalType;
    }
}

int main()
{
    ifstream fin("medal.txt");
    
    int mostMedals = -1;
    string mostMedalsCountry = "";

    string country = "";
    int medalsGold = 0;
    int medalsSilver = 0;
    int medalsBronze = 0;
    
    while (fin >> country >> medalsGold >> medalsSilver >> medalsBronze)
    {
        cout << left << setw(15) << country;
        drawMedals('G', medalsGold);
        drawMedals('S', medalsSilver);
        drawMedals('B', medalsBronze);
        cout << endl;

        int medalsTotal = medalsGold + medalsSilver + medalsBronze;
        if(medalsTotal > mostMedals)
        {
            mostMedals = medalsTotal;
            mostMedalsCountry = country;
        }
    }
    cout << "Most medals: " << mostMedalsCountry << " with " << mostMedals << " medals.\n";
}
