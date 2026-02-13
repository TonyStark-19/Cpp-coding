#include <iostream>
using namespace std;
// using recursion

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

    Node *reverseKGroup(Node *head, int k)
    {
        Node *temp = head;
        int count = 0;

        // check if k nodes exist
        while (count < k)
        {
            if (temp == NULL)
            {
                return head;
            }
            temp = temp->next;
            count++;
        }

        // recursive call for rest of linked list
        Node *prevNode = reverseKGroup(temp, k);

        // reverse current group
        temp = head;
        count = 0;

        while (count < k)
        {
            Node *next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }

        return prevNode;
    }

    void printLL(Node *head) // to print linked list
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* getHead() {
        return head;
    }
    
    void setHead(Node* newHead) {
        head = newHead;
    }
};

int main()
{
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original Linked List: ";
    ll.printLL(ll.getHead());

    int k = 2; // Group size for reversal
    Node *newHead = ll.reverseKGroup(ll.getHead(), k);
    ll.setHead(newHead);

    cout << "Reversed Linked List in groups of " << k << ": ";
    ll.printLL(ll.getHead());

    return 0;
}