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

Node *nextRight = NULL;

// flatten binary tree to linked-list
void flatten(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // right sub tree call
    flatten(root->right);

    // left sub tree call
    flatten(root->left);

    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
}

// Function to print the flattened linked list
void printFlattenedList(Node *root)
{
    cout << "Flattened linked list: ";
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main()
{
    vector<int> preorder = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};
    Node *root = buildTree(preorder);

    flatten(root);
    printFlattenedList(root);

    return 0;
}