class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        auto it = mp.upper_bound(val);
        if(it != mp.begin()) {
            int a = it->first, b = it->second;
            --it;
            if(it->second >= val) 
                return;
            
            if(it->second == val - 1 && a == val + 1) {
                it->second = b;
                mp.erase(++it);
            }
            else if(it->second == val - 1) {
                it->second = val;
            }
            else if(a == val + 1) {
                mp.erase(++it);
                mp[val] = b;
            }
            else
                mp[val] = val;
        }
        else {
            if(it->first == val + 1) {
                mp[val] = it->second;
                mp.erase(it);   
            }
            else 
                mp[val] = val;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto& m : mp) {
            res.push_back({m.first, m.second});
        }
        return res;
    }
    
private:
    map<int, int> mp;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
