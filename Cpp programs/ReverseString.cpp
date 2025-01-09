#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    int n = s.size();
    int st = 0, end = n - 1;

    while (st < end)
    {
        swap(s[st], s[end]);
        st++;
        end--;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}