#include <iostream>
using namespace std;
// using recursion

class Node // class to create a node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node *child;

    Node(int val)
    {
        data = val;
        next = prev = child = NULL;
    }
};

class DoublyList // class to add, delete, print and search nodes
{
public:
    Node *head;
    Node *tail;

    DoublyList()
    {
        head = tail = NULL;
    }

    Node *flatten(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->child != NULL) // if node has a valid child
            {
                Node *next = curr->next;
                curr->next = flatten(curr->child); // recursive call
                curr->next->prev = curr;
                curr->child = NULL;

                // find tail
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }

                // attach tail with next ptr
                if (next != NULL)
                {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }

    void printList(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyList dll;

    // Creating nodes
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *n9 = new Node(9);
    Node *n10 = new Node(10);
    Node *n11 = new Node(11);
    Node *n12 = new Node(12);

    // Connecting main doubly linked list
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    n5->next = n6;
    n6->prev = n5;

    // Adding child nodes
    n3->child = n7;
    n7->next = n8;
    n8->prev = n7;
    n8->next = n9;
    n9->prev = n8;
    n9->next = n10;
    n10->prev = n9;

    n8->child = n11;
    n11->next = n12;
    n12->prev = n11;

    // Assign head
    dll.head = n1;

    cout << "Original list (with child pointers):" << endl;
    dll.printList(dll.head);

    // Flatten list
    dll.head = dll.flatten(dll.head);

    cout << "Flattened list:" << endl;
    dll.printList(dll.head);

    return 0;
}