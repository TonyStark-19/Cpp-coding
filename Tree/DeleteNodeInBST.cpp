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

// build binary search tree
Node *buildBST(vector<int> arr)
{
    Node *root = NULL;

    for (int val : arr)
    {
        root = insert(root, val);
    }

    return root;
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

// find inorder successor
Node *getInorderSuccessor(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// delete node
Node *delNode(Node *root, int key)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    // left sub tree call
    if (key < root->data)
    {
        root->left = delNode(root->left, key);
    }

    // right sub tree call
    else if (key > root->data)
    {
        root->right = delNode(root->right, key);
    }

    // key == root
    else
    {
        // case 1
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // case 2
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // case 3 (2 child)
        else
        {
            Node *IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
        }
    }

    return root;
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node *root = buildBST(arr);

    cout << "before : ";
    inorder(root);
    cout << endl;

    delNode(root, 6);

    cout << "after : ";
    inorder(root);
    cout << endl;

    return 0;
}