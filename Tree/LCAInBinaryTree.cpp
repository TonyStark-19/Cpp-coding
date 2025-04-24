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

// Build tree from preorder traversal
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

    // left subtree
    root->left = buildTree(preorder);

    // right subtree
    root->right = buildTree(preorder);

    return root;
}

// Find a node with a given value
Node *findNode(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
        return root;

    Node *leftResult = findNode(root->left, val);
    if (leftResult != NULL)
        return leftResult;

    return findNode(root->right, val);
}

// Lowest common ancestor function
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;

    if (root->data == p->data || root->data == q->data)
        return root;

    Node *leftLCA = lowestCommonAncestor(root->left, p, q);
    Node *rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA && rightLCA)
        return root;
    else if (leftLCA != NULL)
        return leftLCA;
    else
        return rightLCA;
}

int main()
{
    vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    // Find two nodes
    Node *p = findNode(root, 4);
    Node *q = findNode(root, 5);

    // Find and print LCA
    Node *lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
        cout << "Lowest Common Ancestor: " << lca->data << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;

    return 0;
}