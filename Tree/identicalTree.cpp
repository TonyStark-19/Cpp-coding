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

    // right sub tree recursion call
    root->right = buildTree(preorder, idx);

    return root;
}

// identical tree or not

bool isSameTree(Node *p, Node *q)
{
    // base case
    if (p == NULL || q == NULL)
    {
        return p == q;
    }

    // left sub tree recursion call
    bool isLeftSame = isSameTree(p->left, q->left);

    // right sub tree recursion call
    bool isRightSame = isSameTree(p->right, q->right);

    return isLeftSame && isRightSame && p->data == q->data;
}

int main()
{
    vector<int> preorder1 = {1, 2, -1, -1, 3, -1, -1};
    vector<int> preorder2 = {1, 2, -1, -1, 3, -1, -1};

    int idx1 = -1;
    Node *root1 = buildTree(preorder1, idx1);

    int idx2 = -1;
    Node *root2 = buildTree(preorder2, idx2);

    cout << isSameTree(root1, root2) << endl;

    return 0;
}