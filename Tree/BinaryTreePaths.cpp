#include <iostream>
#include <vector>
#include <string>
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

void allPaths(Node *root, string path, vector<string> &ans)
{
    // if root is not there
    if (!root)
        return;

    // if it is a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(path);
        return;
    }

    if (root->left)
    {
        allPaths(root->left, path + "->" + to_string(root->left->data), ans);
    }

    if (root->right)
    {
        allPaths(root->right, path + "->" + to_string(root->right->data), ans);
    }
}

vector<string> binaryTreePaths(Node *root)
{
    vector<string> ans;
    string path = to_string(root->data);

    allPaths(root, path, ans);
    return ans;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, -1};
    Node *root = buildTree(preorder);

    vector<string> paths = binaryTreePaths(root);

    cout << "Root-to-leaf paths:\n";
    for (const string &p : paths)
    {
        cout << p << endl;
    }

    return 0;
}