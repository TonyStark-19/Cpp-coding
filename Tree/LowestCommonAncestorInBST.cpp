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

// Search node by value
Node *search(Node *root, int val)
{
    // base case
    if (root == NULL || root->data == val)
        return root;

    // left sub tree call
    if (val < root->data)
        return search(root->left, val);

    // right sub tree call
    else
        return search(root->right, val);
}

// LCA in BST
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    // base case
    if (root == NULL)
        return NULL;

    // case 1
    if (root->data > p->data && root->data > q->data)
        return lowestCommonAncestor(root->left, p, q);

    // case 2
    if (root->data < p->data && root->data < q->data)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}

int main()
{
    vector<int> arr = {5, 3, 6, 2, 4, 1};

    // Build the BST
    Node *root = NULL;
    for (int val : arr)
    {
        root = insert(root, val);
    }

    // Define the two values whose LCA we want to find
    int val1 = 1;
    int val2 = 4;

    // Search for the nodes in the tree
    Node *p = search(root, val1);
    Node *q = search(root, val2);

    // Find LCA
    Node *lca = lowestCommonAncestor(root, p, q);

    if (lca)
    {
        cout << "Lowest Common Ancestor of " << val1 << " and " << val2 << " is: " << lca->data << endl;
    }
    else
    {
        cout << "Lowest Common Ancestor not found!" << endl;
    }

    return 0;
}