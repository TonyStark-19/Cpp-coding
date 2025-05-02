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

    // right sub tree recursion call
    root->right = buildTree(preorder);

    return root;
}

void preOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    // left sub tree recursion call
    preOrder(root->left);

    // right sub tree recursion call
    preOrder(root->right);
}

// transform to Sum tree
int sumTree(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // left sub tree call
    int leftSum = sumTree(root->left);

    // right subtree call
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum;

    return root->data;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    cout << "before conversion: ";
    preOrder(root);
    cout << endl;

    sumTree(root);

    cout << "after conversion: ";
    preOrder(root);
    cout << endl;

    return 0;
}