#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAlphaNum(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    int st = 0, end = s.length() - 1;

    while (st < end)
    {
        if (!isAlphaNum(s[st]))
        {
            st++;
            continue;
        }
        if (!isAlphaNum(s[end]))
        {
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }

        st++;
        end--;
    }
    return true;
}

int main()
{

    string str = "Ac3?e3c&a";

    cout << isPalindrome(str) << endl;

    return 0;
}