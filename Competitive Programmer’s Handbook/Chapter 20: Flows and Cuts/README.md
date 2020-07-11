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
