#include <iostream>
#include <queue>
using namespace std;
// implementation of stack using 2 queues

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack s1;

    s1.push(1);
    s1.push(2);

    cout << "Top: " << s1.top() << endl;
    cout << "Popped: " << s1.pop() << endl;

    cout << "Is empty: " << s1.empty() << endl;

    return 0;
}