# Flows and Cuts
* Finding a **maximum flow**(最大流): What is the maximum amount of flow we can send from a node to another node?
* Finding a **minimum cut**(最小割): What is a minimum-weight set of edges that separates two nodes(the source node and the sink node) of the graph?

(It turns out that a maximum flow and a minimum cut are always **equally large**)

## Ford–Fulkerson Algorithm
[Ford-Fulkerson Algorithm for Maximum Flow Problem](https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/)   
The algorithm uses a special representation of the graph where each original edge has a reverse edge in another direction. The weight of each edge indicates how much more flow we could route through it. At the beginning of the algorithm, the weight of each original edge equals the capacity of the edge and the weight of
each reverse edge is zero. The algorithm increases the flow as long as there is a path from the source to the sink through positive-weight edges.   

**Finding Paths**   
The efficiency of the algorithm depends on the way the paths are chosen. There are two efficient way to find the paths than barely use depth-first search  
* **Edmonds–Karp algorithm**: chooses each path so that the number of edges on the path is as small as possible. This can be done by using breadth-first search instead of depth-first search for finding paths.The time complexity of the algorithm is *`O(m^2 n)`*.  
* **Scaling algorithm**: uses depth-first search to find paths where each edge weight is at least a threshold value. Initially, the threshold value is some large number, for example the sum of all edge weights of the graph. Always when a path cannot be found, the threshold value is divided by 2. The time complexity of the algorithm is *`O(m^2 logc)`*, where `c` is the initial threshold value.    

**Minimum Cuts**   
It turns out that once the Ford–Fulkerson algorithm has found a maximum flow, it has also determined a minimum cut. Let A be the set of nodes that can be reached from the source using positive-weight edges. Now the minimum cut consists of the edges of the original graph that start at some node in A , end at some node outside A , and whose capacity(equals to 0) is fully used in the maximum flow.  

## Disjoint Paths
We are given a directed graph with a source and a sink, and our task is to find the maximum number of disjoint paths from the source to the sink.     

**Edge-disjoint paths**    
It turns out that the maximum number of edge-disjoint paths equals the maximum flow of the graph, assuming that the capacity of each edge is one.

**Node-disjoint paths**    
We can reduce also this problem to the maximum flow problem. A standard method for this is to divide each node into two nodes such that the first node has the incoming edges of the original node, the second node has the outgoing edges of the original node, and there is a new edge from the first node to the second node.    

## Maximum Matchings(In Bipartite Graphs)
The **maximum matching** problem asks to find a maximum-size set of node pairs in an undirected graph such that each pair is connected with an edge and each node belongs to at most one pair. In bipartite graphs, the bipartite maximum matching problem is much easier to solve, because we can reduce it to the **maximum flow problem** by adding two new nodes to the graph: a source and a sink. We also add edges from the source to each left node and from each right node to the sink. After this, the size of a maximum flow in the graph equals the size of a maximum matching in the original graph.    

**Hall’s theorem**   
Hall’s theorem can be used to find out whether a bipartite graph has a matching that contains all left or right nodes. If the number of left and right nodes is the same, Hall’s theorem tells us if it is possible to construct a perfect matching that contains all nodes of the graph. That for each `X`(left nodes set), the condition `|X| ≤ |f(X)|` holds.  

**Kőnig’s theorem**   
A **minimum node cover** of a graph is a minimum set of nodes such that each edge of the graph has at least one endpoint in the set. The nodes that do not belong to a minimum node cover form a **maximum independent set** that no two nodes in the set are connected with an edge.   

## Path Covers
A path cover is a set of paths in a graph such that each node of the graph belongs to at least one path. It turns out that in directed, acyclic graphs, we can
reduce the problem of finding a **minimum path cover** to the problem of finding a **maximum flow** in another graph.

**Node-disjoint path cover**   
In a **node-disjoint path cover**, each node belongs to exactly one path. To find a **minimum node-disjoint path cover**, we first construct a bipartite matching
graph where each node of the original graph is represented by two nodes: a left node and a right node. Finally, the size of the minimum node-disjoint path cover is `n − c` , where `n` is the number of nodes in the original graph and `c` is the size of the maximum matching.    

**General path cover**    
A **general path cover** is a path cover where a node can belong to more than one path. A minimum general path cover can be found almost like a minimum node-
disjoint path cover. It suffices to add some new edges to the matching graph so that there is an edge `a → b` always when there is a path from `a` to `b` in the
original graph (possibly through several edges).  

**Dilworth’s theorem**   
An **antichain** is a set of nodes of a graph such that there is no path from any node to another node using the edges of the graph. **Dilworth’s theorem** states
that in a **directed acyclic graph**, the size of a **minimum general path cover** equals the size of a **maximum antichain**.


