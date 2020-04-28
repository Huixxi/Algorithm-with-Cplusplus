class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator vi;
        
        struct comp {
            bool operator()(pair<vi, vi> p1, pair<vi, vi> p2) {
                return *p1.first > *p2.first;
            }
        };
        
        int lo = INT_MAX, hi = INT_MIN;
        priority_queue< pair<vi, vi>, vector<pair<vi, vi> >, comp> pq;  // min-heap
        for(auto& row : nums) {
            lo = min(lo, row[0]);
            hi = max(hi, row[0]);
            pq.push({row.begin(), row.end()});
        }
        vector<int> res{lo, hi};
        while(!pq.empty()) {
            auto p = pq.top();
            cout << *p.first << " ";
            pq.pop();
            ++p.first;
            if(p.first == p.second)
                break;
            pq.push(p);
            lo = *(pq.top().first);
            hi = max(hi, *p.first);
            if (hi - lo < res[1] - res[0])
                res = {lo, hi};
        }
        return res;
    }
};
