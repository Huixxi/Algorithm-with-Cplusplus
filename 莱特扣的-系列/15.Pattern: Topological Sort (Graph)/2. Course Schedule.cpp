class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);
        for(auto& p : prerequisites) {
            adjList[p[0]].push_back(p[1]); 
            ++inDegree[p[1]];  // in-degree + 1
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
            if(inDegree[i] == 0)
                q.push(i);
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            --numCourses;
            for(auto v : adjList[cur]) {
                if(--inDegree[v] == 0)
                    q.push(v);
            }
        }
        return numCourses == 0;
    }
};
