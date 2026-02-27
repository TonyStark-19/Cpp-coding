# Trees (Intermediate)

## Overview

Intermediate tree concepts focus on solving problems using **recursion**, **depth calculations**, and **optimized traversal techniques**.

These concepts are frequently asked in DSA interviews.

---

## Height of a Tree

The **height of a tree** is the number of edges on the longest path from the root to a leaf node.

- Height of empty tree = -1
- Height of single node tree = 0

### Recursive Approach

```cpp
int height(Node* root) {
    if(root == NULL) return -1;
    return 1 + max(height(root->left), height(root->right));
}
```

### Time Complexity

O(n) – every node is visited once

---

## Depth of a Tree

- **Depth of a node**: distance from root to that node
- **Maximum depth** = height + 1 (when counted in nodes)

---

## Diameter of a Tree

The diameter of a tree is the length of the longest path between any two nodes in the tree.

The path may or may not pass through the root.

---

## Diameter (Naive Approach)

- Compute height for every node
- Time Complexity: O(n²)

---

## Diameter (Optimized Approach)

Uses a single traversal.

```cpp
int diameter(Node* root, int &dia) {
    if(root == NULL) return 0;

    int lh = diameter(root->left, dia);
    int rh = diameter(root->right, dia);

    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}
```

### Time Complexity

- O(n)

---

## Balanced Binary Tree

A tree is height balanced if:

```code
|height(left) - height(right)| ≤ 1
```

for every node.

---

## Check if Tree is Balanced

```cpp
int check(Node* root) {
    if(root == NULL) return 0;

    int lh = check(root->left);
    if(lh == -1) return -1;

    int rh = check(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}
```
---

## Lowest Common Ancestor (LCA) – Basic Idea

The Lowest Common Ancestor of two nodes is the deepest node that has both nodes as descendants.

### Conditions:

- If root is NULL → return NULL
- If root matches either node → return root

---

## Count Total Nodes

```cpp
int countNodes(Node* root) {
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```
---

## Count Leaf Nodes

```cpp
int countLeaf(Node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}
```
---

## Common Interview Problems

- Height of tree
- Diameter of tree
- Balanced binary tree
- Count nodes / leaf nodes
- Maximum depth

---

## Common Mistakes

- Confusing height with depth
- Using O(n²) approach when optimized solution exists
- Not handling NULL cases properly

---

### Summary

- Height and diameter are core tree metrics
- Optimized recursion improves performance
- These concepts are foundations for advanced tree problems