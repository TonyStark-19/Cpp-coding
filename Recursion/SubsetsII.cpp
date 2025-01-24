#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
{
    if (i == arr.size())
    {
        allSubsets.push_back(ans);
        return;
    }

    // Inclusion
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1, allSubsets);

    ans.pop_back(); // backtrack

    int idx = i + 1; // to skip duplicates
    while (idx < arr.size() && arr[idx] == arr[idx - 1])
    {
        idx++;
    }

    // Exclusion
    printSubsets(arr, ans, idx, allSubsets);
}

vector<vector<int>> subsetsWithDup(vector<int> &arr)
{
    sort(arr.begin(), arr.end()); // sort the array first

    vector<vector<int>> allSubsets;
    vector<int> ans;

    printSubsets(arr, ans, 0, allSubsets);

    return allSubsets;
}

int main()
{
    vector<int> arr = {1, 2, 2};

    vector<vector<int>> result = subsetsWithDup(arr);

    // Printing the subsets
    cout << "Unique subsets are:\n";
    for (const auto &subset : result)
    {
        cout << "{ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}