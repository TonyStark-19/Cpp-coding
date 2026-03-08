# Graphs (Intermediate)

## 1. What is a Cycle in a Graph?

A **cycle** occurs when a path starts from a node and eventually returns to the same node without repeating edges unnecessarily.

Example:

```text
A → B → C → A
```

Cycles are important to detect because many problems depend on whether a graph contains cycles or not.

Examples:

- Deadlock detection
- Topological sorting
- Dependency resolution
- Network analysis

---

## 2. Cycle Detection in Undirected Graph

Two common methods:

1. DFS
2. BFS (Using Parent Tracking)

---

## 3. Cycle Detection using DFS (Undirected Graph)

### Idea

While doing DFS:

- If you visit an already visited node
- And that node is **not the parent**
- Then a cycle exists.

### Steps

1. Maintain a visited array.
2. Traverse graph using DFS.
3. Pass parent node in recursion.
4. If visited neighbor ≠ parent → cycle detected.

### Time Complexity

- O(V + E)

### C++ Implementation

```cpp
bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;

    for (auto neigh : adj[node]) {
        if (!vis[neigh]) {
            if (dfs(neigh, node, adj, vis))
                return true;
        }
        else if (neigh != parent) {
            return true;
        }
    }

    return false;
}
```
---

## 4. Cycle Detection using BFS (Undirected Graph)

### Idea

Use queue and store:

```text
(node, parent)
```

If a visited neighbor is not the parent → cycle exists.

### C++ Implementation

```cpp
bool bfs(int start, vector<int> adj[], vector<int> &vis) {
    queue<pair<int,int>> q;
    q.push({start, -1});
    vis[start] = 1;

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto neigh : adj[node]) {
            if(!vis[neigh]) {
                vis[neigh] = 1;
                q.push({neigh, node});
            }
            else if(neigh != parent) {
                return true;
            }
        }
    }

    return false;
}
```
---

## 5. Cycle Detection in Directed Graph

For directed graphs, parent tracking does not work.

Instead we use:

- DFS
- Recursion stack

---

## 6. DFS + Recursion Stack Method

### Idea

Maintain two arrays:

- visited[]
- pathVisited[]

If during DFS:

- You encounter a node that is already in pathVisited
- Then a cycle exists

### Time Complexity

- O(V + E)

### C++ Implementation

```cpp
bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto neigh : adj[node]) {
        if(!vis[neigh]) {
            if(dfs(neigh, adj, vis, pathVis))
                return true;
        }
        else if(pathVis[neigh]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}
```
---

## 7. Kahn’s Algorithm (BFS) for Cycle Detection

Used in Directed Graphs

Steps:

1. Compute indegree of every node
2. Push nodes with indegree 0 into queue
3. Remove nodes and reduce indegree of neighbors
4. Count processed nodes

If processed nodes < total nodes → cycle exists.

### Time Complexity

- O(V + E)

---

## 8. Key Concepts to Remember

| Graph Type       | Method                |
| ---------------- | --------------------- |
| Undirected Graph | DFS with parent       |
| Undirected Graph | BFS with parent       |
| Directed Graph   | DFS + recursion stack |
| Directed Graph   | Kahn’s Algorithm      |

---

## 9. Common Interview Problems

Practice problems related to cycle detection:

- Detect Cycle in Undirected Graph
- Detect Cycle in Directed Graph
- Course Schedule
- Topological Sort
- Redundant Connection
- Graph Valid Tree

---

## 10. Key Takeaways

- Cycle detection is fundamental for many graph problems.
- Parent tracking works only for undirected graphs.
- Directed graphs require recursion stack or indegree approach.
- Understanding cycle detection helps in topological sorting and dependency graphs.