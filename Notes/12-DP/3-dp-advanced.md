# Dynamic Programming (Advanced)

## 1. DP on Strings

DP on strings usually involves comparing characters of two strings or working with substrings.

Common ideas:

- Comparing characters
- Building a DP table
- Using previous subproblem results

---

## 2. Longest Common Subsequence (LCS)

### Problem

Given two strings `s1` and `s2`, find the **length of the longest subsequence common to both strings**.

Example:

```text
s1 = "abcde"
s2 = "ace"
LCS = "ace"
Length = 3
```

### Recurrence Relation

If characters match:

```cpp
dp[i][j] = 1 + dp[i-1][j-1]
```

Else:

```cpp
dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```


### Time Complexity

- O(N × M)

---

### C++ Implementation

```cpp
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}
```
---

## 3. Longest Common Substring

Similar to LCS but characters must be continuous.

### Recurrence

If characters match:

```cpp
dp[i][j] = 1 + dp[i-1][j-1]
```

Else:

```cpp
dp[i][j] = 0
```
---

## 4. Edit Distance (Levenshtein Distance)

### Problem

Find the minimum operations required to convert one string to another.

Allowed operations:

- Insert
- Delete
- Replace

### Recurrence

```cpp
dp[i][j] = 1 + min(
    dp[i-1][j],    // delete
    dp[i][j-1],    // insert
    dp[i-1][j-1]   // replace
)
```
---

## 5. DP on Matrices

Matrix DP problems involve moving across a grid.

Typical movement:

- Right
- Down
- Diagonal

Common patterns involve finding minimum cost, number of paths, or maximum value.

---

## 6. Unique Paths Problem

Find number of ways to reach bottom-right corner.

Movement allowed:

- Right
- Down

### Recurrence

```cpp
dp[i][j] = dp[i-1][j] + dp[i][j-1]
```

### Time Complexity

- O(N × M)

---

## 7. Minimum Path Sum

Find path with minimum sum from top-left to bottom-right.

### Recurrence

```cpp
dp[i][j] = grid[i][j] + min(
    dp[i-1][j],
    dp[i][j-1]
)
```
---

## 8. Maximum Square Submatrix

Find the largest square containing only 1s.

### Recurrence

```cpp
dp[i][j] = 1 + min(
    dp[i-1][j],
    dp[i][j-1],
    dp[i-1][j-1]
)
```
---

## 9. Key Patterns in Advanced DP

DP problems generally follow these patterns:

| Pattern        | Example Problems        |
| -------------- | ----------------------- |
| String DP      | LCS, Edit Distance      |
| Subsequence DP | LIS                     |
| Matrix/Grid DP | Unique Paths            |
| Partition DP   | Palindrome Partitioning |

---

## 10. Tips for Solving Advanced DP

1. Clearly define the state
2. Identify the transition/recurrence
3. Decide base cases
4. Choose memoization or tabulation
5. Optimize space if possible

---

## Summary

Topics covered:

- DP on Strings
- Longest Common Subsequence
- Longest Common Substring
- Edit Distance
- Matrix DP
- Unique Path
- Minimum Path Sum
- Maximum Square Submatrix

These problems build strong intuition for handling complex DP transitions and multi-dimensional DP tables.