class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int pro = 1, cnt = 0;
        for(int l = 0, r = 0; r < nums.size(); ++r) {
            pro *= nums[r];
            while(l <= r && pro >= k) {
                pro /= nums[l++];
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
};
