# Graphs (Advanced)

## 1. What is Topological Sorting?

**Topological Sort** is a **linear ordering of vertices** in a **Directed Acyclic Graph (DAG)** such that:

For every directed edge  

```text
u → v  
```

vertex **u appears before v** in the ordering.

Important:

Topological sorting **only works for DAGs (Directed Acyclic Graphs).**

---

## 2. Real World Applications

Topological sorting is used in:

- Course prerequisite scheduling  
- Task scheduling systems  
- Build systems (compilers, dependency managers)  
- Job scheduling in operating systems  
- Dependency resolution in package managers

Example:

Course dependencies:
DSA → Graphs → Advanced Algorithms

Valid order:
DSA → Graphs → Advanced Algorithms

---

## 3. Methods to Perform Topological Sorting

Two common methods:

1. **DFS Based Approach**
2. **Kahn’s Algorithm (BFS + Indegree)**

---

## 4. DFS Based Topological Sort

### Idea

1. Perform DFS traversal.
2. After visiting all neighbors, push the node into a stack.
3. Reverse the stack order to get the topological order.

### Why it works

Nodes are added **after exploring their dependencies**, ensuring correct ordering.

---

### Time Complexity

- O(V + E)

---

### C++ Implementation

```cpp
void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;

    for(auto neigh : adj[node]) {
        if(!vis[neigh]) {
            dfs(neigh, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    stack<int> st;

    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> ans;

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
```
---

## . Kahn’s Algorithm (BFS Topological Sort)

Kahn’s Algorithm uses indegree.

### Indegree

Indegree of a node = number of incoming edges.

Steps

1. Calculate indegree of all vertices
2. Push nodes with indegree = 0 into queue
3. Remove node from queue
4. Reduce indegree of its neighbors
5. If indegree becomes 0 → push into queue
6. Continue until queue becomes empty

### Time Complexity

- O(V + E)

### C++ Implementation

```cpp
vector<int> topoSort(int V, vector<int> adj[]) {

    vector<int> indegree(V,0);

    for(int i=0;i<V;i++){
        for(auto neigh : adj[i]){
            indegree[neigh]++;
        }
    }

    queue<int> q;

    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        topo.push_back(node);

        for(auto neigh : adj[node]){
            indegree[neigh]--;

            if(indegree[neigh]==0){
                q.push(neigh);
            }
        }
    }

    return topo;
}
```
---

## 6. Detecting Cycle using Topological Sort

If Topological Sort does not include all vertices, a cycle exists.

In Kahn’s Algorithm:

If

processed nodes < total nodes

→ Cycle exists in graph

---

## 7. Important Related Problems

Common interview problems:

- Course Schedule
- Course Schedule II
- Alien Dictionary
- Find Eventual Safe States
- Parallel Courses
- Minimum Time to Complete Courses

---

## 8. Key Differences Between DFS & Kahn's Algorithm

| Method               | Approach           | Data Structure |
| -------------------- | ------------------ | -------------- |
| DFS Topological Sort | Depth First Search | Stack          |
| Kahn’s Algorithm     | BFS + Indegree     | Queue          |

---

## 9. Key Takeaways

- Topological sorting works only for Directed Acyclic Graphs (DAGs)
- Two major approaches: DFS + Stack and BFS (Kahn’s Algorithm)
- Widely used in dependency resolution and scheduling problems
- If topological order cannot include all nodes → graph contains cycle