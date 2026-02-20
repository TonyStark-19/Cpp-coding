# 📌 Binary Search (Basics) – C++ DSA

## 🔹 What is Binary Search?

**Binary Search** is an efficient searching algorithm used to find an element in a **sorted array** by repeatedly dividing the search space into half.

Instead of checking elements one by one, it **eliminates half of the array at every step**.

---

## 🔹 Prerequisite

- The array **must be sorted**
- Works best on arrays (random access)

---

## 🔹 Binary Search Logic

1. Define `low` and `high`
2. Find `mid`
3. Compare `arr[mid]` with target
4. Reduce search space accordingly

> mid = low + (high - low) / 2  (Prevents integer overflow)

---

## 🔹 Iterative Binary Search

```cpp
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
```
---

## 🔹 Recursive Binary Search

```cpp
int binarySearch(int arr[], int low, int high, int target) {
    if(low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if(arr[mid] == target)
        return mid;
    else if(arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);
    else
        return binarySearch(arr, low, mid - 1, target);
}
```
---

## 🔹 Search Space Reduction

At each step:

- If target > mid → search right half
- If target < mid → search left half

Search space becomes:

> n → n/2 → n/4 → n/8 ...

---

## 🔹 Time & Space Complexity

| Type      | Time     | Space    |
| --------- | -------- | -------- |
| Iterative | O(log n) | O(1)     |
| Recursive | O(log n) | O(log n) |

---

## 🔹 Binary Search on Different Data Types

### On Arrays

> ✔ Directly applicable

### On Strings

> ✔ Works if sorted lexicographically

### On Answer Space (Concept Intro)

> Binary search can also be applied on ranges, not just arrays.

Example:

- Finding minimum possible answer
- Optimization problems

(This will be covered in advanced binary search)

---

## 🔹 Common Binary Search Variations

- First occurrence
- Last occurrence
- Count of an element
- Lower bound
- Upper bound

---

## 🔹 Common Mistakes

- Forgetting to sort the array
- Infinite loop due to wrong mid update
- Overflow while calculating mid
- Using < instead of <= in loop condition

---

## 🔹 When to Use Binary Search?

- Sorted data
- Monotonic search space
- Need fast search
- Optimization problems