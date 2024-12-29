#include <iostream>
using namespace std;
// brute force

int main()
{

    int arr[] = {0, 3, 8, 9, 5, 2};
    int n = sizeof(arr) / sizeof(int);

    int largest = arr[0];
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            index = i;
        }
    }
    cout << index;

    return 0;
}