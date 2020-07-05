/*
Case 1:
7
1 2
1 4
2 1
2 5
3 2
3 7
5 4
6 5
6 3
7 6

output: 
3 6 7 
1 2 
5 
4 

Case 2:
11
1 2
2 3
2 4
3 1
4 5
5 6
6 4
7 6
7 8
8 9
9 10
10 7
10 11

output:
7 10 9 8 
11 
1 3 2 
4 6 5 
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<bool>& visited, stack<int>& stk, int node) {
    visited[node] = true;
    for(auto n : adj[node]) {
        if(!visited[n]) {
            dfs(adj, visited, stk, n);
        }
    }
    stk.push(node);
}

void rdfs(vector<int> adj[], vector<bool>& visited, int node) {
    cout << node << " ";
    visited[node] = true;
    for(auto n : adj[node]) {
        if(!visited[n]) {
            rdfs(adj, visited, n);
        }
    }
}


int main() {
    auto r = freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    vector<int> radj[n + 1];
    vector<bool> visited(n + 1, false);
    vector<vector<int>> res;
    vector<int> tmp;
    stack<int> stk;
    int s, e;
    while(cin >> s >> e) {
        adj[s].push_back(e);
        radj[e].push_back(s);
    }
    for(int i = 1; i <= n; ++i)
        if(!visited[i])
            dfs(adj, visited, stk, i);
    visited = vector<bool>(n, false);
    while(!stk.empty()) {
        int i = stk.top();
        stk.pop();
        if(!visited[i]) {
            rdfs(radj, visited, i);
            cout << endl;
        }
    }

    return 0;
}
