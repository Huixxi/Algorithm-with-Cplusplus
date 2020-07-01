typedef tuple<int, int, int> Ti;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>> adj[n];
        priority_queue<Ti, vector<Ti>, greater<Ti>> q;
        for(auto v : flights) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        q.push({0, src, K + 1});
        while(!q.empty()) {
            auto [cost, s, stops] = q.top();
            q.pop();
            if(s == dst)
                return cost;
            if(stops == 0)
                continue;
            for(auto d : adj[s]) {
                q.push({cost + d.second, d.first, stops - 1});
            }
        }
        return -1;
    }
};
