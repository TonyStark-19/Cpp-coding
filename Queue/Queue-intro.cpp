#include <iostream>
#include <vector>
using namespace std;

class Node // class to create a node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    void push(int data) // to push data in queue
    {
        Node *newNode = new Node(data);

        if (empty()) // if queue is empty
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() // to pop date from queue
    {
        if (empty()) // if queue is empty
        {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int front() // to return front value of queue
    {
        if (empty()) // if queue is empty
        {
            cout << "Queue is empty\n";
            return 0;
        }

        return head->data;
    }

    bool empty() // to check if queue is empty
    {
        return head == NULL;
    }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}