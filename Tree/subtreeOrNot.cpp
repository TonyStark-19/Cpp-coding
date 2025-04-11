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

Node *buildTree(vector<int> preorder, int &idx)
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
    root->left = buildTree(preorder, idx);

    // left sub tree recursion call
    root->right = buildTree(preorder, idx);

    return root;
}

// is identical or not
bool isIdentical(Node *p, Node *q)
{
    if (p == NULL || q == NULL)
    {
        return p == q;
    }

    return p->data == q->data && isIdentical(p->left, q->left) &&
           isIdentical(p->right, q->right);
}

// subtree or not
bool isSubtree(Node *root, Node *subRoot)
{
    if (root == NULL || subRoot == NULL)
    {
        return root == subRoot;
    }

    if (root->data == subRoot->data && isIdentical(root, subRoot))
    {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    vector<int> preorder1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx1 = -1;
    Node *root = buildTree(preorder1, idx1);

    vector<int> preorder2 = {3, 4, -1, -1, 5, -1, -1};
    int idx2 = -1;
    Node *subRoot = buildTree(preorder2, idx2);

    cout << isSubtree(root, subRoot) << endl;

    return 0;
}