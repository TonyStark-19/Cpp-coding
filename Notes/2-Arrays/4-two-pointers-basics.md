# 📌 Two Pointers Technique (Basics) – C++ DSA

## 🔹 What is the Two Pointers Technique?

The **Two Pointers technique** uses **two indices (pointers)** to iterate over a data structure, usually an array or string, in a smart way to reduce time complexity.

Instead of using nested loops, we move pointers based on conditions.

---

## 🔹 Why Use Two Pointers?

- Reduces time complexity
- Avoids unnecessary nested loops
- Makes code cleaner and more efficient
- Commonly used in interviews and contests

---

## 🔹 When to Use Two Pointers?

Use two pointers when:

- Array or string is **sorted**
- Need to find **pairs / subarrays**
- Working with **reversal problems**
- Need to compare elements from both ends
- Optimizing brute-force O(n²) solutions

---

## 🔹 Common Two Pointer Patterns

### 1️⃣ Opposite Direction Pointers
- One pointer starts at beginning
- Other starts at end

Used in:
- Reversing an array
- Palindrome check
- Pair sum in sorted array

```cpp
int left = 0, right = n - 1;

while(left < right) {
    // logic
    left++;
    right--;
}
```
---

### 2️⃣ Same Direction Pointers

- Both pointers start at the beginning
- Move at different speeds

Used in:

- Removing duplicates
- Sliding window foundation
- Partitioning arrays

```cpp
int i = 0, j = 0;

while(j < n) {
    // logic
    j++;
}
```
---

## 🔹 Reverse an Array (Two Pointers)

```cpp
int l = 0, r = n - 1;

while(l < r) {
    swap(arr[l], arr[r]);
    l++;
    r--;
}
```

- ⏱ Time Complexity → O(n)
- 📦 Space Complexity → O(1)

---

## 🔹 Check if String is Palindrome

```cpp
int l = 0, r = s.length() - 1;

while(l < r) {
    if(s[l] != s[r])
        return false;
    l++;
    r--;
}
return true;
```

## 🔹 Pair Sum in Sorted Array

### Problem

Check if there exists a pair with sum = target.

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
```
---

## 🔹 Remove Duplicates from Sorted Array

```cpp
int i = 0;

for(int j = 1; j < n; j++) {
    if(arr[j] != arr[i]) {
        i++;
        arr[i] = arr[j];
    }
}
```

New length = `i + 1`

---

## 🔹 Move All Zeros to End

```cpp
int i = 0;

for(int j = 0; j < n; j++) {
    if(arr[j] != 0) {
        swap(arr[i], arr[j]);
        i++;
    }
}
```
---

## 🔹 Common Mistakes

- Using two pointers on unsorted data (when sorting is required)
- Forgetting pointer movement (infinite loop)
- Mixing up indices
- Not handling edge cases (empty array, single element)

---

## 🔹 Two Pointers vs Sliding Window

- Two Pointers → flexible movement
- Sliding Window → fixed or dynamic window size
- Sliding Window is a special case of two pointers

---

## 🔹 Problems Where Two Pointers Shine

- Reverse array/string
- Palindrome check
- Two Sum (sorted array)
- Remove duplicates
- Move zeros
- Container With Most Water (advanced)