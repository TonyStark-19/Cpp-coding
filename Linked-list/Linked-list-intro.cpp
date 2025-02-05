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

class List // class to add, delete, print and search nodes
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val) // add node on front of linked list
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

    void pop_front() // delete node from front of linked list
    {
        if (head == NULL) // empty linked list
        {
            cout << "LL is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    void pop_back() // delete node from back or end of linked list
    {
        if (head == NULL) // empty linked list
        {
            cout << "LL is empty\n";
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos) // to insert or add a node at specific position
    {
        if (pos < 0)
        {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid position\n";
                return;
            }

            temp = temp->next;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
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

    int search(int key) // to search a node
    {
        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }

            temp = temp->next;
            idx++;
        }

        return -1;
    }
};

int main()
{
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.insert(4, 1);

    ll.printLL();

    cout << ll.search(2) << endl;

    return 0;
}