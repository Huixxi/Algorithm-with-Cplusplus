class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n];
        int M = INT_MIN;
        deque<int> dk;  // sliding window maximum
        
        for(int i = 0; i < n; ++i) {
            dp[i] = nums[i] + max(0, dk.empty() ? 0 : dp[dk.front()]);
            while(!dk.empty() && dk.front() < i - k + 1)
                dk.pop_front();
            while(!dk.empty() && dp[i] > dp[dk.back()])
                dk.pop_back();
            dk.push_back(i);
            M = max(M, dp[i]);
        }
        
        return M;
    }
};
