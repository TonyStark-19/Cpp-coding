#include <iostream>
#include <vector>
using namespace std;
// stack implementation using vectors

class Stack
{
    vector<int> v;

public:
    void push(int val) // to push elements in stack
    {
        v.push_back(val);
    }

    void pop() // to pop or delete elements from stack
    {
        v.pop_back();
    }

    int top() // to return top value of stack
    {
        return v[v.size() - 1];
    }

    bool empty() // to check if stack is empty
    {
        return v.size() == 0;
    }
};

int main()
{
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}