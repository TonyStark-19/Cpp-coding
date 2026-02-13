#include <iostream>
#include <vector>
using namespace std;

bool searchInRow(vector<vector<int>> &matrix, int target, int row)
{
    int n = matrix[0].size();
    int st = 0, end = n - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (target == matrix[row][mid])
        {
            return true;
        }
        else if (target > matrix[row][mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();

    int startRow = 0, endRow = m - 1;
    while (startRow <= endRow)
    {
        int midRow = startRow + (endRow - startRow) / 2;

        if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1])
        {
            return searchInRow(matrix, target, midRow);
        }
        else if (target >= matrix[midRow][n - 1])
        {
            startRow = midRow + 1;
        }
        else
        {
            endRow = midRow - 1;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 34;

    cout << searchMatrix(matrix, target) << endl;

    return 0;
}