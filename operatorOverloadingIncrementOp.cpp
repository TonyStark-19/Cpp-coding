#include <iostream>
using namespace std;

class demo
{
    int x;

public:
    void getdata()
    {
        cout << "Enter value of x : ";
        cin >> x;
    }
    void putdata()
    {
        cout << "x : " << x;
    }
    void operator++()
    {
        x = x + 1;
    }
};

int main()
{
    demo obj;
    obj.getdata();
    cout << "Orignal value : ";
    obj.putdata();
    ++obj;
    cout << "\nValue after increment : ";
    obj.putdata();
    return 0;
}