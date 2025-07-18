#include <iostream>
#include <vector>
#include <stack>
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

// BST Iterator class
class BSTIterator
{
public:
    stack<Node *> s;

    // sotre left nodes
    void storeLeftNodes(Node *root)
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
    }

    // constructor
    BSTIterator(Node *root)
    {
        storeLeftNodes(root);
    }

    // next value
    int next()
    {
        Node *ans = s.top();
        s.pop();

        storeLeftNodes(ans->right);

        return ans->data;
    }

    // has next value or not
    bool hasNext()
    {
        return s.size() > 0;
    }
};

int main()
{
    Node *root = NULL;

    // Sample values to insert in BST
    vector<int> values = {10, 5, 15, 3, 7, 12, 18};

    for (int val : values)
    {
        root = insert(root, val);
    }

    // Create BST Iterator
    BSTIterator it(root);

    cout << "BST in sorted (in-order) order: ";
    while (it.hasNext())
    {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}