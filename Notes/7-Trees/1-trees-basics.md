# Day 15 – Trees (Basics)

## What is a Tree?

A **Tree** is a hierarchical, non-linear data structure consisting of nodes connected by edges.

- The topmost node is called the **Root**
- Each node can have **children**
- Nodes with no children are called **Leaf nodes**

---

## Basic Terminologies

- **Root**: Topmost node
- **Parent**: Node having children
- **Child**: Node derived from a parent
- **Leaf**: Node with no children
- **Edge**: Connection between nodes
- **Height**: Maximum depth of the tree
- **Depth**: Distance from root to a node
- **Subtree**: Tree formed from any node as root

---

## Binary Tree

A **Binary Tree** is a tree in which:

- Each node has **at most two children**
- Children are referred to as **Left Child** and **Right Child**

### Representation:

```code
    1
   / \
  2   3
 / \
4   5
```

---

## Types of Binary Trees

1. **Full Binary Tree**  
   Every node has either 0 or 2 children

2. **Complete Binary Tree**  
   All levels are completely filled except possibly the last

3. **Perfect Binary Tree**  
   All internal nodes have 2 children and all leaves are at the same level

4. **Skewed Binary Tree**  
   All nodes have only one child (left or right)

---

## Tree Node Structure (C++)

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

## Tree Traversals

Tree traversal means visiting all nodes of a tree exactly once.

There are two main categories:

- Depth First Traversal (DFS)
- Breadth First Traversal (BFS)

---

## Depth First Traversals (DFS)

### 1. Inorder Traversal (LNR)

Steps:

- Visit Left subtree
- Visit Root
- Visit Right subtree

```cpp
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
```
---

### 2. Preorder Traversal (NLR)

Steps:

- Visit Root
- Visit Left subtree
- Visit Right subtree

```cpp
void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
```
---

### 3. Postorder Traversal (LRN)

Steps:

- Visit Left subtree
- Visit Right subtree
- Visit Root

```cpp
void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
```
---

## Breadth First Traversal (Level Order)

- Traverses tree level by level
- Uses a Queue

```cpp
void levelOrder(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
```
---

## Time Complexity

| Traversal   | Time Complexity |
| ----------- | --------------- |
| Inorder     | O(n)            |
| Preorder    | O(n)            |
| Postorder   | O(n)            |
| Level Order | O(n)            |

---

## Space Complexity

- Recursive traversals: O(h) (height of tree)
- Level order traversal: O(n) in worst case

---

## Advantages of Trees

- Efficient hierarchical data representation
- Faster searching compared to linear structures
- Used in many real-world applications

---

## Applications of Trees

- File systems
- Databases
- Expression trees
- Hierarchical data representation

---

## Common Mistakes

- Confusing traversal orders
- Forgetting base condition in recursion
- Not handling NULL root

---

## Summary

- Trees are non-linear hierarchical data structures
- Binary Tree allows at most two children
- Traversals help access nodes in different orders
- Trees are fundamental for advanced DSA topics