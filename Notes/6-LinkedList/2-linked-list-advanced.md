# Linked List (Advanced)

## Overview

Advanced Linked List concepts focus on **pointer manipulation** and **efficient traversal techniques** that help solve complex DSA problems with optimal time and space complexity.

---

## Pointer Manipulation in Linked List

Pointer manipulation is the core skill required to work with linked lists effectively.

### Key Pointer Concepts

- Always store the next node before changing links
- Update pointers in correct order to avoid losing nodes
- Use temporary pointers for safe traversal

### Example: Reversing a Linked List

```cpp
Node* prev = NULL;
Node* curr = head;
Node* next = NULL;

while(curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
head = prev;
```
---

## Slow and Fast Pointer Technique

Also known as the Tortoise and Hare Algorithm.

### Concept

- Slow pointer moves one step at a time
- Fast pointer moves two steps at a time

This technique helps solve many linked list problems efficiently.

---

## Applications of Slow & Fast Pointers

### 1. Finding the Middle of a Linked List

```cpp
Node* slow = head;
Node* fast = head;

while(fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
}
// slow points to middle
```
---

### 2. Detecting a Cycle in Linked List

If slow and fast pointers meet, a cycle exists.

```cpp
Node* slow = head;
Node* fast = head;

while(fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) {
        // Cycle detected
        break;
    }
}
```
---

### 3. Finding the Starting Point of a Cycle

Steps:

- Detect cycle using slow & fast pointers
- Move one pointer to head
- Move both pointers one step at a time
- Meeting point is cycle start

---

## Reversing Linked List (Iterative & Recursive)

### Iterative Approach

- Time: O(n)
- Space: O(1)

### Recursive Approach

```cpp
Node* reverse(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
```
---

## Removing N-th Node from End

Uses slow & fast pointers.

Steps:

- Move fast pointer `n` steps ahead
- Move both pointers until fast reaches end
- Delete the target node

---

## Merging Two Sorted Linked Lists

- Compare nodes from both lists
- Attach smaller node first
- Continue until both lists are merged

---

## Checking Palindrome in Linked List

Steps:

- Find middle using slow & fast pointers
- Reverse second half
- Compare both halves

---

## Time & Space Complexity Summary

| Problem             | Time | Space |
| ------------------- | ---- | ----- |
| Reverse Linked List | O(n) | O(1)  |
| Find Middle         | O(n) | O(1)  |
| Detect Cycle        | O(n) | O(1)  |
| Remove Nth Node     | O(n) | O(1)  |

---

## Common Mistakes

Losing reference to head
Incorrect pointer updates
Not handling edge cases (empty or single node list)

---

## Interview Tips

- Draw linked list on paper
- Dry run pointer changes
- Handle edge cases first

---

## Summary

- Pointer manipulation is the backbone of linked lists
- Slow & fast pointer technique solves many problems efficiently
- Mastering these concepts boosts DSA confidence