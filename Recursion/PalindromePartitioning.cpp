#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPalin(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());

    return s == s2;
}

void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(partitions);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string part = s.substr(0, i + 1);

        if (isPalin(part)) // palindrome or not
        {
            partitions.push_back(part);
            getAllParts(s.substr(i + 1), partitions, ans); // recursive call

            partitions.pop_back(); // backtracking
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> partitions;

    getAllParts(s, partitions, ans);

    return ans;
}

int main()
{
    string s = "aab";

    vector<vector<string>> result = partition(s);

    cout << "Palindrome partitions:\n";
    for (const auto &partition : result)
    {
        cout << "[ ";
        for (const auto &word : partition)
        {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}