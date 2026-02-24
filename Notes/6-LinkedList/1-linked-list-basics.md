# Linked List (Basics)

## What is a Linked List?

A **Linked List** is a linear data structure where elements (nodes) are not stored in contiguous memory locations.

Each node contains:

- **Data**
- **Pointer/Reference** to the next node

Unlike arrays, linked lists allow **dynamic memory allocation**.

---

## Types of Linked Lists

1. Singly Linked List
2. Doubly Linked List
3. Circular Linked List

👉 In this file, we focus on **Singly Linked List (SLL)**.

---

## Singly Linked List

In a singly linked list:

- Each node points to the **next node**
- The last node points to `NULL`

### Representation:

```css
[Data | Next] -> [Data | Next] -> [Data | NULL]
```

---

## Node Structure

Each node has two parts:

1. **Data** – stores the value
2. **Next** – pointer to the next node

### C++ Node Structure:

```cpp
struct Node {
    int data;
    Node* next;
};
```

## Head Pointer

- The head points to the first node of the linked list
- If `head == NULL`, the linked list is empty

---

## Basic Operations on Singly Linked List

### 1. Insertion

Insertion can be done at different positions:

**a) Insertion at Beginning**

Steps:

- Create a new node
- Set `newNode->next = head`
- Update `head = newNode`

```cpp
Node* newNode = new Node();
newNode->data = x;
newNode->next = head;
head = newNode;
```
---

**b) Insertion at End**

Steps:

- Create a new node
- Traverse till the last node
- Set `lastNode->next = newNode`

```cpp
Node* temp = head;
while(temp->next != NULL) {
    temp = temp->next;
}
temp->next = newNode;
newNode->next = NULL;
```
---

**c) Insertion at a Given Position**

Steps:

- Traverse till position-1
- Adjust pointers accordingly

---

### 2. Deletion

Deletion removes a node from the list.

**a) Deletion at Beginning**

Steps:

- Store head in temp
- Move head to head->next
- Delete temp

```cpp
Node* temp = head;
head = head->next;
delete temp;
```
---

**b) Deletion at End**

Steps:

- Traverse till second last node
- Set secondLast->next = NULL
- Delete last node

---

**c) Deletion of a Specific Node**

Steps:

- Find the node before the target node
- Change its next pointer
- Delete the target node

---

## Traversal of Linked List

Traversal means visiting each node once.

```cpp
Node* temp = head;
while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
}
```
---

## Time Complexity

| Operation              | Time Complexity |
| ---------------------- | --------------- |
| Insertion at Beginning | O(1)            |
| Insertion at End       | O(n)            |
| Deletion at Beginning  | O(1)            |
| Deletion at End        | O(n)            |
| Traversal              | O(n)            |

---

## Advantages of Linked List

- Dynamic size
- Efficient insertions and deletions
- No memory wastage due to fixed size

---

## Disadvantages of Linked List

- Extra memory for pointers
- No random access
- Slower traversal compared to arrays

---

## When to Use Linked List?

- When frequent insertions/deletions are required
- When size of data is unknown beforehand

---

## Summary

- Linked List is a dynamic linear data structure
- Singly Linked List uses one pointer per node
- Supports insertion, deletion, and traversal
- Useful where flexibility is needed over random access