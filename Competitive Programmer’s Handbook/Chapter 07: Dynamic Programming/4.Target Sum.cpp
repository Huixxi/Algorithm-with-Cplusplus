class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto& n : nums) sum += n;
        if(S > sum || (sum + S) % 2 == 1)
            return 0;
        int target = (sum + S) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(auto& n : nums) {
            for(int a = target; a >= n; --a) {
                if(a - n >= 0) {
                    dp[a] += dp[a - n];
                }
            }
        }
        return dp[target];
    }
};
