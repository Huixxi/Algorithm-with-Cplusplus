/*
7
1 2
1 3
2 4
2 5
3 7
4 6

output: 5
*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 100;

int x = 0, mxcnt = INT_MIN;

int dfs(vector<int> adj[], int cnt, int node, int parent) {
    ++cnt;
    for(auto n : adj[node]) {
        if(n == parent) 
            continue;
        if(cnt >= mxcnt) {
            mxcnt = cnt;
            x = n;
        }
        dfs(adj, cnt, n, node);
    }
}

int diameter(vector<int> adj[]) {
    dfs(adj, 0, 1, 0);  // arbitrary start node, we choose 1 here.
    cout << mxcnt << " " << x << endl;  // 3 6
    dfs(adj, 0, x, 0);
    return mxcnt;
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
    cout << diameter(adj) << endl;
    return 0;
}
