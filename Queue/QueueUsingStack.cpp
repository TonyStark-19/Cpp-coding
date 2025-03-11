#include <iostream>
#include <stack>
using namespace std;
// implementation of queue using 2 stack

class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    MyQueue q1;

    q1.push(1);
    q1.push(2);

    cout << "Top: " << q1.peek() << endl;
    cout << "Popped: " << q1.pop() << endl;

    cout << "Is empty: " << q1.empty() << endl;

    return 0;
}