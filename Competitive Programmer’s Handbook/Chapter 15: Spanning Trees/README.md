# Spanning Trees
A spanning tree of a graph consists of all nodes of the graph and some of the edges of the graph so that there is a path between any two nodes. Like trees in general, spanning trees are connected and acyclic. The weight of a spanning tree is the sum of its edge weights. A **minimum spanning tree** is a spanning tree whose weight is as small as possible. In a similar way, a **maximum spanning tree** is a spanning tree whose weight is as large as possible.    

## Corresponding Problems on LeetCode
* [Min Cost to Connect All Nodes](https://leetcode.com/discuss/interview-question/356981/amazon-oa-2019-min-cost-to-connect-all-nodes)
* [Minimum cost to connect all cities](https://www.geeksforgeeks.org/minimum-cost-connect-cities/)

## Kruskal’s Algorithm(e.g. to create a minimum spanning tree)
* Sort the edges by their weights
* Go through those sorted edges and always adds an edge to the tree if it does not create a cycle
```
// pseudocode
sort(edges.begin(), edges.end()) by weights;
for(...) {
    if(!same(a,b))  // same函数，判断a，b是否在同一联通分量之中，使用union-find并查集来实现，将复杂度从O(n+m)将至O(logn)
        unite(a,b);  // 若不在，则union函数加边连接
}
```

## Union-Find Structure
```c++
for (int i = 1; i <= n; i++) link[i] = i;  // contains for each element the next element in the chain or the element itself if it is a representative,
for (int i = 1; i <= n; i++) size[i] = 1;  // for each representative the size of the corresponding set.

// O(logn)
int find(int x) {
    while(x != link[x]) 
        x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}
```

## Prim’s Algorithm
The algorithm first adds an arbitrary node to the tree. After this, the algorithm always chooses a minimum-weight edge that adds a new node to the tree.
Prim’s algorithm resembles Dijkstra’s algorithm. The difference is that Dijkstra’s algorithm always selects an edge whose distance from the starting node is minimum, but Prim’s algorithm simply selects the minimum weight edge that adds a new node to the tree, also can be efficiently implemented using a **priority queue**.

