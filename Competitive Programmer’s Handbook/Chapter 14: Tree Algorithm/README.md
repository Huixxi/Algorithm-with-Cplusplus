# Tree Algorithm (N-ary Tree)

## Tree traversal
```c++
// dfs at an arbitrary node
void dfs(int s, int e) {
    // process node s
    for (auto u : adj[s]) {
        if(u != e) dfs(u, s);
    }
}
// In the first call e = 0, because there is no previous node, and it is allowed to proceed to any direction in the tree.
dfs(x, 0);
```
Calculate for each node `s` a value `count[s]`: the number of nodes in its subtree.   
```c++
// Dynamic Programming
void dfs(int s, int e) {
    count[s] = 1;
    for(auto u : adj[s]) {
        if(u == e) continue;
        dfs(u, s);
        count[s] += count[u];
    }
}
```

## Diameter
The diameter of a tree is the maximum length of a path between two nodes.  
* Dynamic Programming: An important observation is that every path in a rooted tree has a highest point: the highest node that belongs to the path.
* Two DFS: First, we choose an arbitrary node `a` in the tree and find the farthest node `b` from `a` . Then, we find the farthest node `c` from `b` . The diameter
of the tree is the distance between `b` and `c` .

## All Longest Paths
To calculate for every node in the tree the maximum length of a path that begins at the node.
