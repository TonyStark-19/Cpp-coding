#include <iostream>
using namespace std;

int getMaxRowSum(int mat[][3], int rows, int cols)
{
    int maxRowSum = 0;
    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < cols; j++)
        {
            rowSum += mat[i][j];
        }

        maxRowSum = max(maxRowSum, rowSum);
    }

    return maxRowSum;
}

int getMaxColumnSum(int mat[][3], int rows, int cols)
{
    int maxColumnSum = 0;
    for (int j = 0; j < cols; j++)
    {
        int columnSum = 0;
        for (int i = 0; i < rows; i++)
        {
            columnSum += mat[i][j];
        }

        maxColumnSum = max(maxColumnSum, columnSum);
    }

    return maxColumnSum;
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;

    cout << getMaxRowSum(matrix, rows, cols) << endl;
    cout << getMaxColumnSum(matrix, rows, cols) << endl;

    return 0;
}