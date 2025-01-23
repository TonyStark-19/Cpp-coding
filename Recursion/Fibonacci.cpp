#include <iostream>
using namespace std;
// nth sum of fibonacci

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(3) << endl;
    cout << fib(5) << endl;

    return 0;
}