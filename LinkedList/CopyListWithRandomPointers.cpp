#include <iostream>
#include <unordered_map>
using namespace std;

// Node class to create a node
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int val)
    {
        data = val;
        next = NULL;
        random = NULL;
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

    void setRandom(int nodeIndex, int randomIndex) // to set random pointers
    {
        if (!head)
            return;

        Node *temp = head;
        Node *randomNode = head;
        int count = 0;

        while (temp && count < nodeIndex)
        {
            temp = temp->next;
            count++;
        }

        count = 0;
        while (randomNode && count < randomIndex)
        {
            randomNode = randomNode->next;
            count++;
        }

        if (temp)
            temp->random = randomNode;
    }

    Node *copyRandomList(Node *head)
    {
        if (head == NULL) // base case
        {
            return NULL;
        }

        unordered_map<Node *, Node *> m;

        Node *newHead = new Node(head->data);
        Node *oldTemp = head->next;
        Node *newTemp = newHead;
        m[head] = newHead;

        while (oldTemp != NULL) // plain copy
        {
            Node *copyNode = new Node(oldTemp->data);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL) // random connections copy
        {
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }

    void printLL(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " (random: ";
            if (temp->random)
                cout << temp->random->data;
            else
                cout << "NULL";
            cout << ") -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List ll1;
    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(3);
    ll1.push_back(4);
    ll1.push_back(5);

    // Setting up random pointers
    ll1.setRandom(0, 2); // Node 1 -> Node 3
    ll1.setRandom(1, 4); // Node 2 -> Node 5
    ll1.setRandom(2, 1); // Node 3 -> Node 2
    ll1.setRandom(3, 3); // Node 4 -> Node 4
    ll1.setRandom(4, 0); // Node 5 -> Node 1

    cout << "Original List:" << endl;
    ll1.printLL(ll1.head);

    // Copying the linked list
    List ll2;
    ll2.head = ll1.copyRandomList(ll1.head);

    cout << "Copied List:" << endl;
    ll2.printLL(ll2.head);

    return 0;
}