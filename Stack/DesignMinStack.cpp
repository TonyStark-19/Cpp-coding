#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> s; // val , minVal

    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push({val, val});
        }
        else
        {
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.top().first; // val
    }

    int getMin()
    {
        return s.top().second; // minVal
    }
};

int main()
{
    MinStack ms;

    ms.push(-2);
    ms.push(0);
    ms.push(-3);

    cout << "Minimum value : " << ms.getMin() << endl;

    ms.pop();

    cout << "Top value : " << ms.top() << endl;
    cout << "Minimum value : " << ms.getMin() << endl;

    return 0;
}