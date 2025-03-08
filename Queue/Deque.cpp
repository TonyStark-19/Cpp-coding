#include <iostream>
#include <deque>
using namespace std;
// deque implementation using STL

int main()
{
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    dq.push_front(4);

    cout << dq.front() << " " << dq.back() << endl;

    dq.pop_back();
    cout << dq.front() << " " << dq.back() << endl;

    return 0;
}