#include <iostream>
#include <vector>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// isert node
Node *insert(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return new Node(val);
    }

    // left sub tree call
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }

    // right sub tree call
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Global pointers for anomaly detection
Node *first = NULL;
Node *sec = NULL;
Node *previous = NULL;

// inorder sequence
void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // left sub tree call
    inorder(root->left);

    // finding anomaly pairs
    if (previous != NULL && previous->data > root->data)
    {
        // first value
        if (first == NULL)
        {
            first = previous;
        }
        // second value
        sec = root;
    }

    // update previous
    previous = root;

    // right sub tree call
    inorder(root->right);
}

// Recover BST
void recoverTree(Node *root)
{
    inorder(root);

    // swap values
    int temp = first->data;
    first->data = sec->data;
    sec->data = temp;
}

// Print in-order traversal
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    // Building BST
    Node *root = new Node(10);

    // anomaly
    root->left = new Node(20); // should be 5
    root->right = new Node(5); // should be 20

    // other nodes
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    recoverTree(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}