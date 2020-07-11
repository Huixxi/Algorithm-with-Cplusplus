# Paths and Circuits
* An **Eulerian path** is a path that goes through each edge exactly once.
* A **Hamiltonian path** is a path that visits each node exactly once.

## Eulerian Paths
In an undirected graph has an Eulerian path exactly when all the edges belong to the same connected component and
* the degree of each node is even or
* the degree of exactly two nodes is odd, and the degree of all other nodes is even.

(An **Eulerian circuit** is an Eulerian path that starts and ends at the same node. In the first case, each Eulerian path is also an Eulerian circuit. In the second
case, the odd-degree nodes are the starting and ending nodes of an Eulerian path which is not an Eulerian circuit.)

In a directed graph, we focus on indegrees and outdegrees of the nodes. A directed graph contains an Eulerian path exactly when all the edges belong to
the same connected component and
* in each node, the indegree equals the outdegree, or
* in one node, the indegree is one larger than the outdegree, in another node, the outdegree is one larger than the indegree, and in all other nodes, the
indegree equals the outdegree.

**Hierholzer’s Algorithm**  
Hierholzer’s algorithm is an efficient method for constructing an Eulerian circuit. First, the algorithm constructs a circuit that contains some (not necessarily
all) of the edges of the graph. After this, the algorithm extends the circuit step by step by adding subcircuits to it. The process continues until all edges have been added to the circuit. 

## Hamiltonian Paths
If a Hamiltonian path begins and ends at the same node, it is called a **Hamiltonian circuit**.    
A simple observation is that if the graph is complete, i.e., there is an edge between all pairs of nodes, it also contains a Hamiltonian path. Also stronger
results have been achieved:
* **Dirac’s theorem**: If the degree of each node is at least `n/2`, the graph contains a Hamiltonian path.
* **Ore’s theorem**: If the sum of degrees of each non-adjacent pair of nodes is at least `n` , the graph contains a Hamiltonian path.

## De Bruijn Sequences
A **De Bruijn sequence** is a string that contains every string of length `n` exactly once as a substring, for a fixed alphabet of `k` characters. The length of such a string is `k^n + n − 1` characters. It turns out that each De Bruijn sequence corresponds to an Eulerian path in a graph.    

## Knight’s Tours
A knight’s tour corresponds to a Hamiltonian path in a graph whose nodes represent the squares of the board, and two nodes are connected with an edge if
a knight can move between the squares according to the rules of chess.    
A natural way to construct a knight’s tour is to use **backtracking**. The search can be made more efficient by using heuristics like **Warnsdorf’s rule**.

