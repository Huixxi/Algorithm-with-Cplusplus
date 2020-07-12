/*
Case 1:
6 0 5
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
output: 23

Case 2:
6 0 5
0 1 5
0 3 4
1 2 6
2 4 8
2 5 5
3 2 3
3 4 1
4 5 2
output: 7
*/
#include <bits/stdc++.h>
using namespace std;

// Edmonds–Karp algorithm(BFS)
bool bfs(vector<vector<int>>& adj, vector<bool>& visited, int s, int t, vector<int>& parent) {
    queue<int> q;
    q.push(s);

    visited[s] = true;
    parent[s] = -1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v = 0; v < adj.size(); ++v) {
            int w = adj[u][v];
            if(!visited[v] && w > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

void ford_fulkerson(int n, vector<vector<int>>& adj, int source, int sink) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    int u, v, max_flow = 0;
    while(bfs(adj, visited, source, sink, parent)) {
        int path_flow = INT_MAX;
        for(v = sink; v != source; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, adj[u][v]);
        }
        for(v = sink; v != source; v = parent[v]) {
            u = parent[v];
            adj[u][v] -= path_flow;
            adj[v][u] += path_flow;
        }
        max_flow += path_flow;
        visited = vector<bool>(n, false);
    }
    cout << max_flow << endl;
}

void minimum_cut(int n, vector<vector<int>>& adj, int source, int sink) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    int u, v;
    bfs(adj, visited, source, sink, parent);
    vector<pair<int, int>> minCut;
    for(u = 0; u < n; ++u) {
        if(visited[u]) {
            for(v = 0; v < n; ++v) {
                if(!visited[v] && adj[u][v] == 0 && adj[v][u] > 0)
                    minCut.push_back({u, v});
            }
        }
    }
    for(auto p : minCut)
        cout << p.first << "--" << p.second << endl;
}


int main() {
    auto r = freopen("input.txt", "r", stdin);
    int n, source, sink, s, t, w;  // node: 0-n
    cin >> n >> source >> sink;
    vector<vector<int>> adj(n, vector<int>(n, 0));

    while(cin >> s >> t >> w) 
        adj[s][t] = w;
    
    ford_fulkerson(n, adj, source, sink);
    minimum_cut(n, adj, source, sink);
    return 0;
}
