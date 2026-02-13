#include <iostream>
using namespace std;

int main()
{
    long long n, r;

    cout << "Enter your number: ";
    cin >> n;

    int count = 0;
    while (n > 0)
    {
        r = n % 10;
        n = n / 10;
        count++;
    }

    cout << "Number of digits is : " << count << endl;

    return 0;
}