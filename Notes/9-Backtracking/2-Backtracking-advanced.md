# Backtracking (Advanced)

## Overview

Advanced backtracking focuses on:

- Decision tree modeling
- Pruning techniques
- Constraint optimization
- Reducing exponential search space

These concepts are very common in interviews.

---

## Decision Tree Concept

Every backtracking problem can be visualized as a **decision tree**:

- Root → Initial state
- Branches → Possible choices
- Leaf nodes → Valid solutions or dead ends

Example:
Subsets of {1,2}

            []
           /  \
        [1]    []
        / \     / \
    [1,2] [1] [2]  []

Each level = one decision  
Each branch = include/exclude choice  

Understanding this tree helps optimize the solution.

---

## Pruning in Backtracking

Pruning means:

> Stop exploring a branch early if it cannot lead to a valid solution.

This reduces unnecessary recursion calls.

Without pruning → O(2^n) or O(n!)  
With pruning → Much faster in practice

---

## Types of Pruning

### 1. Constraint-based Pruning

Stop recursion if constraints are violated.

Example:

- N-Queens: Stop if two queens attack each other
- Sudoku: Stop if number placement invalid

---

### 2. Bound-based Pruning

Stop exploring when:

- Current solution already worse than best solution found

Used in:

- Optimization problems
- Branch and Bound

---

## Example: N-Queens Problem

Place N queens such that no two queens attack each other.

Key Constraints:

- No same column
- No same diagonal

```cpp
bool isSafe(int row, int col, vector<string>& board, int n) {
    for(int i = 0; i < row; i++)
        if(board[i][col] == 'Q') return false;

    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
        if(board[i][j] == 'Q') return false;

    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
        if(board[i][j] == 'Q') return false;

    return true;
}
```
---

## Branch and Bound

Extension of backtracking.

Key Idea:

- Maintain best solution so far
- Use bounds to cut unpromising branches

Used in:

- Job assignment
- Traveling Salesman (basic version)

---

## Combination Sum (Pruning Example)

```cpp
void solve(vector<int>& nums, int target, int index, vector<int>& current) {
    if(target == 0) {
        // store solution
        return;
    }

    for(int i = index; i < nums.size(); i++) {
        if(nums[i] > target) break;   // Pruning

        current.push_back(nums[i]);
        solve(nums, target - nums[i], i, current);
        current.pop_back();   // Backtrack
    }
}
```
---

## Handling Duplicates

To avoid duplicate solutions:

- Sort input first
- Skip repeated elements

```cpp
if(i > index && nums[i] == nums[i-1])
    continue;
```

### Time Complexity

Worst case:

- O(2^n)
- O(n!)

Depends on branching factor and depth.

Pruning reduces practical runtime significantly.

---

## Space Complexity

- O(n) recursion stack
- Additional space for storing solutions

---

## Advanced Patterns in Backtracking

- Subset problems
- Permutation problems
- Partition problems
- Constraint satisfaction problems
- Grid-based search (maze, word search)

---

## Common Mistakes

- Not pruning early
- Forgetting to undo state changes
- Not sorting when duplicates exist
- Wrong base condition
- Modifying shared data incorrectly

---

## Interview Tips

- Always draw the decision tree
- Explain pruning clearly
- Clarify constraints before coding
- Optimize after writing brute-force

---

## Summary

- Backtracking explores decision trees
- Pruning is key for optimization
- Constraint checking improves efficiency
- Many hard problems rely on strong backtracking logic