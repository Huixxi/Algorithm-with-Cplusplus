class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0, idx = 0, x = 0, y = 0;
        for(auto n : nums) a ^= n;
        while(!(a & (1 << idx))) ++idx;
        
        for(auto n : nums) {
            if(n & (1 << idx))
                x ^= n;
            else 
                y ^= n;
        }
        return vector<int>{x, y};
    }
};
