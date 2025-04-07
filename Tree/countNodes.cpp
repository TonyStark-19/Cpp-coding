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

// count nodes of tree
int countNodes(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // left subtree call
    int leftCount = countNodes(root->left);

    // right subtree call
    int rightCount = countNodes(root->right);

    return leftCount + rightCount + 1;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    cout << "Nodes : " << countNodes(root);

    return 0;
}