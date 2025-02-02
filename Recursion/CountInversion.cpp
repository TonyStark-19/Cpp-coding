#include <iostream>
#include <vector>
using namespace std;
// using merge sort

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;

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
            invCount += (mid - i + 1); // inversion count
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

    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        int leftInvCount = mergeSort(arr, st, mid);       // left half
        int rightInvCount = mergeSort(arr, mid + 1, end); // right half

        int invCount = merge(arr, st, mid, end); // backtracking

        return leftInvCount + rightInvCount + invCount;
    }

    return 0;
}

int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};

    int ans = mergeSort(arr, 0, arr.size() - 1);

    cout << "Inversion count : " << ans << endl;

    return 0;
}