# Day 20 – Backtracking (Basics)

## What is Backtracking?

Backtracking is an algorithmic technique used to solve problems recursively by:

1. Making a choice  
2. Exploring further with that choice  
3. Undoing the choice if it leads to a dead end  

It is often described as:

> Try → Explore → Undo

---

## Recursion vs Backtracking

### Recursion
- A function calls itself
- Breaks problem into smaller subproblems
- Does not necessarily undo decisions

Example:
- Factorial
- Fibonacci
- Tree traversals

---

### Backtracking
- Uses recursion
- Explores all possible solutions
- Explicitly **reverts changes (undo step)**

Used when:
- Multiple solutions exist
- We must explore combinations/permutations
- We need constraint-based exploration

---

## Structure of Backtracking

```cpp
void solve(parameters) {
    if(base_condition) {
        store_solution;
        return;
    }

    for(each_choice) {
        make_choice;
        solve(updated_parameters);
        undo_choice;   // Backtrack
    }
}
```
---

## When to Use Backtracking?

- Generating permutations
- Generating combinations
- Subset problems
- N-Queens
- Sudoku solver
- Maze problems

---

## Example 1: Generate All Subsets

```cpp
void subsets(vector<int>& nums, int index, vector<int>& current) {
    if(index == nums.size()) {
        // store current subset
        return;
    }

    // Include element
    current.push_back(nums[index]);
    subsets(nums, index + 1, current);

    // Exclude element (Backtrack)
    current.pop_back();
    subsets(nums, index + 1, current);
}
```
---

## Example 2: Generate All Permutations

```cpp
void permute(vector<int>& nums, int index) {
    if(index == nums.size()) {
        // store permutation
        return;
    }

    for(int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        permute(nums, index + 1);
        swap(nums[i], nums[index]);  // Backtrack
    }
}
```
---

## Decision Tree Concept

Backtracking problems can be visualized as:

- Root → initial state
- Branches → choices
- Leaf → solution or dead end

If a branch fails → return to parent and try another branch.

---

## Time Complexity

Backtracking is usually:

- Exponential: O(2^n), O(n!), etc.
- Depends on number of choices per level

---

## Space Complexity

- O(n) recursion stack
- Additional space for storing solutions

---

## Common Backtracking Patterns

1. Choose → Explore → Unchoose
2. Constraint checking before recursion
3. Early pruning to reduce search space

---

## Pruning (Optimization)

Instead of exploring all possibilities:

- Stop early if constraints are violated

Example:

- In N-Queens, stop if queen attacks another queen

---

## Common Mistakes

- Forgetting to undo changes
- Incorrect base condition
- Not handling duplicates
- Modifying shared data without restoring it

---

## Summary

- Backtracking is recursion + undo mechanism
- Used for exploring all possible solutions
- Very common in combinatorial problems
- Requires careful handling of state changes