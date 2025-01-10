#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string removeOccurrences(string s, string part)
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{

    string str = "daabcbaabcbc";
    string part = "abc";

    cout << removeOccurrences(str, part) << endl;

    return 0;
}