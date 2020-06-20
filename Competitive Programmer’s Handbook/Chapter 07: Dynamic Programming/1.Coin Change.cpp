class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10000);
        dp[0] = 0;
        for(int a = 1; a <= amount; ++a) {
            for(auto c : coins) {
                if(a - c >= 0)
                    dp[a] = min(dp[a - c] + 1, dp[a]);
            }
        }
        return dp[amount] == 10000 ? -1 : dp[amount];        
    }
};
