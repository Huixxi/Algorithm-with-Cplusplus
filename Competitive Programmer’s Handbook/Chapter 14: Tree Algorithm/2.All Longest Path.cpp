/*
11
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
7 10
7 11

output: 
The maximum height when node 1 is considered as root is 3
The maximum height when node 2 is considered as root is 4
The maximum height when node 3 is considered as root is 3
The maximum height when node 4 is considered as root is 4
The maximum height when node 5 is considered as root is 5
The maximum height when node 6 is considered as root is 5
The maximum height when node 7 is considered as root is 4
The maximum height when node 8 is considered as root is 5
The maximum height when node 9 is considered as root is 5
The maximum height when node 10 is considered as root is 5
The maximum height when node 11 is considered as root is 5
*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 100;

int in[mx];
int out[mx];

void dfs1(vector<int> adj[], int node, int parent) {
    in[node] = 0;
    for(auto n : adj[node]) {
        if(n == parent) 
            continue;
        dfs1(adj, n, node);
        in[node] = max(in[node], 1 + in[n]);
    }
}

void dfs2(vector<int> adj[], int node, int parent) {
    int mx1 = -1, mx2 = -1;

    for(auto n : adj[node]) {
        if(n == parent) 
            continue;
        if(in[n] >= mx1) {
            mx2 = mx1;
            mx1 = in[n];
        }
        else if(in[n] > mx2)
            mx2 = in[n];
    }

    for(auto n : adj[node]) {
        if(n == parent) 
            continue;

        int longest = mx1;

        if (mx1 == in[n]) 
            longest = mx2;

        out[n] = 1 + max(out[node], 1 + longest);
        dfs2(adj, n, node);
    }
}

void printHeights(vector<int> adj[], int n) { 
    // traversal to calculate in[] array 
    dfs1(adj, 1, 0); 
  
    // traversal to calculate out[] array 
    dfs2(adj, 1, 0); 
  
    // print all maximum heights 
    for (int i = 1; i <= n; i++) 
        cout << "The maximum height when node " 
             << i << " is considered as root"
             << " is " << max(in[i], out[i])  
             << "\n"; 
} 


int main() {
    auto r = freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    int p, c;
    for(int i = 1; i < n; ++i) {
        cin >> p >> c;
        adj[p].push_back(c);
        adj[c].push_back(p);
    }

    printHeights(adj, n);
    return 0;
}
