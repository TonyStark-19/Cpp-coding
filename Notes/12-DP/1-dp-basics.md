# Dynamic Programming (Basics)

## 1. What is Dynamic Programming?

Dynamic Programming is a technique used to solve problems by **breaking them into smaller subproblems**, solving each subproblem once, and **storing their results** for reuse.

This helps avoid redundant calculations.

DP is mainly used for **optimization problems** where we need to find the best possible solution.

---

## 2. Recursion vs Dynamic Programming

### Recursion
Recursion solves problems by calling the same function repeatedly with smaller inputs.

Example:

Factorial

```cpp
factorial(n) = n * factorial(n-1)
```

Problem:

Recursive solutions often repeat the same calculations many times.

---

### Dynamic Programming

DP improves recursion by **saving already computed results**.

Two main techniques:

1. **Memoization (Top-Down)**
2. **Tabulation (Bottom-Up)**

---

## 3. Key Properties of DP

For a problem to be solved using DP, it must have:

### 1. Overlapping Subproblems
The same subproblems appear multiple times.

Example:

Fibonacci

```text
fib(5)
├─ fib(4)
│ ├─ fib(3)
│ └─ fib(2)
└─ fib(3)
```

Here **fib(3)** is computed multiple times.

DP stores the value so it doesn't need to be recalculated.

---

### 2. Optimal Substructure

A problem has optimal substructure if **optimal solution can be constructed from optimal solutions of subproblems**.

Example:
Shortest path problems.

---

## 4. Memoization (Top-Down DP)

Memoization stores the results of recursive calls.

### Steps

1. Solve using recursion
2. Store results in a DP array
3. Reuse stored values

### Example: Fibonacci using Memoization

```cpp
int fib(int n, vector<int> &dp) {
    if(n <= 1) return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}
```

### Time Complexity

- O(n)

---

## 5. Tabulation (Bottom-Up DP)

Tabulation builds the solution iteratively from smaller values.

### Example: Fibonacci using Tabulation

```cpp
int fib(int n) {
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
```

### Time Complexity

- O(n)

---

## 6. Memoization vs Tabulation

| Feature        | Memoization               | Tabulation         |
| -------------- | ------------------------- | ------------------ |
| Approach       | Top-Down                  | Bottom-Up          |
| Uses recursion | Yes                       | No                 |
| Stack usage    | Uses recursion stack      | No recursion stack |
| Performance    | Slightly slower sometimes | Often faster       |

---

## 7. Steps to Solve a DP Problem

1. Identify if problem has overlapping subproblems
2. Check for optimal substructure
3. Write recursive solution
4. Add memoization
5. Convert to tabulation if needed

---

## 8. Common Beginner DP Problems

- Fibonacci
- Climbing Stairs
- Frog Jump
- Coin Change
- House Robber
- Minimum Path Sum

---

## 9. Why Dynamic Programming is Important

DP helps solve complex problems efficiently.

Many famous algorithms use DP such as:

- Knapsack Problem
- Longest Common Subsequence
- Longest Increasing Subsequence
- Matrix Chain Multiplication

---

## Summary

Key concepts covered:

- Recursion vs Dynamic Programming
- Overlapping Subproblems
- Optimal Substructure
- Memoization (Top-Down)
- Tabulation (Bottom-Up)

Dynamic Programming is all about avoiding repeated work by storing computed results.