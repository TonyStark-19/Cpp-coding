#include <iostream>
#include <vector>
using namespace std;
// Kadane's algorithm

int main()
{

    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int size = sizeof(arr) / sizeof(int);

    int currSum = 0, maxSum = 0;

    for (int i = 0; i < size; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    cout << "Max subarray sum : " << maxSum << endl;

    return 0;
}