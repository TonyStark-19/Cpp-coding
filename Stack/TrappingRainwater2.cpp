#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// using two pointer approach

int trap(vector<int> &height)
{
    int n = height.size();
    int ans = 0;
    int l = 0, r = n - 1; // two pointer
    int lmax = 0, rmax = 0;

    while (l < r)
    {
        // calculating left max value
        lmax = max(lmax, height[l]);

        // calculating right max value
        rmax = max(rmax, height[r]);

        // calculating ans
        if (lmax < rmax)
        {
            ans += lmax - height[l];
            l++;
        }
        else
        {
            ans += rmax - height[r];
            r--;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trap(arr) << endl;

    return 0;
}