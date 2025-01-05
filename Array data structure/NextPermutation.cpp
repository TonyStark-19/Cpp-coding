#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int piv = -1;

    for (int i = n - 2; i >= 0; i--) // pivot finding logic
    {
        if (arr[i] < arr[i + 1])
        {
            piv = i;
            break;
        }
    }

    if (piv == -1) // if pivot is still -1 means array is in decreasing order
    {
        reverse(arr.begin(), arr.end());
    }

    for (int i = n - 1; i > piv; i--) // to find next larger value from the end
    {
        if (arr[i] > arr[piv])
        {
            swap(arr[i], arr[piv]);
            break;
        }
    }

    int i = piv + 1, j = n - 1; // to reverse value after pivot

    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}