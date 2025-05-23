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

Node *helper(vector<int> &nums, int st, int end)
{
    // base case
    if (st > end)
    {
        return NULL;
    }

    // calulate mid value
    int mid = st + (end - st) / 2;

    Node *root = new Node(nums[mid]);

    // left sub tree call
    root->left = helper(nums, st, mid - 1);

    // right sub tree call
    root->right = helper(nums, mid + 1, end);

    return root;
}

// sorted array to balanced BST
Node *sortedArrayToBST(vector<int> &nums)
{
    return helper(nums, 0, nums.size() - 1);
}

// inorder sequence
void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // left sub tree call
    inorder(root->left);

    // print root
    cout << root->data << " ";

    // right sub tree call
    inorder(root->right);
}

int main()
{
    vector<int> arr = {-10, -3, 0, 5, 9};
    Node *root = sortedArrayToBST(arr);

    cout << "In-order Traversal of Balanced BST: ";
    inorder(root);
    cout << endl;

    return 0;
}