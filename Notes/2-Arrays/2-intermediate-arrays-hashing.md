# 📌 Intermediate Arrays & Hashing in C++ (DSA)

## 🔹 Why Hashing?

Hashing helps us **store and retrieve data efficiently**.  
Instead of repeatedly scanning an array (O(n)), hashing allows **O(1)** average-time lookups.

Used heavily in:

- Frequency counting
- Duplicate detection
- Anagram problems
- Subarray & prefix sum problems

---

## 🔹 Frequency Array

A **frequency array** stores how many times an element appears.

### Example

Given:

```cpp
arr = {1, 2, 2, 3, 3, 3}
```

```php
freq[1] = 1
freq[2] = 2
freq[3] = 3
```

### Implementation

```cpp
int freq[100000] = {0};

for(int i = 0; i < n; i++) {
    freq[arr[i]]++;
}
```

### Limitations

- Works only when values are small & non-negative
- Wastes memory for large ranges

---

## 🔹 Hashing Concept (Core Idea)

Hashing = mapping data to an index

```bash
key → hash function → index
```

This allows:

- Fast insertion
- Fast search
- Fast deletion

---

## 🔹 Using `map` in C++

### What is `map`?

- Stores data in sorted order
- Implemented using Red-Black Tree
- Keys are unique

### Syntax

```cpp
map<int, int> mp;
```

### Insertion

```cpp
mp[5]++;
mp[2] = 10;
```

### Traversal

```cpp
for(auto it : mp) {
    cout << it.first << " " << it.second << endl;
}
```

### Time Complexity

- Insert / Search / Delete → O(log n)

---

## 🔹 Using `unordered_map` in C++

### What is `unordered_map`?

- Stores data in random order
- Implemented using Hash Table
- Faster than `map` in most cases

### Syntax

```cpp
unordered_map<int, int> ump;
```

### Example

```cpp
for(int i = 0; i < n; i++) {
    ump[arr[i]]++;
}
```

### Time Complexity

- Average → O(1)
- Worst case → O(n) (rare)

---

## 🔹 `map` vs `unordered_map`

| Feature         | map            | unordered_map |
| --------------- | -------------- | ------------- |
| Ordering        | Sorted         | Unordered     |
| Implementation  | Red-Black Tree | Hash Table    |
| Time Complexity | O(log n)       | O(1) avg      |
| Memory          | Less           | More          |
| Use Case        | Sorted data    | Fast lookup   |

---

### Rule of Thumb

- Need sorted output → map
- Need speed → unordered_map

---

## 🔹 Counting Frequency using Hash Map

```cpp
unordered_map<int, int> freq;

for(int i = 0; i < n; i++) {
    freq[arr[i]]++;
}
```
---

## 🔹 Checking if Element Exists

```cpp
if(freq.find(x) != freq.end()) {
    cout << "Present";
}
```
---

## 🔹 Find Element with Maximum Frequency

```cpp
int maxFreq = 0, element;

for(auto it : freq) {
    if(it.second > maxFreq) {
        maxFreq = it.second;
        element = it.first;
    }
}
```
---

## 🔹 Hashing for Characters (Strings)

### Frequency of Characters

```cpp
string s;
cin >> s;

int freq[26] = {0};

for(char c : s) {
    freq[c - 'a']++;
}
```
---

## 🔹 Common Hashing Problems

- Count frequency of elements
- Find duplicates
- Check if two arrays are equal
- Check if two strings are anagrams
- First non-repeating element

---

## 🔹 Common Mistakes

- Using frequency array for large values
- Forgetting that unordered_map is unordered
- Assuming hashing is always O(1)
- Not handling negative values properly

---

## 🔹 When to Use What?

- Small range integers → Frequency Array
- Large or unknown range → Hash Map
- Ordered output → map
- Performance critical → unordered_map