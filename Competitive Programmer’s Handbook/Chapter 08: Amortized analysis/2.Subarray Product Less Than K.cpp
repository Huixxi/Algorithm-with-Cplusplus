class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), res = 0, pro = 1;
        while(j < n) {
            pro *= nums[j];
            while(pro >= k && i <= j) {
                pro /= nums[i];
                ++i;
            }
            res += (j - i + 1);
            ++j;
        }
        return res;
    }
};
