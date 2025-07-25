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

// right Most In Left Subtree
Node *rightMostInLeftSubtree(Node *root)
{
    Node *ans;

    while (root != NULL)
    {
        ans = root;
        root = root->right;
    }

    return ans;
}

// left Most In Right Subtree
Node *leftMostInRightSubtree(Node *root)
{
    Node *ans;

    while (root != NULL)
    {
        ans = root;
        root = root->left;
    }

    return ans;
}

// find Predecessor & Successor in BST
vector<int> getPredSucc(Node *root, int key)
{
    Node *curr = root; // current node
    Node *pred = NULL; // Predecessor
    Node *succ = NULL; // Successor

    while (curr != NULL)
    {
        if (key < curr->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else if (key > curr->data)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            if (curr->left != NULL)
            {
                // inorder pred
                pred = rightMostInLeftSubtree(curr->left);
            }

            if (curr->right != NULL)
            {
                // inorder succ
                succ = leftMostInRightSubtree(curr->right);
            }

            break;
        }
    }

    return {pred->data, succ->data};
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    vector<int> ans = getPredSucc(root, key);
    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;

    return 0;
}