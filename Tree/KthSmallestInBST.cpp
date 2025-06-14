#include <iostream>
#include <vector>
#include <climits>
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

// previous order
int prevOrder = 0;

// kth smallest in BST
int kthSmallest(Node *root, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }

    // left sub tree call
    if (root->left != NULL)
    {
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1)
        {
            return leftAns;
        }
    }

    if (prevOrder + 1 == k)
    {
        return root->data;
    }
    prevOrder += 1;

    // right sub tree call
    if (root->right != NULL)
    {
        int rightAns = kthSmallest(root->right, k);
        if (rightAns != -1)
        {
            return rightAns;
        }
    }

    return -1;
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

    int k = 4;
    cout << kthSmallest(root, k) << endl;

    return 0;
}