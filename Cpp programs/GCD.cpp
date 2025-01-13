#include <iostream>
using namespace std;
// Euclid's Algorithm

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    if (a == 0)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    cout << gcd(20, 28) << endl;

    return 0;
}