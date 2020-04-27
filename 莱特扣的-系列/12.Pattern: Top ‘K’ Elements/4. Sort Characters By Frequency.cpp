class Solution {
public:
    string frequencySort(string s) {
        int l = s.length();
        unordered_map<char, int> mm;
        for(auto& c : s)
            ++mm[c];
        priority_queue< pair<char, int>, vector<pair<char, int>>, less_comp > pq;
        for(auto& x : mm) 
            pq.push(x);
        
        string res;
        while(!pq.empty()) {
            for(int i = 0; i < pq.top().second; ++i)
                res += pq.top().first;
            pq.pop();
        }
        return res;
    }
    
    struct less_comp {
        bool operator() (pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        }  
    };
};
