#include <iostream>
using namespace std;

int main()
{

    int n = 4, num = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    return 0;
}