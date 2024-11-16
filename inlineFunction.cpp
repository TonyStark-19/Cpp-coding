#include <iostream>
using namespace std;

class operation
{
    int a, b, add, sub, mul;
    float div;

public:
    void getdata();
    void sum();
    void diff();
    void product();
    void division();
};

inline void operation::getdata()
{
    cout << "Enter value of a : ";
    cin >> a;
    cout << "Enter value of b : ";
    cin >> b;
}

inline void operation::sum()
{
    add = a + b;
    cout << "Sum is : " << add;
}

inline void operation::diff()
{
    sub = a - b;
    cout << "\nSubtraction is : " << sub;
}

inline void operation::product()
{
    mul = a * b;
    cout << "\nProduct is : " << mul;
}

inline void operation::division()
{
    div = a / b;
    cout << "\nDivision is : " << div;
}

int main()
{
    operation a;
    a.getdata();
    a.sum();
    a.diff();
    a.product();
    a.division();
    return 0;
}