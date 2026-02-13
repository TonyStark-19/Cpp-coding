#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// hashing

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];
        int sec = target - first;

        if (m.find(sec) != m.end())
        {
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }

        m[first] = i;
    }

    return ans;
}

int main()
{

    vector<int> nums = {5, 2, 11, 7, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}