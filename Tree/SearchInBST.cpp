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

// build binary search tree
Node *buildBST(vector<int> arr)
{
    Node *root = NULL;

    for (int val : arr)
    {
        root = insert(root, val);
    }

    return root;
}

// search values in BST
bool search(Node *root, int key)
{
    // base case
    if (root == NULL)
    {
        return false;
    }

    // key found
    if (root->data == key)
    {
        return true;
    }

    // left sub tree call
    if (key < root->data)
    {
        return search(root->left, key);
    }

    // right sub tree call
    else
    {
        return search(root->right, key);
    }
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node *root = buildBST(arr);
    cout << search(root, 5) << endl;
    cout << search(root, 8) << endl;

    return 0;
}