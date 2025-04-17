#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

    // Right sub tree recursion call
    root->right = buildTree(preorder);

    return root;
}

// bottom view of binary tree
void bottomView(Node *root)
{
    // pair of node and horizontal distance
    queue<pair<Node *, int>> q;

    // horizontal distance and node value
    map<int, int> m;

    // push root and it's horizontal distance
    q.push({root, 0});

    while (q.size() > 0)
    {
        Node *curr = q.front().first;
        int currHD = q.front().second;

        q.pop();

        // push currHD
        m[currHD] = curr->data;

        // push left sub tree
        if (curr->left != NULL)
        {
            q.push({curr->left, currHD - 1});
        }

        // push right sub tree
        if (curr->right != NULL)
        {
            q.push({curr->right, currHD + 1});
        }
    }

    // print top view nodes
    for (auto it : m)
    {
        cout << it.second << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    bottomView(root);

    return 0;
}