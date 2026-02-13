#include <iostream>
using namespace std;

int main()
{

    int arr[] = {5, 15, 22, 1, -15, 24};
    int size = sizeof(arr) / sizeof(int);
    int smallest = arr[0];
    int largest = arr[0];

    // smallest in arr logic
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    cout << "Smallest is : " << smallest << endl;

    // largest in arr logic
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    cout << "Largest is : " << largest << endl;
}