class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<double, int>> adj[n];
        for(int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }
        vector<bool> visited(n, false);
        vector<double> prob(n, 0.0); prob[start] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            if(visited[p.second]) continue;
            visited[p.second] = true;
            for(auto x : adj[p.second]) {
                double w = x.first; int v = x.second;
                if(prob[p.second] * w > prob[v]) {
                    prob[v] = prob[p.second] * w;
                    pq.push({prob[v], v});
                }
            }
        }
        return prob[end];
    }
};
