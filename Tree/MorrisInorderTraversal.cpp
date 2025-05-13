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

    // left sub tree recursion call
    root->right = buildTree(preorder);

    return root;
}

// morris algorithm
vector<int> inorderTraversal(Node *root)
{
    vector<int> ans;

    // current node
    Node *curr = root;

    while (curr != NULL)
    {
        // if left subtree does not exist
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }

        else
        {
            // find the inorder predecessor IP
            Node *IP = curr->left;

            while (IP->right != NULL && IP->right != curr)
            {
                IP = IP->right;
            }

            // connection not formed
            if (IP->right == NULL)
            {
                // create connection
                IP->right = curr;
                curr = curr->left;
            }
            else
            {
                // destroy connection
                IP->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    vector<int> ans = inorderTraversal(root);

    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}