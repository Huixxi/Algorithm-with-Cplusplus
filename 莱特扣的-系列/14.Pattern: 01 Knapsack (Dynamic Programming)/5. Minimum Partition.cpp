class Solution {
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums 
     */
    int findMin(vector<int> &nums) {
        int sum = 0;

        for (auto& num : nums) 
            sum += num;

        int M = sum / 2;

        int n = nums.size();
        vector<bool> dp(M + 1, false);
        dp[0] = true;

        for (int& num : nums) {
            for (int i = M; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        for (int j = M; j >= 0; --j) { 
            if (dp[j] == true) { 
                sum -= 2 * j; 
                break; 
            } 
        } 
        return sum;
    }
};
