# Big-O Notation

## 📌 Introduction

**Big-O Notation** is a mathematical way to describe the **time and space complexity** of an algorithm as the input size grows.

It helps us understand **how an algorithm scales**, not how fast it runs on a specific machine.

In simple terms:

> Big-O tells us **how an algorithm behaves for large inputs**.

---

## 🤔 Why Do We Need Big-O?

* Machines differ in speed
* Programming languages differ in performance
* Input size can grow very large

Big-O focuses on the **growth rate**, ignoring constants and minor details.

---

## 📈 How Big-O Works

Big-O expresses complexity using:

* Input size → `n`
* Upper bound of growth → worst-case scenario

We usually care about the **worst-case performance**, because it guarantees limits.

---

## 🔢 Common Big-O Notations

### 🟢 O(1) — Constant Time

* Execution time does not depend on input size
* Example: accessing an array element by index

---

### 🔵 O(n) — Linear Time

* Time grows directly with input size
* Example: looping through an array once

---

### 🟡 O(n²) — Quadratic Time

* Nested loops over the same input
* Example: comparing every pair of elements

---

### 🟠 O(log n) — Logarithmic Time

* Input size reduces at every step
* Example: Binary Search

---

### 🔴 O(n log n) — Linearithmic Time

* Combination of linear and logarithmic
* Example: Merge Sort, Quick Sort (average case)

---

### ⚫ O(2ⁿ) — Exponential Time

* Growth doubles with each input increase
* Example: recursive solutions without optimization

---

## 🚫 What Big-O Ignores

Big-O notation ignores:

* Constant factors (O(2n) → O(n))
* Lower-order terms (O(n² + n) → O(n²))
* Hardware and language differences

This keeps analysis simple and universal.

---

## ⚖️ Best, Average & Worst Case

* **Best Case**: Minimum time taken
* **Average Case**: Expected time
* **Worst Case**: Maximum time taken

Big-O usually represents the **worst case**.

---

## 🧠 Example Simplification

```
for (i = 0; i < n; i++) {
  for (j = 0; j < n; j++) {
    // constant operation
  }
}
```

* Inner loop runs `n` times
* Outer loop runs `n` times
* Total operations → `n * n`

👉 **Time Complexity: O(n²)**

---

## 🎯 Key Takeaways

* Big-O measures algorithm scalability
* Focuses on worst-case performance
* Ignores constants and small details
* Helps compare and choose efficient algorithms

---

> Big-O is not about writing faster code today, but about writing code that scales tomorrow.
=