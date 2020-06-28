/*
14
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
4 10
5 11
5 12
7 13
7 14
3 2 1 10 1 3 9 1 5 3 4 5 9 8

output: 22
*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 100;

int dp[mx];

void dfs(vector<int>& val, vector<int> adj[], int node) {
    dp[node] = val[node];
    int maxium = 0;
    for(auto n : adj[node]) {
        dfs(val, adj, n);
        maxium = max(maxium, dp[n]);
    }
    dp[node] += maxium;
}

int main() {
    auto r = freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    vector<int> val(n + 1, 0);
    int p, c;
    for(int i = 1; i < n; ++i) {
        cin >> p >> c;
        adj[p].push_back(c);
    }
    for(int i = 1; i <= n; ++i)
        cin >> val[i];

    dfs(val, adj, 1);
    cout << dp[1] << endl;
    return 0;
}
