# Time Complexity vs Space Complexity

## 📌 Introduction

When analyzing an algorithm, we mainly focus on **how fast it runs** and **how much memory it consumes**. These two aspects are measured using **Time Complexity** and **Space Complexity**.

Understanding both helps us write **efficient, scalable, and optimized code**.

---

## ⏱️ What is Time Complexity?

**Time Complexity** describes how the **execution time of an algorithm grows** as the input size increases.

In simple terms:

> Time Complexity tells us **how much time an algorithm takes to run**.

### 🔑 Why Time Complexity Matters

* Helps compare different algorithms
* Predicts performance on large inputs
* Prevents slow and inefficient solutions

### 🧠 Example

If an algorithm checks every element in a list of size `n`, the time taken grows as `n` grows.

---

## 💾 What is Space Complexity?

**Space Complexity** describes how much **extra memory an algorithm uses** during execution relative to input size.

In simple terms:

> Space Complexity tells us **how much memory an algorithm needs**.

This includes:

* Variables
* Data structures
* Recursive call stack

### 🔑 Why Space Complexity Matters

* Prevents memory overflow
* Important for memory-constrained systems
* Helps build efficient applications

---

## 🔍 Key Differences: Time vs Space Complexity

| Aspect       | Time Complexity    | Space Complexity        |
| ------------ | ------------------ | ----------------------- |
| Measures     | Execution time     | Memory usage            |
| Focus        | Speed of algorithm | Memory efficiency       |
| Concern      | Slow programs      | High memory consumption |
| Optimization | Faster execution   | Lower memory usage      |

---

## ⚖️ Time–Space Tradeoff

Often, improving **time complexity** requires using **more space**, and reducing space may increase execution time.

### Example

* Using a hash map speeds up search (better time)
* But uses extra memory (more space)

This balance is called the **Time–Space Tradeoff**.

---

## 🎯 Which One is More Important?

There is no single answer — it depends on the problem:

* Large data → prioritize **time complexity**
* Limited memory → prioritize **space complexity**
* Competitive programming → mostly **time**
* Embedded systems → mostly **space**

---

## 🚀 Key Takeaways

* **Time Complexity** = How fast an algorithm runs
* **Space Complexity** = How much memory it uses
* Both are equally important
* Always aim for a **balanced and optimized solution**

---

> A good algorithm is not just fast, but also memory efficient.