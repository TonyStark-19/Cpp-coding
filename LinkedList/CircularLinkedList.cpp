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

class CircularList // class to add, delete, print and search nodes
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void insertAtHead(int val) // to insert node at head
    {
        Node *newNode = new Node(val);

        if (head == NULL) // empty linked list
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val) // to insert node at tail
    {
        Node *newNode = new Node(val);

        if (head == NULL) // empty linked list
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead() // to delete node from head
    {
        if (head == NULL) // empty linked list
        {
            return;
        }
        else if (head == tail) // one node in the list
        {
            delete head;
            head = tail = NULL;
        }
        else // more than one node in list
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail() // to delete node from tail
    {
        if (head == NULL) // empty linked list
        {
            return;
        }
        else if (head == tail) // one node in the list
        {
            delete head;
            head = tail = NULL;
        }
        else // more than one node in list
        {
            Node *temp = tail;
            Node *prev = head;

            while (prev->next != tail)
            {
                prev = prev->next;
            }

            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void printLL() // to print linked list
    {
        if (head == NULL)
            return;

        cout << head->data << " -> ";
        Node *temp = head->next;

        while (temp != head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    CircularList cll;

    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);

    cll.printLL();

    cll.deleteAtTail();
    cll.printLL();

    return 0;
}