#include <iostream>
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

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL) // empty linked list
        {
            head = tail = newNode;
            return;
        }
        else // not empty
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void printLL()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.printLL();

    return 0;
}