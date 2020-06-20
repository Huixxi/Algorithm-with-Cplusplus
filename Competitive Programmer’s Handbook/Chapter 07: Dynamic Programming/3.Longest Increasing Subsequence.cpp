class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> lens(n, 0);
        for(int k = 0; k < n; ++k) {
            lens[k] = 1;
            for(int i = 0; i < k; ++i) {
                if(nums[i] < nums[k]) {
                    lens[k] = max(lens[i] + 1, lens[k]);
                }
            }
        }
        return lens[n - 1];
    }
};
