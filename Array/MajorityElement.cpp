#include <iostream>
#include <vector>
using namespace std;
// brute force

int main()
{

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int n = nums.size();

    for (int val : nums)
    {
        int freq = 0;

        for (int el : nums)
        {
            if (el == val)
            {
                freq++;
            }
        }
        if (freq > n / 2)
        {
            cout << val;
            break;
        }
    }

    return 0;
}