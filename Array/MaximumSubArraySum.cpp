#include <iostream>
#include <vector>
using namespace std;
// brute force 

int main()
{

    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int size = sizeof(arr) / sizeof(int);

    int maxSum = 0;

    for (int st = 0; st < size; st++)
    {
        int currSum = 0;
        for (int end = st; end < size; end++)
        {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }

    cout << "Max subarray sum : " << maxSum << endl;

    return 0;
}