class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mm;
        for(auto& n : nums) {
            ++mm[n];
        }
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater_comp > pq;
        for(auto& x : mm) {
            pq.push(x);
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
    
    struct greater_comp {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }  
    };
};
