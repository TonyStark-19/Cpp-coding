#include <iostream>
#include <list>
using namespace std;
// Stack implementation using linked-list

class Stack
{
    list<int> ll;

public:
    void push(int val) // to push elements in stack
    {
        ll.push_front(val);
    }

    void pop() // to pop or delete elements from stack
    {
        ll.pop_front();
    }

    int top() // to return top value of stack
    {
        return ll.front();
    }

    bool empty() // to check if stack is empty
    {
        return ll.size() == 0;
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