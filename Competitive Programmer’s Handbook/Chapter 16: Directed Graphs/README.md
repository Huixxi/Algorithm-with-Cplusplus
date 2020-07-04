# Directed Graphs
* **Acyclic graphs**: There are no cycles in the graph, so there is no path from any node to itself.
* **Successor graphs**: The outdegree of each node is 1, so each node has a unique successor.

## [Topological Sorting](https://github.com/Huixxi/Algorithm-with-Cplusplus/tree/master/%E8%8E%B1%E7%89%B9%E6%89%A3%E7%9A%84-%E7%B3%BB%E5%88%97/15.Pattern:%20Topological%20Sort%20(Graph))
If there is a path from node `a` to node `b` , then node `a` appears before node `b` in the ordering.(一种依赖关系，或者在执行b之前必须先执行a) An acyclic graph always has a topological sort, and it is not possible to form a topological sort, so we can also use it to detect whether a greph contains a cycle.   

The idea is to go through the nodes of the graph and always begin a depth-first search at the current node if it has not been processed yet.(拓扑排序基于DFS)   

## Dynamic Programming(In an Acyclic Graph)
We can efficiently solve the following problems concerning paths from a starting node to an ending node:
* how many different paths are there?
* what is the shortest/longest path?
* what is the minimum/maximum number of edges in a path?
* which nodes certainly appear in any path?

## Successor Paths
Define a function `succ(x, k)` that gives the node we begin at node `x` and walk `k` steps forward. We can reduce the time complexity from `O(n)` to `O(logn)` with a `O(nlogn)` preprocess, because we should calculate `O(logn)` for each node. The idea is to precalculate all values of `succ(x, k)` where `k` is a power of two and at most `u` , where `u` is the maximum number of steps we will ever walk.    
For example, if we want to calculate the value of **`succ(x, 11)`**, we first form the representation `11 = 8 + 2 + 1`. Using that,   
**`succ(x, 11) = succ(succ(succ(x, 8), 2), 1)`**.   

## Cycle Detection
**Floyd’s algorithm(即快慢指针算法)**
