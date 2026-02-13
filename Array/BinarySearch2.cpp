#include <iostream>
#include <vector>
using namespace std;
// Recursive method

int binarySearch(vector<int> arr, int tar, int st, int end)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (tar > arr[mid])
        {
            return binarySearch(arr, tar, mid + 1, end);
        }
        else if (tar < arr[mid])
        {
            return binarySearch(arr, tar, st, mid - 1);
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // even
    int tar1 = 12;
    int st1 = 0, end = arr1.size() - 1;

    cout << binarySearch(arr1, tar1, st1, end) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // odd
    int tar2 = 0;
    int st2 = 0;
    end = arr2.size() - 1;

    cout << binarySearch(arr2, tar2, st2, end) << endl;

    return 0;
}