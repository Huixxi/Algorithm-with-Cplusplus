class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, mx = 0;
        for (auto& num : nums) 
            sum += num;

        if ((sum & 1) == 1) 
            return false;

        sum /= 2;
        
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for(auto& n : nums) {
            for(int i = sum - n; i >= 0; --i) 
                if(dp[i])
                    dp[i + n] = true;
        }
        return dp[sum];
    }
}
