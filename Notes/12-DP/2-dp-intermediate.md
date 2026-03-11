# Dynamic Programming (Intermediate)


## 1. What is the Knapsack Problem?

The **Knapsack Problem** is a classic optimization problem.

You are given:

- `n` items
- Each item has a **weight**
- Each item has a **value**
- A bag (knapsack) with limited **capacity**

Goal:

**Maximize total value without exceeding the weight capacity.**

---

## 2. Types of Knapsack Problems

### 1. 0/1 Knapsack

Each item can be taken **only once**.

Choice:

- Take the item
- Skip the item

### 2. Unbounded Knapsack

Items can be taken **multiple times**.

Example:
Coin Change, Rod Cutting

---

# 3. 0/1 Knapsack Recurrence

If:

`weight[i] <= capacity`

Then we have two choices:

```cpp
max(
value[i] + dp[i-1][capacity - weight[i]],
dp[i-1][capacity]
)
```

Otherwise:

```cpp
dp[i-1][capacity]
```
---

## 4. 0/1 Knapsack Implementation (Tabulation)

```cpp
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){

            if(wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}
```

Time Complexity: **O(N × W)**

---

## 5. Space Optimized Knapsack

We can optimize space by using 1D DP array.

```cpp
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W+1,0);

    for(int i=0;i<n;i++){
        for(int w=W; w>=wt[i]; w--){
            dp[w] = max(dp[w], val[i] + dp[w-wt[i]]);
        }
    }

    return dp[W];
}
```
---

## 6. Unbounded Knapsack

Difference from 0/1 knapsack:

Items can be reused multiple times.

Loop direction changes.

```cpp
for(int i=0;i<n;i++){
    for(int w=wt[i]; w<=W; w++){
        dp[w] = max(dp[w], val[i] + dp[w-wt[i]]);
    }
}
```
---

## 7. Important Knapsack Pattern Problems

Many interview questions follow the Knapsack pattern:

- Subset Sum:
Check if subset exists with given sum.

-  Partition:
Divide array into two equal sum subsets.

- Count Subsets with Given Sum
- Minimum Subset Sum Difference
- Target Sum Problem
- Coin Change
- Rod Cutting

---

## 8. Recognizing Knapsack Pattern

A problem likely follows the knapsack pattern if:

- Items have weight/value
- We must choose or skip items
- Constraint like capacity or sum
- Goal is max/min/possible combinations

---

## 9. 0/1 Knapsack vs Unbounded Knapsack

| Feature        | 0/1 Knapsack     | Unbounded Knapsack |
| -------------- | ---------------- | ------------------ |
| Item selection | Once             | Multiple times     |
| Loop direction | Reverse          | Forward            |
| Example        | Classic knapsack | Coin change        |

---

## Summary

Concepts covered:

- 0/1 Knapsack
- Unbounded Knapsack
- Knapsack recurrence relation
- Tabulation approach
- Space optimization
- Related DP patterns (subset sum, coin change, partition problems)

Knapsack is one of the most important Dynamic Programming patterns in DSA.