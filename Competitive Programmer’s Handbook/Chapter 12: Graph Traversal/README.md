# Graph Traversal

##  Depth-First Search(DFS)
```c++
vector<int> adj[N];
bool visited[N];

void dfs(int s) {
    if(visited[s]) return;
    visited[s] = true;
    // process node s
    for(auto u : adj[s]) :
        dfs(u);
    }
}
```

## Breadth-First Search(BFS)
```c++
queue<int> q;
bool visited[N];
int distance[N];

visited[x] = true;
distance[x] = 0;
q.push(x);
while (!q.empty()) {
    int s = q.front(); q.pop();
    // process node s
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        distance[u] = distance[s] + 1;
        q.push(u);
    }
}
```

## Applications
* **Connectivity Check(使用DFS连通性检查以及查找连通分量)**
* **Finding Cycles(使用DFS找环)**
  * If during a graph traversal, we find a node whose neighbor has already been visited.
  * To simply calculate the number of nodes and edges in every component.
* **Bipartiteness Check(使用DFS二分图/偶图检测)**






