class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for(int i = 0; i < n; ++i)
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        for(int i = 0; i < n; ++i)
             startTime[i] = jobs[i][0], endTime[i] = jobs[i][1], profit[i] = jobs[i][2];
        vector<int> dp(n, 0);
        dp[n - 1] = profit[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            auto it = lower_bound(startTime.begin() + i, startTime.end(), endTime[i]);
            if(it != startTime.end())
                dp[i] += max(dp[i + 1], dp[it - startTime.begin()] + profit[i]);
            else
                dp[i] += max(dp[i + 1], profit[i]);
        }
        return dp[0];
    }
};
