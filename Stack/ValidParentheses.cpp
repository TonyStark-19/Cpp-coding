#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') // opening brackets
        {
            st.push(s[i]);
        }
        else // closing bracket
        {
            if (st.size() == 0) // stack is empty or no opening brackets
            {
                return false;
            }

            if (st.top() == '(' && s[i] == ')' ||
                st.top() == '{' && s[i] == '}' ||
                st.top() == '[' && s[i] == ']')
            { // match found
                st.pop();
            }
            else // no match found
            {
                return false;
            }
        }
    }

    return st.size() == 0;
}

int main()
{
    string s1 = "()[]{}";
    string s2 = "(]";

    cout << isValid(s1) << endl;
    cout << isValid(s2) << endl;

    return 0;
}