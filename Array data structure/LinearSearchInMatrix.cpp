#include <iostream>
using namespace std;

int linearSearch(int mat[][3], int rows, int cols, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;
    int target = 7;

    cout << linearSearch(matrix, rows, cols, target) << endl;

    return 0;
}