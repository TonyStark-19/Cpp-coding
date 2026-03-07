# Graphs (Basics)

## 1. What is a Graph?

A **Graph** is a non-linear data structure used to represent relationships between objects.

A graph consists of:

- **Vertices (Nodes)** → represent entities
- **Edges** → represent connections between vertices

Example:
Social networks, road maps, recommendation systems.

---

## 2. Basic Terminology

| Term | Meaning |
|-----|--------|
| Vertex (Node) | An element of the graph |
| Edge | Connection between two vertices |
| Degree | Number of edges connected to a vertex |
| Path | Sequence of vertices connected by edges |
| Cycle | Path where the first and last vertices are the same |
| Connected Graph | Every vertex can be reached from any other vertex |

---

## 3. Types of Graphs

### 1. Undirected Graph

Edges have **no direction**.

Example:
A — B

---

### 2. Directed Graph (Digraph)

Edges have **direction**.

Example:
A → B

---

### 3. Weighted Graph

Edges have **weights/costs**.

Example:
A --5--> B

---

### 4. Unweighted Graph

Edges do not have weights.

---

## 4. Graph Representation

Graphs are usually represented in two ways.

---

### 1. Adjacency Matrix

A **2D matrix** used to represent edges.

Example:

Graph:

```text
0 --- 1
| |
2 --- 3
```

Matrix:

```text
0 1 2 3
```

```text
0 [ 0 1 1 0 ]
1 [ 1 0 0 1 ]
2 [ 1 0 0 1 ]
3 [ 0 1 1 0 ]
```

### Space Complexity
O(V²)

---

### 2. Adjacency List

Stores neighbors of each vertex.

Example:

```text
0 → 1,2
1 → 0,3
2 → 0,3
3 → 1,2
```
---

### Implementation (C++)

```cpp
vector<int> adj[V];

adj[0].push_back(1);
adj[1].push_back(0);
```

### Space Complexity

O(V + E)

More efficient for sparse graphs.

---

## 5. Graph Traversal

Traversal means visiting all vertices of the graph.

Two main methods:

- Breadth First Search (BFS)
- Depth First Search (DFS)

---

## 6. Breadth First Search (BFS)

BFS explores nodes level by level.

Uses:

- Queue
- Visited array

### Algorithm Steps

1. Start from source node
2. Mark it visited
3. Push into queue
4. Visit neighbors
5. Continue until queue is empty

---

### BFS Implementation (C++)

```cpp
void bfs(int start, vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

### Time Complexity

O(V + E)

---

## 7. Depth First Search (DFS)

DFS explores nodes as deep as possible before backtracking.

Uses:

- Recursion
- Stack (internally)

---

### DFS Implementation (C++)

```cpp
void dfs(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
```

### Time Complexity

O(V + E)

---

## 8. BFS vs DFS

| Feature         | BFS                        | DFS              |
| --------------- | -------------------------- | ---------------- |
| Data Structure  | Queue                      | Stack/Recursion  |
| Traversal Style | Level by level             | Deep exploration |
| Shortest Path   | Works in unweighted graphs | Not guaranteed   |

---

## 9. Applications of Graph Traversal

- Social network analysis
- Web crawling
- Shortest path problems
- Network connectivity
- Cycle detection
- Path finding

---

## 10. Common Interview Problems

- Number of Islands
- Flood Fill
- Connected Components
- Shortest Path in Unweighted Graph
- Detect cycle in graph

---

## 11. Summary

Key concepts covered:

- Graph definition and terminology
- Graph types
- Graph representations
- BFS traversal
- DFS traversal

Graphs are one of the most important topics in DSA, forming the base for advanced algorithms like Dijkstra, Topological Sort, and Minimum Spanning Trees.