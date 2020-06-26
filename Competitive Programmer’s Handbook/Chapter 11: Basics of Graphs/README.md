# Basic of Graphs

## Graph terminology
| **`node(节点)`** | **`edge(边)`** | **`path(路径)`** | **`cycle(环)`** | **`simple path(简单路径)`**  

| **`connected graph(连通图)`** | **`components(连通分量)`** | **`directed graph(有向图)`** | **`edg weights(边的权重)`** |   

| **`neighbors(邻居)`** | **`degrees(度，in-/out-)`** | **`regular graph(正则图，所有节点的度都相同)`** | **`complete graph(完全图)`** |   

| **`coloring(图的上色)`** | **`bipartite(二分图/偶图，不含奇圈)`** | **`simple graph(简单图，不含重边和子环)`** |   

## Graph representation
* Adjacency list representation: `vector<int> adj[N];` | `vector<pair<int,int>> adj[N];  // weighted graph`
* Adjacency matrix representation: `int adj[N][N];  // 0/1 or weights`
* Edge list representation: `vector<pair<int,int>> edges;` | `vector<tuple<int,int,int>> edges;  // weighted graph`
