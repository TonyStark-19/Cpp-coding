#include <iostream>
using namespace std;

int main()
{

    int n = 4;

    // top
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }

        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }

        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < i + 1; j++)
        {
            cout << " *";
        }

        cout << endl;
    }

    // bottom
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }

        // spaces
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }

        // spaces
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << " *";
        }

        cout << endl;
    }
}