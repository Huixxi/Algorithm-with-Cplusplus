# Strong Connectivity(强连通图)
A directed graph is **strongly connected** if there is a path from any node to all other nodes in the graph.   

The **strongly connected components(强连通分量)** of a graph divide the graph into strongly connected parts that are as large as possible. The strongly connected components form an acyclic **component graph** that represents the deep structure of the original graph.  

## Kosaraju’s Algorithm(`O(n+m)`)
Detailed explain: [Strongly Connected Components Kosaraju's Algorithm Graph Algorithm](youtube.com/watch?v=RpgcYiky7uw)    

Kosaraju’s algorithm is an efficient method for finding the strongly connected components of a directed graph. The algorithm performs two depth-first searches:
* Search 1: constructs a list of nodes in the order of their timestep that a depth-first search finish processes them.
* Search 2: reverses every edge in the graph, then use a depth-first search to form the strongly connected components.

## 2SAT problem
In this problem, we are given a logical formula **(a1 ∨ b1) ∧ (a2 ∨ b2) ∧ · · · ∧ (am ∨ bm)**, our task is to assign each variable a value so that the
formula is **true**, or state that this is **not possible**. The 2SAT problem can be represented as a directed graph whose nodes correspond to variables `xi` and negations `¬xi`, and edges determine the connections between the variables. And in the graph of the formula if there are no nodes `xi` and `¬xi` such that both
nodes belong to the same strongly connected component, so a solution exists.
