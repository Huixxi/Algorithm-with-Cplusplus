class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        vector<int> idx{-1};
        for(int i = 0; i < n; ++i) {
            if(nums[i] & 1)
                idx.push_back(i);
        }
        idx.push_back(n);
        int m = idx.size();
        for(int i = 1; i < m - k; ++i) {
            res += (idx[i] - idx[i-1]) * (idx[i+k] - idx[i+k-1]);
        }
        
        return res;
    }
};
