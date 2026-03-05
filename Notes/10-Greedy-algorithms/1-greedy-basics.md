# Greedy Algorithms (Basics) – DSA Notes

## 1. What is a Greedy Algorithm?

A **Greedy Algorithm** is an approach where we make the **locally optimal choice at each step** with the hope that it leads to the **globally optimal solution**.

Instead of exploring all possibilities (like backtracking or DP), greedy algorithms **choose the best option available at the moment**.

### Key Idea

> Make the best choice now without worrying about future consequences.

---

## 2. When Does Greedy Work?

Greedy algorithms work when the problem satisfies two main properties:

### 1. Greedy Choice Property

A **global optimum** can be reached by choosing the **locally optimal choice**.

### 2. Optimal Substructure

The optimal solution of the problem **can be constructed from optimal solutions of its subproblems**.

---

## 3. General Greedy Strategy

Typical steps to solve a greedy problem:

1. Understand the problem objective
2. Identify the greedy choice (best local option)
3. Sort or structure data if needed
4. Pick the optimal choice step by step
5. Continue until the problem is solved

---

## 4. Common Greedy Problem Patterns

### 1. Sorting Based Greedy

Sort elements and choose based on a rule.

Examples:

- Activity Selection
- Meeting Rooms
- Minimum Platforms

---

### 2. Interval Scheduling

Select maximum number of non-overlapping intervals.

Example:

- Activity Selection Problem

Greedy Rule:

Choose the activity that **finishes earliest**.

---

### 3. Resource Allocation

Distribute resources efficiently.

Examples:

- Fractional Knapsack
- Assign cookies
- Job sequencing

---

### 4. Minimization / Maximization Problems

Greedy often works when we need to:

- minimize cost
- maximize profit
- maximize number of tasks

---

## 5. Example: Activity Selection Problem

### Problem

Given start and end times of activities, select the **maximum number of activities** that do not overlap.

### Greedy Strategy

1. Sort activities by **end time**
2. Pick the first activity
3. Select the next activity whose **start time ≥ last selected end time**

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int activitySelection(vector<Activity> &arr) {
    sort(arr.begin(), arr.end(), compare);

    int count = 1;
    int lastEnd = arr[0].end;

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i].start >= lastEnd) {
            count++;
            lastEnd = arr[i].end;
        }
    }

    return count;
}
```

Time Complexity: O(n log n) (due to sorting)

---

## 6. Example: Fractional Knapsack

### Problem

Given items with:

- weight
- value

Maximize total value in a knapsack with limited capacity.

### Greedy Strategy

Pick items with highest value/weight ratio first.

### Steps

1. Calculate value/weight ratio
2. Sort in descending order
3. Pick full item if possible
4. Otherwise take fractional part

---

## 7. Greedy vs Other Techniques

| Approach            | Idea                          | Example            |
| ------------------- | ----------------------------- | ------------------ |
| Greedy              | Best choice at each step      | Activity Selection |
| Dynamic Programming | Solve overlapping subproblems | Knapsack (0/1)     |
| Backtracking        | Try all possibilities         | N-Queens           |

---

## 8. Popular Greedy Problems in DSA

You should practice these:

- Activity Selection
- Fractional Knapsack
- Assign Cookies
- Jump Game
- Minimum Coins (specific cases)
- Gas Station
- Job Sequencing with Deadlines
- Huffman Coding

---

## 9. How to Identify a Greedy Problem

Ask these questions:

- Can I make a local optimal choice?
- Does the problem have optimal substructure?
- Will the greedy choice always lead to optimal solution?
- If yes → Greedy likely works.

---

## 10. Key Takeaways

- Greedy focuses on local optimal decisions
- Works only when problem properties allow it
- Usually involves sorting or priority selection
- Faster than DP/backtracking in many cases
- Not always guaranteed to work