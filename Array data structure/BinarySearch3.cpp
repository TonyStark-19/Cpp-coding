#include <iostream>
#include <vector>
using namespace std;
// Rotated sorted array

int main()
{

    vector<int> arr = {3, 4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();
    int tar = 0;
    int st = 0, end = n - 1;
    bool found = false;

    while (st <= end)
    {

        int mid = st + (end - st) / 2;

        if (arr[mid] == tar)
        {
            cout << mid << endl;
            found = true;
            break;
        }

        if (arr[st] <= arr[mid])
        {
            if (arr[st] <= tar && tar <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }

        else
        {
            if (arr[mid] <= tar && tar <= arr[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    if (!found)
    {
        cout << -1 << endl;
    }

    return 0;
}