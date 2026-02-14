# 📌 Arrays in C++ (DSA Basics)

## 🔹 What is an Array?
An **array** is a data structure that stores **multiple values of the same data type** in **contiguous memory locations**.

### ✅ Key Characteristics

- Fixed size
- Zero-based indexing
- Fast access using index
- Same data type elements

---

## 🔹 1D Array Declaration & Initialization

### Declaration

```cpp
int arr[5];
```

### Initialization

```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

### Partial Initialization

```cpp
int arr[5] = {1, 2};  // remaining elements are 0
```

### Size Inference

```cpp
int arr[] = {10, 20, 30};
```
---

## 🔹 Accessing Array Elements

```cpp
cout << arr[0];  // first element
cout << arr[4];  // last element
```

⚠️ Accessing invalid index leads to undefined behavior.

---

## 🔹 Array Traversal Techniques

### 1️⃣ Using `for` Loop

```cpp
for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
```
---

### 2️⃣ Using `while` Loop

```cpp
int i = 0;
while(i < n) {
    cout << arr[i] << " ";
    i++;
}
```
---

### 3️⃣ Using Range-Based Loop

```cpp
for(int x : arr) {
    cout << x << " ";
}
```
---

## 🔹 Taking Input in an Array

```cpp
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}
```
---

## 🔹 Finding Minimum & Maximum Element

### 🔸 Minimum Element

```cpp
int minVal = arr[0];
for(int i = 1; i < n; i++) {
    if(arr[i] < minVal)
        minVal = arr[i];
}
```
---

### 🔸 Maximum Element

```cpp
int maxVal = arr[0];
for(int i = 1; i < n; i++) {
    if(arr[i] > maxVal)
        maxVal = arr[i];
}
```
---

## 🔹 Sum of Array Elements

```cpp
int sum = 0;
for(int i = 0; i < n; i++) {
    sum += arr[i];
}
```
---

## 🔹 Average of Array Elements

```cpp
float avg = (float)sum / n;
```
---

## 🔹 Reverse an Array

### 🔸 Using Two Pointers

```cpp
int start = 0, end = n - 1;
while(start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
}
```
---

## 🔹 Check if Array is Sorted

```cpp
bool isSorted = true;
for(int i = 1; i < n; i++) {
    if(arr[i] < arr[i - 1]) {
        isSorted = false;
        break;
    }
}
```
---

## 🔹 Linear Search

```cpp
int key;
cin >> key;
bool found = false;

for(int i = 0; i < n; i++) {
    if(arr[i] == key) {
        found = true;
        break;
    }
}
```
---

## 🔹 Count Even & Odd Elements

```cpp
int even = 0, odd = 0;
for(int i = 0; i < n; i++) {
    if(arr[i] % 2 == 0)
        even++;
    else
        odd++;
}
```
---

## 🔹 Important Notes

- Array size cannot be changed once declared
- Arrays are passed to functions by reference
- Time complexity for traversal → O(n)

---

## 🔹 Common Beginner Mistakes

- Accessing out-of-bound indices
- Forgetting to initialize variables
- Assuming dynamic size for arrays