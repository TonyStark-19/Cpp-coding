#include <iostream>
using namespace std;

// Node class to create a node
class Node
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

// List class to manage linked list operations
class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = tail = NULL;
    }

    void push_back(int val) // Add node to the end
    {
        Node *newNode = new Node(val);

        if (head == NULL) // Empty linked list
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node *mergeTwoLists(Node *head1, Node *head2) // Merge two sorted lists
    {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;

        if (head1->data <= head2->data)
        {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }

    void printLL(Node *head) // Print linked list from given head
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
    List ll1, ll2;

    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(5);
    cout << "List 1: ";
    ll1.printLL(ll1.head);

    ll2.push_back(2);
    ll2.push_back(3);
    ll2.push_back(6);
    cout << "List 2: ";
    ll2.printLL(ll2.head);

    // Merging the two lists
    Node *mergedHead = ll1.mergeTwoLists(ll1.head, ll2.head);

    // Printing the merged list
    cout << "Merged List: ";
    ll1.printLL(mergedHead);

    return 0;
}