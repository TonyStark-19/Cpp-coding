#include <iostream>
using namespace std;

int nSum(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n + nSum(n - 1);
}

int main()
{
    cout << nSum(10) << endl;
    cout << nSum(5) << endl;

    return 0;
}