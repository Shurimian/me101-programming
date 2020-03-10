// Chamath Wijesekera - ME 101
// Magic Squares

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 3;
    
    int square[SIZE][SIZE] = {0};

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << "Enter value at row " << row + 1 << ", col " << col + 1 << ": ";
            cin >> square[row][col];
        }
    }

    // Sum row
    cout << "Sum rows: ";
    for (int row = 0; row < SIZE; row++)
    {
        int rowSum = 0;
        for (int col = 0; col < SIZE; col++)
        {
            rowSum += square[row][col];
        }
        cout << rowSum << " ";
    }
    cout << endl;

    // Sum col

    cout << "Sum cols: ";
    for (int col = 0; col < SIZE; col++)
    {
        int colSum = 0;
        for (int row = 0; row < SIZE; row++)
        {
            colSum += square[row][col];
        }
        cout << colSum << " ";
    }
    cout << endl;

    // Sum Diag

        cout << "Sum diags: ";
        int diagSum1 = 0;
        int diagSum2 = 0;
    for (int diag = 0; diag < SIZE; diag++)
    { 
        diagSum1 += square[diag][diag];
        diagSum2 += square[SIZE - diag][SIZE - diag];
    }
    cout << diagSum1 << " " << diagSum2 << endl;
}