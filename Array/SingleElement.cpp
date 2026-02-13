#include <iostream>
using namespace std;
// brute force

int main()
{

    int arr[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        if (arr[i - 1] != arr[i] && arr[i] != arr[i + 1])
        {
            cout << arr[i] << endl;
        }
    }

    return 0;
}