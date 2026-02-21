# 📌 Binary Search (Advanced) – C++ DSA

## 🔹 What is Advanced Binary Search?

Advanced Binary Search goes beyond finding an element in a sorted array.  
It focuses on **variants**, **edge cases**, and **searching on answer space**.

These patterns are very common in interviews.

---

## 🔹 Binary Search Variants

### 1️⃣ First Occurrence of an Element

```cpp
int firstOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1, ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            ans = mid;
            high = mid - 1;   // move left
        }
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}
```
---

### 2️⃣ Last Occurrence of an Element

```cpp
int lastOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1, ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            ans = mid;
            low = mid + 1;   // move right
        }
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}
```
---

### 3️⃣ Count Occurrences of an Element

```cpp
int countOccurrences(int arr[], int n, int target) {
    int first = firstOccurrence(arr, n, target);
    if(first == -1)
        return 0;

    int last = lastOccurrence(arr, n, target);
    return last - first + 1;
}
```
---

## 🔹 Lower Bound

### Definition

First index where element is ≥ target

```cpp
int lowerBound(int arr[], int n, int target) {
    int low = 0, high = n - 1, ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```
---

## 🔹 Upper Bound

### Definition

First index where element is > target

```cpp
int upperBound(int arr[], int n, int target) {
    int low = 0, high = n - 1, ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```
---

## 🔹 Binary Search on Answer Space

### Core Idea

> Binary search can be applied on range of answers, not just arrays.

Conditions:

- Search space is monotonic
- Answer lies within a range

---

## Example: Find Square Root (Floor)

```cpp
int sqrtBinarySearch(int x) {
    int low = 0, high = x, ans = 0;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
```
---

## 🔹 Minimum Element in Rotated Sorted Array

```cpp
int findMin(int arr[], int n) {
    int low = 0, high = n - 1;

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[low];
}
```
---

## 🔹 Search in Rotated Sorted Array

```cpp
int search(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
            return mid;

        if(arr[low] <= arr[mid]) {
            if(target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if(target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
```
---

## 🔹 Common Mistakes

- Wrong mid calculation
- Infinite loops
- Incorrect boundary updates
- Not identifying monotonic behavior
- Overflow in calculations

---

## 🔹 When to Think Binary Search?

Ask yourself:

- Is the data sorted?
- Is the answer monotonic?
- Can I reduce the search space?

If yes → Binary Search applies