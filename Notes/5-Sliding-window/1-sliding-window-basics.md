# 📌 Sliding Window Technique (Basics) – C++ DSA

## 🔹 What is Sliding Window?

The **Sliding Window technique** is used to process a **range (window)** of elements in an array or string efficiently.

Instead of recalculating values for every window, we **reuse previous computations**, reducing time complexity.

---

## 🔹 When to Use Sliding Window?

Use sliding window when:

- Working with **subarrays or substrings**
- Window size is **fixed or variable**
- Need to find max/min/sum/length
- Brute-force solution is O(n²)

---

## 🔹 Types of Sliding Window

1. **Fixed Size Window**
2. **Variable Size Window** (covered in advanced)

---

## 🔹 Fixed Size Window

### Idea
- Maintain a window of size `k`
- Add next element
- Remove element going out of window

---

## 🔹 Window Sum Concept

### Brute Force Approach

```cpp
for(int i = 0; i <= n - k; i++) {
    int sum = 0;
    for(int j = i; j < i + k; j++) {
        sum += arr[j];
    }
}
```

⏱ Time → O(n × k)

---

## Sliding Window Approach

```cpp
int windowSum = 0;

// first window
for(int i = 0; i < k; i++)
    windowSum += arr[i];

int maxSum = windowSum;

// slide the window
for(int i = k; i < n; i++) {
    windowSum += arr[i];
    windowSum -= arr[i - k];
    maxSum = max(maxSum, windowSum);
}
```

- ⏱ Time → O(n)
- 📦 Space → O(1)

---

## 🔹 Maximum Sum Subarray of Size K

```cpp
int maxSumSubarray(int arr[], int n, int k) {
    int windowSum = 0;

    for(int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;

    for(int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
```
---

## 🔹 Count Subarrays of Size K

```cpp
int count = n - k + 1;
```
---

## 🔹 Sliding Window on Strings

### Example: Maximum Vowels in Substring of Length K

```cpp
int countVowels(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
```
---

## 🔹 Why Sliding Window Works?

Because:

- Adjacent windows overlap
- Only one element enters and one exits
- We update instead of recompute

---

## 🔹 Common Mistakes

- Forgetting to remove outgoing element
- Off-by-one errors
- Using sliding window on non-contiguous problems
- Confusing fixed and variable window logic

---

## 🔹 Fixed Window vs Variable Window

| Fixed Window     | Variable Window           |
| ---------------- | ------------------------- |
| Size is constant | Size changes              |
| Simpler          | Slightly complex          |
| Sum/avg problems | Longest/shortest problems |

---

## 🔹 Problems to Practice

- Maximum sum subarray of size K
- Average of subarrays of size K
- Maximum vowels in substring of size K
- First negative number in every window