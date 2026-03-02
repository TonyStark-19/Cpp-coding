# Heaps (Advanced)

## Overview

Advanced heap concepts focus on **optimization techniques** and **problem-solving patterns** where heaps reduce time complexity significantly.

Heaps are especially useful when:

- Only partial ordering is needed
- Top K or extreme elements are required
- Data is dynamic or streamed

---

## Heap-Based Optimization Patterns

### 1. Top K Elements

Instead of sorting (O(n log n)):

- Use a **Min Heap of size K**
- Time Complexity: **O(n log k)**

### Steps:

1. Insert first K elements
2. For remaining elements:

   - If element > heap top → replace

---

## Kth Largest / Smallest Element

- Kth Largest → Min Heap of size K
- Kth Smallest → Max Heap of size K

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```
---

## Merge K Sorted Arrays / Lists

- Push first element of each array into heap
- Repeatedly extract min and insert next element

### Time Complexity:

- O(n log k)

---

## Heap Sort

A comparison-based sorting algorithm using heaps.

### Steps:

- Build Max Heap
- Swap root with last element
- Heapify remaining elements

### Complexity:

- Time: O(n log n)
- Space: O(1) (in-place)

---

## Median in a Data Stream

Uses two heaps:

- Max Heap (left half)
- Min Heap (right half)

### Logic:

- Balance sizes
- Median depends on heap sizes

---

## Sliding Window Maximum

Uses heap with index tracking.

- Push (value, index)
- Remove out-of-window elements

### Complexity:

- O(n log n)

(Deque solution exists but heap approach is common in interviews)

---

## Replace Elements with Rank

- Use heap to maintain ordering
- Useful in compression problems

---

## Heap + Greedy Combination

Many greedy problems rely on heaps:

- Task scheduling
- Job sequencing
- CPU scheduling
- Minimum cost problems

---

## Custom Comparator in Heap

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
```

Used when ordering is not purely numerical.

---

## Time Complexity Summary

| Problem        | Time                |
| -------------- | ------------------- |
| Top K          | O(n log k)          |
| Merge K Arrays | O(n log k)          |
| Median Stream  | O(log n) per insert |
| Heap Sort      | O(n log n)          |

---

## Common Mistakes

- Using sorting instead of heap
- Choosing wrong heap type (min vs max)
- Forgetting to limit heap size
- Ignoring index tracking in window problems

---

### Interview Tips

- Ask if full sorting is required
- Think “Top / K / Extreme” → Heap
- Optimize space by limiting heap size

---

### Summary

- Advanced heap problems focus on optimization
- Heaps reduce time complexity significantly
- Key patterns: Top K, streaming data, merging