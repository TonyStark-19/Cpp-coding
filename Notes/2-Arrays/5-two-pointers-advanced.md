# 📌 Two Pointers Technique (Advanced) – C++ DSA

## 🔹 Why Advanced Two Pointers?

At an advanced level, two pointers help solve problems in **O(n)** time that would otherwise require **O(n²)** brute force.

They are especially powerful when the array is **sorted** or when we need to maintain certain conditions while moving pointers.

---

## 🔹 Two Pointers on Sorted Arrays

### Key Idea

When the array is sorted:

- If the current sum is **too small**, move the **left pointer forward**
- If the current sum is **too large**, move the **right pointer backward**

This works because sorting gives us order and predictability.

---

## 🔹 Two Sum in Sorted Array

### Problem

Find if there exists a pair such that:

```cpp
arr[i] + arr[j] = target
```


### Solution (Two Pointers)
```cpp
int l = 0, r = n - 1;

while(l < r) {
    int sum = arr[l] + arr[r];

    if(sum == target)
        return true;
    else if(sum < target)
        l++;
    else
        r--;
}
return false;
```

- ⏱ Time → O(n)
- 📦 Space → O(1)

---

## 🔹 Triplet Sum (Sorted Array)

### Idea

- Fix one element
- Apply two pointers on the remaining array

```cpp
sort(arr, arr + n);

for(int i = 0; i < n; i++) {
    int l = i + 1, r = n - 1;

    while(l < r) {
        int sum = arr[i] + arr[l] + arr[r];

        if(sum == target)
            return true;
        else if(sum < target)
            l++;
        else
            r--;
    }
}
```

- ⏱ Time → O(n²)

---

## 🔹 Count Pairs with Given Sum (Sorted Array)

```cpp
int l = 0, r = n - 1, count = 0;

while(l < r) {
    int sum = arr[l] + arr[r];

    if(sum == target) {
        count++;
        l++;
        r--;
    }
    else if(sum < target)
        l++;
    else
        r--;
}
```
---

## 🔹 Closest Pair to Target

```cpp
int l = 0, r = n - 1;
int closest = INT_MAX;

while(l < r) {
    int sum = arr[l] + arr[r];
    closest = min(closest, abs(target - sum));

    if(sum < target)
        l++;
    else
        r--;
}
```

## 🔹 Remove Duplicates (Advanced Handling)

### Skip Duplicate Values

```cpp
while(l < r && arr[l] == arr[l + 1])
    l++;

while(l < r && arr[r] == arr[r - 1])
    r--;
```

Used in:

- Two Sum (unique pairs)
- 3Sum problems

---

## 🔹 Partition Array (Two Pointers)

### Move Negatives to One Side

```cpp
int l = 0, r = n - 1;

while(l < r) {
    if(arr[l] < 0)
        l++;
    else if(arr[r] >= 0)
        r--;
    else
        swap(arr[l], arr[r]);
}
```
---

## 🔹 Dutch National Flag Algorithm

### Sort 0s, 1s, and 2s

```cpp
int low = 0, mid = 0, high = n - 1;

while(mid <= high) {
    if(arr[mid] == 0) {
        swap(arr[low++], arr[mid++]);
    }
    else if(arr[mid] == 1) {
        mid++;
    }
    else {
        swap(arr[mid], arr[high--]);
    }
}
```

- ⏱ Time → O(n)
- 📦 Space → O(1)

---

## 🔹 Two Pointers vs Hashing (Advanced)

| Two Pointers       | Hashing             |
| ------------------ | ------------------- |
| O(1) space         | O(n) space          |
| Needs sorted array | Works on unsorted   |
| Faster in practice | Easier to implement |

> 📌 Prefer two pointers after sorting if space matters.

---

## 🔹 Common Pitfalls

- Forgetting to sort the array
- Not skipping duplicates
- Infinite loops due to pointer misuse
- Using hashing when two pointers suffice

---

## 🔹 Problems to Practice

- Two Sum (sorted)
- 3Sum
- 4Sum
- Container With Most Water
- Dutch National Flag