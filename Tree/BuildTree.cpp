#include <iostream>
#include <vector>
using namespace std;
// buildtree using preorder and inorder sequence

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

// search root node
int search(vector<int> &inorder, int left, int right, int val)
{
    for (int i = left; i <= right; i++)
    {
        if (inorder[i] == val)
        {
            return i;
        }
    }

    return -1;
}

// helper function
Node *helper(vector<int> &preorder, vector<int> &inorder, int &preIdx, int left, int right)
{

    // base case
    if (left > right)
    {
        return NULL;
    }

    Node *root = new Node(preorder[preIdx]);

    // inorder index
    int inIdx = search(inorder, left, right, preorder[preIdx]);
    preIdx++;

    // left subtree call
    root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);

    // right subtree call
    root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

    return root;
}

// buildtree
Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // preoder index
    int preIdx = 0;

    return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node *root = buildTree(preorder, inorder);

    // print root of tree
    cout << root->data << endl;

    return 0;
}