#include <iostream>
using namespace std;

class CircularQueue // cricular queue
{
    int *arr;
    // current size and capacity of array
    int currSize, cap;
    // front and rear pointers
    int f, r;

public:
    // constructor to initialize array
    CircularQueue(int size)
    {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0, r = -1;
    }

    void push(int data) // to push element in circular queue
    {
        if (currSize == cap) // to check if Circular queue is full
        {
            cout << "CQ is full\n";
            return;
        }

        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop() // to pop element from circular queue
    {
        if (empty()) // to check if Circular queue is full
        {
            cout << "CQ is full\n";
            return;
        }

        f = (f + 1) % cap;
        currSize--;
    }

    int front() // to return front value of circular queue
    {
        if (empty()) // to check if Circular queue is full
        {
            cout << "CQ is full\n";
            return -1;
        }

        return arr[f];
    }

    bool empty() // to check if circular queue is empty
    {
        return currSize == 0;
    }

    void printArr() // to print array
    {
        for (int i = 0; i < cap; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);

    cq.pop();
    cq.push(4);

    while (!cq.empty())
    {
        cout << cq.front() << " ";
        cq.pop();
    }
    cout << endl;

    return 0;
}