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

// info class
class Info
{
public:
    int min, max, size;

    Info(int mi, int ma, int sz)
    {
        min = mi;
        max = ma;
        size = sz;
    }
};

// helper function
Info helper(Node *root)
{
    // base case
    if (root == NULL)
    {
        return Info(INT_MAX, INT_MIN, 0);
    }

    // left sub tree call
    Info left = helper(root->left);

    // right sub tree call
    Info right = helper(root->right);

    if (root->data > left.max && root->data < right.min)
    {
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSz = left.size + right.size + 1;

        return Info(currMin, currMax, currSz);
    }

    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
}

// find size of largest BST in BT
int largestBSTinBT(Node *root)
{
    Info info = helper(root);
    // max BST size
    return info.size;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout << largestBSTinBT(root) << endl;
}