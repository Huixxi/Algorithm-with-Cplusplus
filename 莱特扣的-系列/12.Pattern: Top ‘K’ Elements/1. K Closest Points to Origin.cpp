class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        for(auto& p : points) {
            pq.push(p);
            if(pq.size() > K)
                pq.pop();
        }
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
    
    struct comp {
        bool operator() (vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }
    };  
};
