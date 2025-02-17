#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    // stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans(price.size(), 0);
    stack<int> s;

    for (int i = 0; i < price.size(); i++)
    {
        while (s.size() > 0 && price[s.top()] <= price[i]) // to remove leeser values
        {
            s.pop();
        }

        if (s.empty()) // no previous high value
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - s.top();
        }

        s.push(i);
    }

    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}