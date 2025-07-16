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
    Node *next;

    Node(int val)
    {
        data = val;
        left = right = next = NULL;
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

// populate next right pointers
Node *connect(Node *root)
{
    // base case
    if (root == NULL || root->left == NULL)
    {
        return root;
    }

    // create queue
    queue<Node *> q;

    // push root
    q.push(root);
    // push null to mark the end of a level
    q.push(NULL);

    // previous pointer
    Node *prev = NULL;

    while (q.size() > 0)
    {
        // current node
        Node *curr = q.front();
        // pop the node
        q.pop();

        // if current is null
        if (curr == NULL)
        {
            if (q.size() == 0)
            {
                break;
            }

            q.push(NULL);
        }
        else
        {
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }

            if (prev != NULL)
            {
                prev->next = curr;
            }
        }

        prev = curr;
    }

    return root;
}

// Print the next pointers for each level
void printNextPointers(Node *root)
{
    Node *levelStart = root;
    while (levelStart)
    {
        Node *curr = levelStart;
        levelStart = nullptr;

        while (curr)
        {
            cout << curr->data << " -> ";
            if (!levelStart)
            {
                if (curr->left)
                    levelStart = curr->left;
                else if (curr->right)
                    levelStart = curr->right;
            }
            curr = curr->next;
        }

        cout << "NULL" << endl;
    }
}

int main()
{
    Node *root = NULL;
    vector<int> values = {10, 5, 15, 3, 7, 12, 18};

    for (int val : values)
    {
        root = insert(root, val);
    }

    root = connect(root);

    cout << "Level-wise 'next' pointers:\n";
    printNextPointers(root);

    return 0;
}