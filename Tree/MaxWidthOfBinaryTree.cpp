#include <iostream>
#include <vector>
#include <queue>
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

// maximum width of binary tree
int widthOfBinaryTree(Node *root)
{
    queue<pair<Node *, unsigned long long>> q;

    // push root
    q.push({root, 0});

    // max width
    int maxWidth = 0;

    while (q.size() > 0)
    {
        // current level size
        int currLevelSize = q.size();

        // starting index
        unsigned long long stIdx = q.front().second;

        // ending index
        unsigned long long endIdx = q.back().second;

        // update max width
        maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

        for (int i = 0; i < currLevelSize; i++)
        {
            auto curr = q.front();
            q.pop();

            if (curr.first->left)
            {
                q.push({curr.first->left, curr.second * 2 + 1});
            }

            if (curr.first->right)
            {
                q.push({curr.first->right, curr.second * 2 + 2});
            }
        }
    }

    return maxWidth;
}

int main()
{
    vector<int> preorder = {1, 3, 5, -1, -1, 3, -1, -1, 2, -1, 9, -1, -1};
    Node *root = buildTree(preorder);

    cout << widthOfBinaryTree(root) << endl;

    return 0;
}