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

// build BST
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
void inorder(Node *root, vector<int> &arr)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // left sub tree call
    inorder(root->left, arr);

    // push root
    arr.push_back(root->data);

    // right sub tree call
    inorder(root->right, arr);
}

// build BST from sorted array
Node *buildBSTFromSorted(vector<int> arr, int st, int end)
{
    // base case
    if (st > end)
    {
        return NULL;
    }

    // mid value
    int mid = st + (end - st) / 2;

    // create root node
    Node *root = new Node(arr[mid]);

    // left subtree call
    root->left = buildBSTFromSorted(arr, st, mid - 1);

    // right subtree call
    root->right = buildBSTFromSorted(arr, mid + 1, end);

    return root;
}

// merge BST
Node *mergeBST(Node *root1, Node *root2)
{
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    // final BST inorder sequence
    vector<int> temp;

    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            temp.push_back(arr1[i++]);
        }
        else
        {
            temp.push_back(arr2[j++]);
        }
    }

    while (i < arr1.size())
    {
        temp.push_back(arr1[i++]);
    }

    while (j < arr2.size())
    {
        temp.push_back(arr2[j++]);
    }

    return buildBSTFromSorted(temp, 0, temp.size() - 1);
}

int main()
{
    vector<int> arr1 = {8, 2, 1, 10};
    vector<int> arr2 = {5, 3, 0};

    Node *root1 = buildBST(arr1);
    Node *root2 = buildBST(arr2);

    Node *root = mergeBST(root1, root2);

    vector<int> seq;
    inorder(root, seq);

    for (int val : seq)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}