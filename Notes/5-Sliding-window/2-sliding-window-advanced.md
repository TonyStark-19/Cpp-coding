# 🧠 Sliding Window (Advanced) – DSA Notes (C++)

## 📌 What is Advanced Sliding Window?

Advanced sliding window problems usually involve a **variable-size window**, where the window expands and shrinks dynamically based on a condition instead of having a fixed length.

This technique is widely used to optimize problems involving subarrays or substrings.

---

## 🔑 When to Use Variable Size Sliding Window

Use it when:

- You need the longest / smallest subarray or substring
- A condition must be satisfied (sum, count, frequency, uniqueness, etc.)
- The array/string is continuous
- Brute force gives O(n²) complexity

---

## 🪟 Variable Size Window Concept

Basic Idea:

- Use two pointers: left and right
- Expand the window by moving right
- When condition breaks, shrink the window by moving left
- Track the answer during valid windows

---

## 🔁 General Template (C++)

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // include arr[right] in window

    while (condition_not_valid) {
        // remove arr[left] from window
        left++;
    }

    // update answer if window is valid
}
```
---

## 📊 Common Problems Using Variable Sliding Window

- Longest subarray with sum ≤ K
- Longest substring without repeating characters
- Smallest subarray with sum ≥ K
- Count of subarrays satisfying a condition
- Longest substring with at most K distinct characters

---

## 🧮 Example: Smallest Subarray with Sum ≥ K

```cpp
int minLen = INT_MAX;
int sum = 0, left = 0;

for (int right = 0; right < n; right++) {
    sum += arr[right];

    while (sum >= k) {
        minLen = min(minLen, right - left + 1);
        sum -= arr[left];
        left++;
    }
}
```
---

## ⏱️ Time & Space Complexity

- Time Complexity: O(n)
(each element enters and leaves the window once)
- Space Complexity: O(1) or O(k) depending on problem

---

## ⚠️ Common Mistakes

- Forgetting to shrink the window
- Updating the answer at the wrong time
- Mixing fixed-size and variable-size logic
- Not clearly defining the condition

---

## ✅ Key Takeaways

- Sliding window is about maintaining a valid range
- Variable size window = dynamic expand + shrink
- Focus more on logic than memorizing code
- One of the most important techniques for arrays & strings