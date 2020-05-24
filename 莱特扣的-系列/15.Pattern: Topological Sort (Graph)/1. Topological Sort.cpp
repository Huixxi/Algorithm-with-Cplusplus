void TopologicalSortUnit(int v, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& stk) {
    visited[v] = true;
    for(auto x : adjList[v]) {
        if(!visited[x])
            TopologicalSortUnit(x, adjList, visited, stk);
    }
    stk.push(v);
}

void TopologicalSort(vector<vector<int>>& adjList) {
    stack<int> stk;
    const int n = adjList.size();
    vector<bool> visited(n, false);
    for(int v = 0; v < n; ++v) {
        if(!visited[v])
            TopologicalSortUnit(v, adjList, visited, stk);
    }
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
}
