#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end) // sorting
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]); // if left half elements are remaining
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]); // if right half elements are remaining
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx]; // copy values
    }
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // right half

        merge(arr, st, mid, end); // backtracking
    }
}

int main()
{

    vector<int> arr = {12, 31, 35, 8, 32, 17};

    mergeSort(arr, 0, arr.size() - 1); // merge sort call

    for (int val : arr) // print values
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}