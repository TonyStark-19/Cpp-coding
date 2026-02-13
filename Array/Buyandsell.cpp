#include <iostream>
using namespace std;

int main()
{

    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(int);
    int mp = 0;
    int bestbuy = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > bestbuy)
        {
            mp = max(mp, arr[i] - bestbuy);
        }
        bestbuy = min(bestbuy, arr[i]);
    }

    cout << "Max profit : " << mp;
}