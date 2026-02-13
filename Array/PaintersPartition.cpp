#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime)
{
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedTime)
        {
            return false;
        }

        if (time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }

        else
        {
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}

int minTimeToPaint(vector<int> &arr, int n, int m) // O(log(sum) * n)
{
    if (m > n)
    {
        return -1;
    }

    int sum = 0;
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    int st = largest, end = sum; // range of possible answers
    int ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> arr = {40, 30, 10, 20};
    int n = 4, m = 2;

    cout << minTimeToPaint(arr, n, m) << endl;
    return 0;
}