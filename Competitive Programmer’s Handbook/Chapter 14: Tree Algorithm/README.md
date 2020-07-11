# Tree Algorithm (N-ary Tree)
* [Dynamic Programming on Trees | Set-1 (Maximum Sum of the Node Values from Root to Any of the Leaves)](https://www.geeksforgeeks.org/dynamic-programming-trees-set-1/)
* [Dynamic Programming on Trees | Set 2 (Maximum Height of Tree for Each Node as a Root)](https://www.geeksforgeeks.org/dynamic-programming-trees-set-2/)
* [Dynamic Programming on Trees | Set-3 (Diameter of N-ary Tree)](https://www.geeksforgeeks.org/dp-on-trees-set-3-diameter-of-n-ary-tree/)
* [Diameter of a Tree Using Two DFS](https://www.geeksforgeeks.org/diameter-tree-using-dfs/)

## Corresponding Problems on LeetCode
* [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
* [310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/)

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
* First, to calculate for every node `x` the maximum length of a path from `x` that goes through a child of `x`.  
* Second, to calculate for every node `x` the maximum length of a path through its parent `p`.
  * `maxLength1(x)`: the maximum length of a path from `x`
  * `maxLength2(x)`: the maximum length of a path from `x` in another direction than the first path
* Finally, if the path that corresponds to `maxLength1(p)` goes through `x` , we conclude that the maximum length is `maxLength2(p) + 1`, and otherwise the maximum length is `maxLength1(p) + 1`.
