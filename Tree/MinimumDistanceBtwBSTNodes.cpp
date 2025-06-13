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

// Helper function for in-order traversal to find min difference
void inOrder(Node *root, Node *&prev, int &minDiff)
{
    // base case
    if (root == NULL)
        return;

    // left sub tree call
    inOrder(root->left, prev, minDiff);

    if (prev != NULL)
    {
        minDiff = min(minDiff, root->data - prev->data);
    }
    prev = root;

    // right sub tree call
    inOrder(root->right, prev, minDiff);
}

// Main function to get minimum difference
int minDiffInBST(Node *root)
{
    // previous node
    Node *prev = NULL;

    // minimum difference
    int minDiff = INT_MAX;

    inOrder(root, prev, minDiff);

    return minDiff;
}

int main()
{
    vector<int> arr = {83, 62, 88, 42, 82, 52};

    // Build the BST
    Node *root = NULL;
    for (int val : arr)
    {
        root = insert(root, val);
    }

    // Get the minimum difference
    int result = minDiffInBST(root);
    cout << "Minimum difference between any two nodes in BST: " << result << endl;

    return 0;
}