#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// building BT and implementing different tree traversals

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

// preorder traversal
void preOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // print root
    cout << root->data << " ";

    // recursive call for left sub tree
    preOrder(root->left);

    // recursive call for right sub tree
    preOrder(root->right);
}

// inorder traversal
void inOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive call for left sub tree
    inOrder(root->left);

    // print root
    cout << root->data << " ";

    // recursive call for right sub tree
    inOrder(root->right);
}

// postorder traversal
void postOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive call for left sub tree
    postOrder(root->left);

    // recursive call for right sub tree
    postOrder(root->right);

    // print root
    cout << root->data << " ";
}

// level order traversal
void levelOrder(Node *root)
{
    queue<Node *> q;

    // push root
    q.push(root);
    // to mark level of tree
    q.push(NULL);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            // next line case
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            // empty tree case
            else
            {
                break;
            }
        }

        cout << curr->data << " ";

        // push left sub tree
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }

        // push right sub tree
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }

    cout << endl;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    preOrder(root);
    cout << endl;

    inOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;

    levelOrder(root);

    return 0;
}