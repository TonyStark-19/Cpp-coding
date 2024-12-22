#include <iostream>
using namespace std;
// two pointer approach

int main()
{

    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(arr) / sizeof(int);

    int maxWater = 0;
    int lp = 0, rp = n - 1;

    while (lp < rp)
    {
        int w = rp - lp;
        int h = min(arr[lp], arr[rp]);
        int currWater = w * h;

        maxWater = max(maxWater, currWater);

        if (arr[lp] < arr[rp])
        {
            lp++;
        }
        else
        {
            rp--;
        }
    }

    cout << "Max water : " << maxWater << endl;

    return 0;
}