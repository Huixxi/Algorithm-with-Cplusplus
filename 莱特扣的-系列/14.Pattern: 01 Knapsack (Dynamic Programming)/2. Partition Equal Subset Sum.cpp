// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (auto& num : nums) 
            sum += num;

        if ((sum & 1) == 1) 
            return false;

        sum /= 2;

        int n = nums.size();
        bool dp[sum + 1];
        memset(dp, false, sum + 1);
        dp[0] = true;

        for (int& num : nums) {
            for (int i = sum; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[sum];
    }
};
