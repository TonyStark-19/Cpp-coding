#include <iostream>
using namespace std;

void sumArr(int arr[], int size);
void productArr(int arr[], int size);

int main()
{

    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    int size = sizeof(arr) / sizeof(int);

    sumArr(arr, size);
    productArr(arr, size);

    return 0;
}

void sumArr(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    cout << "Sum : " << sum << endl;
}

void productArr(int arr[], int size)
{
    int product = 1;
    for (int i = 0; i < size; i++)
    {
        product *= arr[i];
    }

    cout << "Product : " << product << endl;
}