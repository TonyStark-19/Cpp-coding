#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1, pivot = arr[end];

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]); // left partition
        }
    }

    idx++;
    swap(arr[end], arr[idx]); // assigning pivot the right index

    return idx;
}

void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx - 1);  // left half call
        quickSort(arr, pivIdx + 1, end); // right half call
    }
}

int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    quickSort(arr, 0, arr.size() - 1);

    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}