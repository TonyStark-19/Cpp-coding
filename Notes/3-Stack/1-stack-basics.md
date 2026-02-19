# 📌 Stack Data Structure – C++ DSA

## 🔹 What is a Stack?

A **Stack** is a linear data structure that follows the principle of:

> **LIFO – Last In, First Out**

The element inserted last will be removed first.

Example:
If we push: 10 → 20 → 30  
Then pop → 30 comes out first.

---

## 🔹 Real-Life Analogy

- Stack of plates
- Browser back button
- Undo/Redo operations
- Call stack in recursion

---

## 🔹 Basic Operations on Stack

1. **push(x)** → Insert element
2. **pop()** → Remove top element
3. **top() / peek()** → View top element
4. **empty()** → Check if stack is empty
5. **size()** → Number of elements

All major operations work in:

⏱ **O(1) Time Complexity**

---

## 🔹 Stack Implementation in C++

### Using STL Stack

```cpp
#include <stack>
using namespace std;

stack<int> st;

st.push(10);
st.push(20);
st.pop();

cout << st.top();
```
---

## 🔹 Stack Using Array (Manual Implementation)

```cpp
int stack[100];
int top = -1;

void push(int x) {
    if(top == 99) {
        cout << "Stack Overflow";
        return;
    }
    stack[++top] = x;
}

void pop() {
    if(top == -1) {
        cout << "Stack Underflow";
        return;
    }
    top--;
}

int peek() {
    return stack[top];
}
```
---

## 🔹 Stack Using Linked List

### Node Structure

```cpp
struct Node {
    int data;
    Node* next;
};
```

### Push Operation

```cpp
void push(Node*& top, int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}
```

### Pop Operation

```cpp
void pop(Node*& top) {
    if(top == NULL)
        return;

    Node* temp = top;
    top = top->next;
    delete temp;
}
```
---

## 🔹 Stack Overflow & Underflow

- **Overflow**→ Pushing into full stack
- **Underflow** → Popping from empty stack

Always check before push/pop.

---

## 🔹 Applications of Stack in DSA

- Reversing data
- Balanced Parentheses
- Infix → Postfix conversion
- Evaluate Postfix Expression
- Next Greater Element
- Monotonic Stack problems
- Recursion (call stack)

---

## 🔹 Balanced Parentheses Problem

```cpp
bool isBalanced(string s) {
    stack<char> st;

    for(char c : s) {
        if(c == '(')
            st.push(c);
        else {
            if(st.empty())
                return false;
            st.pop();
        }
    }
    return st.empty();
}
```
---

## 🔹 Reverse a String Using Stack

```cpp
stack<char> st;

for(char c : s)
    st.push(c);

while(!st.empty()) {
    cout << st.top();
    st.pop();
}
```
---

## 🔹 Time & Space Complexity

| Operation | Time |
| --------- | ---- |
| push      | O(1) |
| pop       | O(1) |
| peek      | O(1) |

> Space → O(n)

---

## 🔹 Common Mistakes

- Forgetting to check empty before pop
- Stack overflow in recursion
- Using stack where queue is needed
- Not understanding LIFO behavior clearly

---

## 🔹 Stack vs Queue

| Stack               | Queue                           |
| ------------------- | ------------------------------- |
| LIFO                | FIFO                            |
| push/pop at one end | insert at rear, delete at front |