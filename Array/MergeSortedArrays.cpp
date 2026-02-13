#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {2, 5, 6};
    int m = 3, n = 3;
    int index = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] >= arr2[j])
        {
            arr1[index] = arr1[i];
            index--;
            i--;
        }
        else
        {
            arr1[index] = arr2[j];
            index--;
            j--;
        }
    }

    while (j >= 0)
    {
        arr1[index] = arr2[j];
        index--;
        j--;
    }

    for (int i = 0; i < m + n; i++)
    {
        cout << arr1[i] << " ";
    }

    return 0;
}