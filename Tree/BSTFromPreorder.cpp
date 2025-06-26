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

// helper function
Node *helper(vector<int> &preorder, int &i, int bound)
{
    // base case
    if (i >= preorder.size() || preorder[i] > bound)
    {
        return NULL;
    }

    // create root
    Node *root = new Node(preorder[i++]);

    // build left sub tree
    root->left = helper(preorder, i, root->data);

    // build right sub tree
    root->right = helper(preorder, i, bound);

    return root;
}

// build BST from preorder
Node *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return helper(preorder, i, INT_MAX);
}

// inorder sequence
void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // left sub tree call
    inorder(root->left);

    // print root
    cout << root->data << " ";

    // right sub tree call
    inorder(root->right);
}

int main()
{
    vector<int> preorder = {6, 3, 1, 4, 8, 9};

    // Build the BST
    Node *root = bstFromPreorder(preorder);

    cout << "In-order Traversal of Balanced BST: ";
    inorder(root);
    cout << endl;

    return 0;
}