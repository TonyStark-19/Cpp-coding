#include <iostream>
#include <vector>
using namespace std;
// more optimal approach

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

int ans = 0;

// height of tree
int height(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // left subtree call
    int leftHt = height(root->left);

    // right subtree call
    int rightHt = height(root->right);

    // current diameter of root node
    ans = max(ans, leftHt + rightHt);

    return max(leftHt, rightHt) + 1;
}

// diameter of tree
int diameterOfBinaryTree(Node *root)
{
    height(root);
    return ans;
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node *root = buildTree(preorder);

    cout << "Diameter : " << diameterOfBinaryTree(root) << endl;

    return 0;
}