#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
    int n = chars.size();
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = chars[i];
        int count = 0;

        while (i < n && chars[i] == ch)
        {
            count++;
            i++;
        }

        if (count == 1)
        {
            chars[index] = ch;
            index++;
        }
        else
        {
            chars[index] = ch;
            index++;

            string str = to_string(count);
            for (char dig : str)
            {
                chars[index] = dig;
                index++;
            }
        }
        i--;
    }

    chars.resize(index);
    return index;
}

int main()
{

    vector<char> s = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    cout << compress(s) << endl;

    return 0;
}