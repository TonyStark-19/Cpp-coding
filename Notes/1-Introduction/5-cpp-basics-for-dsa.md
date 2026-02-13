# C++ Basics for Data Structures & Algorithms

These notes cover essential **C++ concepts** required for **DSA**, focusing on speed, clarity, and **problem-solving** readiness.

---

## 1. Basic Program Structure

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // code
    return 0;
}
```

### Explanation:

- #include `<bits/stdc++.h>` includes most standard libraries (used in CP/DSA)
- using `namespace std;` avoids writing `std::` repeatedly
- `main()` is the program entry point

---

## 2. Input / Output (I/O)

### Basic I/O

```cpp
int x;
cin >> x;
cout << x << endl;
```

### Fast I/O (Recommended for DSA)

```cpp
ios::sync_with_stdio(false);
cin.tie(NULL);
```

### Together, they:

- Disable unnecessary safety checks
- Optimize I/O speed
- Are standard in competitive programming & DSA

✔ Improves performance for large input sizes

---

## 3. Data Types

| Data Type   | Size    | Use Case                      |
| ----------- | ------- | ----------------------------- |
| `int`       | 4 bytes | Small numbers                 |
| `long long` | 8 bytes | Large numbers (DSA preferred) |
| `float`     | 4 bytes | Decimal (low precision)       |
| `double`    | 8 bytes | Decimal (high precision)      |
| `char`      | 1 byte  | Characters                    |
| `bool`      | 1 byte  | true / false                  |

### Important:

Use `long long` when values may exceed `10^9`.

---

## 4. Operators

### Arithmetic

```cpp
+  -  *  /  %
```

### Relational

```cpp
==  !=  <  >  <=  >=
```

### Logical

```cpp
&&  ||  !
```

### Assignment

```cpp
=  +=  -=  *=  /=
```
---

## 5. Conditional Statements

### if-else

```cpp
if (x > 0) {
    cout << "Positive";
} else {
    cout << "Non-positive";
}
```

### switch

```cpp
switch (x) {
    case 1: cout << "One"; break;
    case 2: cout << "Two"; break;
    default: cout << "Other";
}
```
---

## 6. Loops

### for loop

```cpp
for (int i = 0; i < n; i++) {
    cout << i << " ";
}
```

### while loop

```cpp
while (n > 0) {
    n--;
}
```

### do-while

```cpp
do {
    cout << "Runs at least once";
} while (false);
```

✔ `for` loop is most commonly used in DSA.

---

## 7. Functions

### Function Definition

```cpp
int add(int a, int b) {
    return a + b;
}
```

### Function Call

```cpp
int sum = add(3, 4);
```
---

## 8. Pass by Value vs Pass by Reference

### Pass by Value

```cpp
void update(int x) {
    x = 10;
}
```

### Pass by Reference

```cpp
void update(int &x) {
    x = 10;
}
```

✔ Use pass by reference to avoid copying and improve performance.

---

## 9. Arrays (Basics)

### Declaration

```cpp
int arr[5];
```

### Initialization

```cpp
int arr[] = {1, 2, 3, 4, 5};
```

### Traversal

```cpp
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
```

✔ Arrays are zero-indexed.

---

## 10. Intro to STL (Very Basic)

### Vector

```cpp
vector<int> v;
v.push_back(10);
v.push_back(20);
```

### Traversal

```cpp
for (int x : v) {
    cout << x << " ";
}
```

### String

```cpp
string s = "DSA";
cout << s.length();
```
---

## 11. Common Mistakes to Avoid

- Forgetting `;`
- Using `int` instead of `long long`
- Not using fast I/O for large inputs
- Out-of-bounds array access