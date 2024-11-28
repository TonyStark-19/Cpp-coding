#include <iostream>
using namespace std;

class sample
{
    int y;

public:
    void getdata()
    {
        cout << "\nEnter value of y : ";
        cin >> y;
    }
    void operator==(sample s)
    {
        if (y == s.y)
        {
            cout << "Objects are equal";
        }
        else
        {
            cout << "Objects are not equal";
        }
    }
};

int main()
{
    sample a1, a2;
    cout << "Enter object 1 value : ";
    a1.getdata();
    cout << "Enter object 2 value : ";
    a2.getdata();
    a1 == a2;
    return 0;
}