#include <iostream>
using namespace std;

class A
{
public:
    void display()
    {
        cout << "\nBase class";
    }
};

class B : public A
{
public:
    void display()
    {
        cout << "\nDerived class";
    }
};

int main()
{
    B obj;
    obj.display();
    obj.A::display();
    return 0;
}