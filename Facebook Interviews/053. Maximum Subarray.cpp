class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // use divide and conquer
        return divCon(nums, 0, nums.size() - 1);
    }
    
    int divCon(vector<int>& nums, int l, int r) {
        if(l > r)
            return INT_MIN;
        int m = l + (r - l) / 2;
        int lmax = divCon(nums, l, m - 1);
        int rmax = divCon(nums, m + 1, r);
        int ml = 0, mr = 0;
        for(int i = m - 1, sum = 0; i >= l; --i) {
            sum += nums[i];
            ml = max(ml, sum);
        }
        for(int i = m + 1, sum = 0; i <= r; ++i) {
            sum += nums[i];
            mr = max(mr, sum);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};
