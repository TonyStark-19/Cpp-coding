#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> m;
    queue<int> q;

    for (int i = 0; i < s.size(); i++)
    {
        // push the unique elements
        if (m.find(s[i]) == m.end())
        {
            q.push(i);
        }

        // increase char frequency in map
        m[s[i]]++;

        // pop non unique elements
        while (q.size() > 0 && m[s[q.front()]] > 1)
        {
            q.pop();
        }
    }

    return q.empty() ? -1 : q.front();
}

int main()
{

    string s = "leetcode";

    cout << firstUniqChar(s) << endl;

    return 0;
}