class RangeModule {
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto it1 = itvs.upper_bound(left), it2 = itvs.upper_bound(right);
        if(it1 != itvs.begin()) {
            --it1;
            if(it1->second < left)
                ++it1;
        }
        if(it1 != it2) {
            left = min(left, it1->first);
            right = max(right, (--it2)->second);
            itvs.erase(it1, ++it2);
        }
        itvs[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = itvs.upper_bound(left);
        if(it == itvs.begin() || (--it)->second < right)
            return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto it1 = itvs.upper_bound(left), it2 = itvs.upper_bound(right);
        if(it1 != itvs.begin()) {
            --it1;
            if(it1->second < left)
                ++it1;
        }
        if(it1 == it2) return;
        
        int l = min(left, it1->first), r = max(right, (--it2)->second);
        itvs.erase(it1, ++it2);
        if(l < left) itvs[l] = left;
        if(r > right) itvs[right] = r;
    }
    
private:
    map<int, int> itvs;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
