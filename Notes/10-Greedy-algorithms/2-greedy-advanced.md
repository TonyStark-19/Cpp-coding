# Greedy Algorithms (Advanced)

## Overvie
Advanced greedy problems often involve **intervals, scheduling, and optimization decisions** where choosing the locally optimal option leads to a globally optimal solution.

These problems commonly appear in coding interviews and competitive programming.

---

## 1. Interval-Based Greedy Problems

Interval problems involve selecting or processing intervals based on **start and end times**.

Typical approach:

1. Sort intervals based on **end time** (most common)
2. Greedily pick intervals that do not overlap

---

## Example: Activity Selection Problem

### Problem

Given activities with start and end times, select the **maximum number of non-overlapping activities**.

### Greedy Strategy

Always choose the activity that **finishes earliest**.

### Steps

1. Sort activities by **end time**
2. Select first activity
3. For each next activity:

   - If its start time ≥ last selected end time → select it

### Time Complexity

O(n log n) due to sorting

---

## 2. Interval Scheduling

Goal: **Maximize number of non-overlapping intervals**

### Algorithm

1. Sort intervals by **end time**
2. Select the first interval
3. Skip overlapping intervals
4. Continue selecting next valid interval

---

## 3. Minimum Number of Platforms (Greedy + Sorting)

### Problem

Given arrival and departure times of trains, find the **minimum platforms needed**.

### Approach

1. Sort arrival and departure arrays
2. Use two pointers
3. Track platform count

### Time Complexity

O(n log n)

---

## 4. Interval Merging

Sometimes intervals overlap and must be merged.

### Example

Input:
[1,3], [2,6], [8,10]

Output:
[1,6], [8,10]

### Approach

1. Sort by start time
2. Merge overlapping intervals

---

## 5. Job Scheduling with Deadlines

Each job has:

- deadline
- profit

### Goal:

**Maximize total profit while completing jobs before deadlines**

### Greedy Strategy

1. Sort jobs by **profit (descending)**
2. Assign each job to the **latest possible free slot before deadline**

---

## 6. Greedy with Sorting Patterns

Common sorting strategies in greedy:

| Problem Type | Sorting Strategy |
|--------------|------------------|
| Activity selection | Sort by end time |
| Job scheduling | Sort by profit |
| Interval merging | Sort by start time |
| Train platforms | Sort arrival & departure |

---

## 7. Key Greedy Concepts

### Greedy Choice Property

A **locally optimal choice** leads to a **globally optimal solution**.

### Optimal Substructure

Optimal solution can be built from **optimal solutions of subproblems**.

---

## 8. Common Interview Problems

- Activity Selection
- Merge Intervals
- Insert Interval
- Minimum Platforms
- Non-overlapping Intervals
- Job Scheduling with Deadlines
- Partition Labels

---

## 9. When to Use Greedy


Greedy works when:
- Problem has **greedy choice property**
- Problem has **optimal substructure**
- Decisions can be made **step by step**

---

## 10. Greedy vs Dynamic Programming

| Greedy | Dynamic Programming |
|------|------|
| Makes local optimal choice | Explores multiple possibilities |
| Faster | Often slower |
| Works only in specific problems | Works in broader cases |

Example:

- Fractional Knapsack → Greedy
- 0/1 Knapsack → DP

---

## Summary

Key advanced greedy topics:

- Interval scheduling
- Activity selection
- Job scheduling with deadlines
- Interval merging
- Platform problems
- Sorting-based greedy strategies

Greedy algorithms are powerful when the problem allows **local optimal decisions that build the global optimum**.