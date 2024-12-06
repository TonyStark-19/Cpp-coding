#include <iostream>
using namespace std;

class Base
{
public:
    void display()
    {
        cout << "\nDisplay Base";
    }

    virtual void show()
    {
        cout << "\nShow Base";
    }
};

class Derived : public Base
{
public:
    void display()
    {
        cout << "\nDisplay derived";
    }

    void show()
    {
        cout << "\nShow derived";
    }
};

int main()
{
    Base B;
    Derived D;
    Base *bptr;
    cout << "bptr points to base";
    bptr = &B;
    bptr->display();
    bptr->show();
    cout << "\nbptr points to derived";
    bptr = &D;
    bptr->display();
    bptr->show();
    return 0;
}