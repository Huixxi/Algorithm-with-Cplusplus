class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses, vector<int>());
        for(auto& p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
            ++inDegree[p[0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int cur = q.front();
            res.push_back(cur);
            q.pop();
            --numCourses;
            for(auto v : adjList[cur]) {
                if(--inDegree[v] == 0)
                    q.push(v);
            }
        }
        return numCourses == 0 ? res : vector<int>();
    }
};
