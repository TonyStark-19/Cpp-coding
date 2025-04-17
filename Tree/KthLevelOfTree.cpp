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

static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;

    // base case
    if (preorder[idx] == -1)
    {
        return NULL;
    }

    // create root node
    Node *root = new Node(preorder[idx]);

    // left sub tree recursion call
    root->left = buildTree(preorder);

    // Right sub tree recursion call
    root->right = buildTree(preorder);

    return root;
}

void KthLevel(Node *root, int k)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    // print node value
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }

    // left sub tree call
    KthLevel(root->left, k - 1);

    // right sub tree call
    KthLevel(root->right, k - 1);
}

int main()
{
    vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    KthLevel(root, 3);

    return 0;
}