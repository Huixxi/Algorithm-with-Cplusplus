# Shortest Paths(In a weighted graph)

## Corresponding Problems on LeetCode
* [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
* [568. Maximum Vacation Days](https://xinjiema.gitbooks.io/leetcode/maximum-vacation-days.html)

## Bellman-Ford Algorithm(`O(nm)`)
The **Bellman–Ford algorithm** finds shortest paths from a starting node to all nodes of the graph. The algorithm can process all kinds of graphs, provided that the graph does not contain a cycle with negative length. If the graph contains a negative cycle, the algorithm can detect this. The algorithm reduces the distances by finding edges that shorten the paths until it is not possible to reduce any distance. If there are no negative cycles in the graph, all distances are final after `n − 1` rounds, because each shortest path can contain at most `n − 1` edges. A negative cycle can be detected using the Bellman–Ford algorithm by running the algorithm for `n` rounds.   
```c++
for(int i = 1; i <= n; i++) distance[i] = INF;
distance[x] = 0;
for(int i = 1; i <= n-1; i++) {
    for(auto e : edges) {
        int a, b, w;
        tie(a, b, w) = e;
        distance[b] = min(distance[b], distance[a] + w);
    }
}
```

## SPFA Algorithm(Shortest Path Faster Algorithm)
The algorithm maintains a queue of nodes that might be used for reducing the distances. First, the algorithm adds the starting node x to the queue. Then, the algorithm always processes the first node in the queue, and when an edge `a → b` reduces a distance, node b is added to the queue.   

## Dijkstra’s Algorithm(`O(n + mlogm)`)
Dijkstra’s algorithm finds shortest paths from the starting node to all nodes of the graph, that it is more efficient and can be used for processing large graphs, but remember that the algorithm requires there are no negative weight edges in the graph.   
```c++
priority_queue<pair<int, int>> q;
for (int i = 1; i <= n; i++) distance[i] = INF;
distance[x] = 0;
q.push({0,x});
while(!q.empty()) {
    int a = q.top().second; q.pop();
    if(processed[a]) continue;
    processed[a] = true;
    for(auto u : adj[a]) {
        int b = u.first, w = u.second;
        if(distance[a]+w < distance[b]) {
            distance[b] = distance[a] + w;
            q.push({-distance[b],b});
        }
    }
}
```

## Floyd–Warshall algorithm(`O(n^3)`)
The algorithm maintains a two-dimensional array that contains distances between the nodes. First, distances are calculated only using direct edges between the nodes, and after this, the algorithm reduces distances by using intermediate nodes in paths.
```c++
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
        if (i == j) distance[i][j] = 0;
        else if (adj[i][j]) distance[i][j] = adj[i][j];
        else distance[i][j] = INF;
    }
}

for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            distance[i][j] = min(distance[i][j],
            distance[i][k]+distance[k][j]);
        }
    }
}
```



