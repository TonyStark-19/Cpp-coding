# Trees (Advanced)

## Overview

Advanced tree problems are heavily **recursive** and test your ability to:

- Break problems into subproblems
- Return multiple values from recursion
- Optimize solutions to O(n)

These concepts are very common in coding interviews.

---

## Recursive Thinking in Trees

Most tree problems follow this pattern:

1. Define the base case
2. Solve for left subtree
3. Solve for right subtree
4. Combine results

---

## Maximum Depth / Height (Revisited)

```cpp
int maxDepth(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```
---

## Check if Two Trees are Identical

```cpp
bool isSameTree(Node* p, Node* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    if(p->data != q->data) return false;

    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
```
---

## Mirror / Invert a Binary Tree

```cpp
Node* invertTree(Node* root) {
    if(root == NULL) return NULL;

    Node* left = invertTree(root->left);
    Node* right = invertTree(root->right);

    root->left = right;
    root->right = left;
    return root;
}
```
---

## Maximum Path Sum in Binary Tree

The maximum sum path may start and end at any node.

```cpp
int maxPath(Node* root, int &ans) {
    if(root == NULL) return 0;

    int left = max(0, maxPath(root->left, ans));
    int right = max(0, maxPath(root->right, ans));

    ans = max(ans, root->data + left + right);
    return root->data + max(left, right);
}
```
---

## Lowest Common Ancestor (LCA)

```cpp
Node* LCA(Node* root, Node* p, Node* q) {
    if(root == NULL || root == p || root == q)
        return root;

    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);

    if(left && right) return root;
    return left ? left : right;
}
```
---

## Check if Tree is Symmetric

```cpp
bool isMirror(Node* a, Node* b) {
    if(a == NULL && b == NULL) return true;
    if(a == NULL || b == NULL) return false;
    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}
```
---

## Sum of Nodes at Each Level

Uses recursion with level tracking.

```cpp
void levelSum(Node* root, int level, vector<int>& res) {
    if(root == NULL) return;
    if(level == res.size()) res.push_back(0);

    res[level] += root->data;
    levelSum(root->left, level + 1, res);
    levelSum(root->right, level + 1, res);
}
```
---

## Diameter of Tree (Optimized – Revision)

- Uses postorder traversal
- Solved in O(n)

---

## Time & Space Complexity

| Problem         | Time | Space |
| --------------- | ---- | ----- |
| Tree Traversals | O(n) | O(h)  |
| LCA             | O(n) | O(h)  |
| Max Path Sum    | O(n) | O(h)  |
| Invert Tree     | O(n) | O(h)  |

---

## Common Mistakes

- Forgetting base cases
- Recomputing values (causing O(n²))
- Not considering NULL and leaf nodes
- Incorrect recursion return values

---

### Interview Tips

- Always dry run recursion
- Clearly define what recursive function returns
- Use diagrams for complex problems

---

### Summary

- Advanced tree problems rely on strong recursion
- Optimized solutions avoid repeated calculations
- Mastering these builds confidence for hard DSA problems