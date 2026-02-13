#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter your number: ";
    cin >> n;

    int count = 0;
    for (int i = n; i >= 1; i--)
    {
        if (n % i == 0)
        {
            count++;
        }
    }

    if (count == 2)
    {
        cout << n << " is a prime number" << endl;
    }
    else
    {
        cout << n << " is not a prime number" << endl;
    }
    
    return 0;
}