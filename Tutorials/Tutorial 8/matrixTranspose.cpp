// Chamath Wijesekera - ME 101
// Matrix Transpose

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

void prepMatrix (ifstream &fin, double matrix[MAX_SIZE][MAX_SIZE], int &row, int &col)
{
    fin >> row >> col;
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            fin >> matrix[rowIndex][colIndex];
        }
    }
}

void writeTranspose (ofstream &fout, double matrix[MAX_SIZE][MAX_SIZE], int &row, int &col)
{
    for (int rowIndex = 0; rowIndex < col; rowIndex++)
    {
        for (int colIndex = 0; colIndex < row; colIndex++)
        {
            fout << right << setw(5) << matrix[colIndex][rowIndex] << " ";
        }
        fout << endl;
    }
}

int main()
{
    ifstream fin("matrix.txt");
    if (!fin)
    {
        cout << "File not found";
        return EXIT_FAILURE;
    }

    ofstream fout("transposeOut.txt");

    int rows = 0;
    int cols = 0;
    double matrix[MAX_SIZE][MAX_SIZE] = {0};
    
    prepMatrix(fin, matrix, rows, cols);
    writeTranspose(fout, matrix, rows, cols);
}