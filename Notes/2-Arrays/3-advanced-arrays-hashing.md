# 📌 Advanced Arrays & Hashing (Prefix Sum & Subarrays) – C++ DSA

## 🔹 Why Prefix Sum?

Prefix Sum is a technique used to **precompute cumulative sums** so that we can answer **range-based queries** efficiently.

Instead of recalculating sums repeatedly (O(n)), prefix sums reduce it to **O(1)** per query.

---

## 🔹 Prefix Sum Array

### Definition

A prefix sum array stores the sum of elements from index `0` to `i`.

```cpp
prefix[i] = arr[0] + arr[1] + ... + arr[i]
```
---

## 🔹 Building Prefix Sum Array

```cpp
vector<int> prefix(n);
prefix[0] = arr[0];

for(int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + arr[i];
}
```

## 🔹 Range Sum Query using Prefix Sum

To find sum of elements from index `l` to `r`:

```cpp
int rangeSum;
if(l == 0)
    rangeSum = prefix[r];
else
    rangeSum = prefix[r] - prefix[l - 1];
```

### ⏱ Time Complexity

- Preprocessing → O(n)
- Each query → O(1)

---

## 🔹 Subarray Concept

A subarray is a contiguous part of an array.

Example

```cpp
Array: [1, 2, 3]
Subarrays:
[1], [2], [3]
[1, 2], [2, 3]
[1, 2, 3]
```

Total Number of Subarrays

```cpp
n * (n + 1) / 2
```
---

## 🔹 Generate All Subarrays (Brute Force)

```cpp
for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
        for(int k = i; k <= j; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}
```

⏱ Time Complexity → O(n³)

---

## 🔹 Subarray Sum (Brute Force)

```cpp
for(int i = 0; i < n; i++) {
    int sum = 0;
    for(int j = i; j < n; j++) {
        sum += arr[j];
        cout << sum << endl;
    }
}
```

⏱ Time Complexity → O(n²)

---

## 🔹 Subarray Sum using Prefix Sum

```cpp
for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
        int sum = (i == 0) ? prefix[j] : prefix[j] - prefix[i - 1];
        cout << sum << endl;
    }
}
```

⏱ Time Complexity → O(n²) (better than brute force)

---

## 🔹 Count Subarrays with Given Sum (Hashing)

### Idea

If:

```cpp
prefix[j] - prefix[i] = k
```

Then:

```cpp
prefix[i] = prefix[j] - k
```
---

### Efficient Approach

```cpp
unordered_map<int, int> mp;
mp[0] = 1;

int prefixSum = 0, count = 0;

for(int i = 0; i < n; i++) {
    prefixSum += arr[i];

    if(mp.find(prefixSum - k) != mp.end()) {
        count += mp[prefixSum - k];
    }

    mp[prefixSum]++;
}
```

- ⏱ Time Complexity → O(n)
- 📦 Space Complexity → O(n)

---

## 🔹 Longest Subarray with Sum = K

```cpp
unordered_map<int, int> mp;
int prefixSum = 0, maxLen = 0;

for(int i = 0; i < n; i++) {
    prefixSum += arr[i];

    if(prefixSum == k)
        maxLen = i + 1;

    if(mp.find(prefixSum) == mp.end())
        mp[prefixSum] = i;

    if(mp.find(prefixSum - k) != mp.end())
        maxLen = max(maxLen, i - mp[prefixSum - k]);
}
```
---

## 🔹 Prefix Sum for Frequency (0/1 Array)

Used in:

- Count subarrays with equal 0s and 1s
- Binary array problems

```cpp
if(arr[i] == 0)
    arr[i] = -1;
```

Then apply prefix sum + hashing.

---

## 🔹 Common Mistakes ❌

- Forgetting to initialize `mp[0] = 1`
- Using brute force when prefix sum is applicable
- Confusing subarray with subsequence
- Overflow issues (use `long long` if needed)

---

## 🔹 Where This is Used

- Subarray sum problems
- Range queries
- Competitive programming
- Interview questions