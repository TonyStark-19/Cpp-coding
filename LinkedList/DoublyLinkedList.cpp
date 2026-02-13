#include <iostream>
using namespace std;

class Node // class to create a node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList // class to add, delete, print and search nodes
{
    Node *head;
    Node *tail;

public:
    DoublyList()
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
            head->prev = newNode;
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
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() // delete node from front of linked list
    {
        if (head == NULL) // empty linked list
        {
            cout << "DLL is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        temp->next = NULL;

        delete temp;
    }

    void pop_back() // delete node from back or end of linked list
    {
        if (head == NULL) // empty linked list
        {
            cout << "DLL is empty\n";
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail != NULL)
        {
            tail->next = NULL;
        }

        temp->prev = NULL;
        delete temp;
    }

    void printLL() // to print linked list
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyList dll;

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);

    dll.pop_back();

    dll.printLL();

    return 0;
}