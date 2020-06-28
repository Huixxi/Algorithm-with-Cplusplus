/*
5
1 2
1 3
2 4
2 5

output: 4
*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 100;

int in[mx] = {0};
int out[mx] = {0};

int dfs(vector<int> adj[], int node, int parent) {
    int mx1 = -1, mx2 = -1;

    for(auto n : adj[node]) {
        if(n == parent) 
            continue;

        dfs(adj, n, node);

        if(in[n] >= mx1) {
            mx2 = mx1;
            mx1 = in[n];
        }
        else if(in[n] > mx2)
            mx2 = in[n];
    }
    in[node] = 1;
    if(mx1 != -1)
        in[node] += mx1;
    if(mx2 != -1)
        out[node] = 1 + mx1 + mx2;
    return max(in[node], out[node]);
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
    cout << dfs(adj, 1, 0) << endl;
    return 0;
}
