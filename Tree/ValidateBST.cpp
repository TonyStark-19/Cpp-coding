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

// helper
bool helper(Node *root, Node *min, Node *max)
{
    // case 1
    if (root == NULL)
    {
        return true;
    }

    // case 2
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }

    // case 3
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    return helper(root->left, min, root) && helper(root->right, root, max);
}

// validate BST
bool isValidBST(Node *root)
{
    return helper(root, NULL, NULL);
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node *root = buildBST(arr);

    cout << isValidBST(root);

    return 0;
}