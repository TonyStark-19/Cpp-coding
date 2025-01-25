#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getPermut(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back({nums});
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        getPermut(nums, idx + 1, ans);

        // Backtracking
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    getPermut(nums, 0, ans);

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> result = permute(arr);

    // Printing the subsets
    cout << "Permutations are:\n";
    for (const auto &permutation : result)
    {
        cout << "{ ";
        for (int num : permutation)
        {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}