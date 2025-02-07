#include <iostream>
using namespace std;
// Slow and fast pointer approach

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

class List // class to add, delete, print and search nodes
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_back(int val) // add node on back or end of linked list
    {
        Node *newNode = new Node(val);

        if (head == NULL) // empty linked list
        {
            head = tail = newNode;
            return;
        }
        else // not empty
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // has cycle function

    bool hasCycle()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }

    void printLL() // to print linked list
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    ll.printLL();
    cout << ll.hasCycle() << endl;

    return 0;
}