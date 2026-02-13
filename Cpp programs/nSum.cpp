#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter your number: ";
    cin >> n;

    bool isValid = true;

    if (n <= 0)
    {
        isValid = false;
    }

    if (isValid)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }

        cout << "Sum is : " << sum << endl;
        ;
    }
    else
    {
        cout << "Number is invalid" << endl;
    }

    return 0;
}