# Heaps (Basics)

## What is a Heap?

A **Heap** is a special **complete binary tree** that follows the **heap property**.

- Used when we need **quick access to min or max element**
- Commonly implemented using arrays

---

## Types of Heaps

### 1. Min Heap
- Parent node value ≤ children values
- Root contains the **minimum element**

### 2. Max Heap
- Parent node value ≥ children values
- Root contains the **maximum element**

---

## Complete Binary Tree

A binary tree where:

- All levels are completely filled except possibly the last
- Nodes are filled from **left to right**

---

## Array Representation of Heap

For index `i` (0-based indexing):

- Parent: `(i - 1) / 2`
- Left child: `2*i + 1`
- Right child: `2*i + 2`

---

## Heap Operations

### Insertion in Heap

Steps:

1. Insert element at the end
2. Heapify up (bubble up)

```cpp
void heapifyUp(int i) {
    while(i > 0 && arr[(i-1)/2] > arr[i]) {
        swap(arr[i], arr[(i-1)/2]);
        i = (i-1)/2;
    }
}
```
---

## Deletion from Heap

(Deleting root element)

Steps:

1. Replace root with last element
2. Remove last element
3. Heapify down

```cpp
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;
    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyDown(smallest);
    }
}
```
---

## Heapify

Heapify converts a binary tree into a heap.

- Time Complexity: O(n)
- Used in building heaps efficiently

---

## Priority Queue

A Priority Queue is an abstract data type where:

- Each element has a priority
- Higher priority elements are served first

> Heaps are commonly used to implement priority queues.

---

## Priority Queue in C++

### Min Heap (Default)

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

### Max Heap

```cpp
priority_queue<int> pq;
```
---

## Common Applications

- Scheduling algorithms
- Top K problems
- Median in a stream
- Dijkstra’s algorithm
- Task prioritization

---

## Time Complexity Summary

| Operation     | Time     |
| ------------- | -------- |
| Insert        | O(log n) |
| Delete        | O(log n) |
| Get Min / Max | O(1)     |
| Build Heap    | O(n)     |

---

## Advantages

- Fast access to min/max
- Efficient priority handling
- Better than sorting for dynamic data

---

## Limitations

- No fast search for arbitrary elements
- Not suitable when full ordering is required

---

## Common Mistakes

- Forgetting heap property after insertion/deletion
- Confusing min heap and max heap
- Incorrect index calculations

---

## Summary

- Heap is a complete binary tree
- Min heap and max heap differ by ordering
- Priority queue is a major use-case of heaps
- Fundamental for many DSA problems