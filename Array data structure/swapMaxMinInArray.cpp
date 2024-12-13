#include <iostream>
using namespace std;

void SwapMaxMin(int arr[], int size);

int main()
{

    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    int size = sizeof(arr) / sizeof(int);

    SwapMaxMin(arr, size);
}

void SwapMaxMin(int arr[], int size)
{
    int maxIndex = 0, minIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    swap(arr[maxIndex], arr[minIndex]);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}