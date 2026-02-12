# Big-O Notation – Practice Problems & Solutions

This file contains **15 carefully selected problems** to practice **time complexity analysis**, along with **clear explanations**. These cover constant, linear, logarithmic, quadratic, and exponential patterns.

---

## Problems 1–10 (Reviewed)

### 1️⃣ Linear Loop

```cpp
for (int i = 0; i < n; i++) {
    cout << i;
}
```

**Time Complexity:** `O(n)`
**Explanation:** Loop runs `n` times, constant work inside.

---

### 2️⃣ Constant Time Access

```cpp
int x = arr[0];
```

**Time Complexity:** `O(1)`
**Explanation:** Direct access, no dependency on input size.

---

### 3️⃣ Linear with Step Size

```cpp
for (int i = 0; i < n; i += 2) {
    cout << i;
}
```

**Time Complexity:** `O(n)`
**Explanation:** Runs `n/2` times → constants ignored.

---

### 4️⃣ Nested Loops (Square)

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << i << j;
    }
}
```

**Time Complexity:** `O(n²)`
**Explanation:** `n × n` operations.

---

### 5️⃣ Nested Loop (Triangle – Upper)

```cpp
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        cout << i << j;
    }
}
```

**Time Complexity:** `O(n²)`
**Explanation:** Total operations ≈ `n(n+1)/2`.

---

### 6️⃣ Nested Loop (Triangle – Lower)

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        cout << i << j;
    }
}
```

**Time Complexity:** `O(n²)`
**Explanation:** Summation `0 + 1 + ... + (n-1)`.

---

### 7️⃣ Sequential Loops

```cpp
for (int i = 0; i < n; i++) cout << i;
for (int j = 0; j < n; j++) cout << j;
```

**Time Complexity:** `O(n)`
**Explanation:** `O(n) + O(n)` → `O(n)`.

---

### 8️⃣ Mixed Growth

```cpp
for (int i = 0; i < n; i++) cout << i;
for (int j = 0; j < n*n; j++) cout << j;
```

**Time Complexity:** `O(n²)`
**Explanation:** Dominant term wins.

---

### 9️⃣ Logarithmic While Loop

```cpp
int i = n;
while (i > 1) {
    i = i / 2;
}
```

**Time Complexity:** `O(log n)`
**Explanation:** Value halves every iteration.

---

### 🔟 Logarithmic For Loop

```cpp
for (int i = 1; i < n; i = i * 2) {
    cout << i;
}
```

**Time Complexity:** `O(log n)`
**Explanation:** Value doubles each step.

---

## Problems 11–15 (New)

### 1️⃣1️⃣ Linear + Logarithmic

```cpp
for (int i = 0; i < n; i++) {
    int j = 1;
    while (j < n) {
        j = j * 2;
    }
}
```

**Time Complexity:** `O(n log n)`
**Explanation:** Outer loop `n`, inner loop `log n`.

---

### 1️⃣2️⃣ Triple Nested Loop

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            cout << i << j << k;
        }
    }
}
```

**Time Complexity:** `O(n³)`
**Explanation:** `n × n × n` operations.

---

### 1️⃣3️⃣ Binary Search Pattern

```cpp
int low = 0, high = n - 1;
while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == x) break;
    else if (arr[mid] < x) low = mid + 1;
    else high = mid - 1;
}
```

**Time Complexity:** `O(log n)`
**Explanation:** Search space halves every iteration.

---

### 1️⃣4️⃣ Exponential Recursion

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

**Time Complexity:** `O(2^n)`
**Explanation:** Each call branches into two calls.

---

### 1️⃣5️⃣ Divide & Conquer Recursion

```cpp
void func(int n) {
    if (n <= 1) return;
    func(n/2);
    func(n/2);
}
```

**Time Complexity:** `O(n)`
**Explanation:** Two calls on half input → total work is linear.

---

## 🔑 Key Takeaways

* `+ / -` → **Linear**
* `* / /` → **Logarithmic**
* Nested loops → **Multiply complexities**
* Sequential blocks → **Take dominant term**
* Drop constants in Big-O

---

📌 **Tip:** Always count *how fast input size is reducing or increasing*.