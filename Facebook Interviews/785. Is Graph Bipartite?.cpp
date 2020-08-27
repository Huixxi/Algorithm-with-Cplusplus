class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int coloring[n];
        for(int i = 0; i < n; ++i) {
            memset(coloring, -1, sizeof(coloring));
            if(!dfs(graph, coloring, i, 1))
                return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, int coloring[], int pos, int color) {
        if(coloring[pos] != -1 && coloring[pos] != color)
            return false;
        coloring[pos] = color;
        for(auto v : graph[pos]) {
            if((coloring[v] == -1 && !dfs(graph, coloring, v, 1 - color)) || (coloring[v] != -1 && coloring[v] != 1 - color))
                return false;
        }
        return true;
    }
};
