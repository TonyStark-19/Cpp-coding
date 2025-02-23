#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// using prefix array

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);

    lmax[0] = height[0];
    rmax[n - 1] = height[n - 1];

    // calculating left max value
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], height[i]);
    }

    // calculating right max value
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], height[i]);
    }

    int ans = 0;

    // calculating ans
    for (int i = 0; i < n; i++)
    {
        ans += min(lmax[i], rmax[i]) - height[i];
    }

    return ans;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trap(arr) << endl;

    return 0;
}