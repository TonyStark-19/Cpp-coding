#include <iostream>
using namespace std;
// brute force

int main()
{

    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(arr) / sizeof(int);

    int maxWater = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int w = j - i;
            int h = min(arr[i], arr[j]);
            int currWater = w * h;

            maxWater = max(maxWater, currWater);
        }
    }

    cout << "Max water : " << maxWater << endl;

    return 0;
}