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

    // left sub tree recursion call
    root->right = buildTree(preorder);

    return root;
}

// countsum of nodes
int sumOfNodes(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // left subtree call
    int leftSum = sumOfNodes(root->left);

    // right subtree call
    int rightSum = sumOfNodes(root->right);

    return leftSum + rightSum + root->data;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    cout << "Sum of nodes : " << sumOfNodes(root);

    return 0;
}