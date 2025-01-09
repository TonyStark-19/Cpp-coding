#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    string str = "Hello world";

    reverse(str.begin(), str.end());
    cout << str << endl;

    return 0;
}