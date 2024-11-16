#include <iostream>
using namespace std;

class test
{
    int code;
    static int count;

public:
    void setcode()
    {
        code = ++count;
    }
    void showcode()
    {
        cout << "Object number : " << count << "\n";
    }
    static void showcount()
    {
        cout << "Count : " << count << "\n";
    }
};

int test::count;

int main()
{
    test t1, t2;
    t1.setcode();
    t2.setcode();
    test::showcount();
    test t3;
    t3.setcode();
    test::showcount();
    t1.showcode();
    t2.showcode();
    t3.showcode();
    return 0;
}