#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int getCelebrity(vector<vector<int>> arr)
{
    stack<int> s;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        s.push(i); // push all index value
    }

    while (s.size() > 1)
    {
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if (arr[i][j] == 0)
        {
            s.push(i);
        }
        else
        {
            s.push(j);
        }
    }

    int celeb = s.top();

    for (int i = 0; i < n; i++)
    {
        if ((i != celeb) && (arr[i][celeb] == 0 || arr[celeb][i] == 1))
        {
            return -1; // no celebrity exits
        }
    }

    return celeb;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    int ans = getCelebrity(arr);

    cout << "Celebrity is : " << ans << endl;

    return 0;
}