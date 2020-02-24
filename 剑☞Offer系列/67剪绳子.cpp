class Solution {
public:
    int cutRope(int number) {
        int dp[number + 1], MAXN;
        if(number == 2)
            return 1;
        if(number == 3)
            return 2;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int n = 4; n <= number; ++n) {
            MAXN = 0;
            for(int i = 1; i <= n / 2 + 1; ++i)
                MAXN = max(MAXN, dp[i] * dp[n - i]);
            dp[n] = MAXN;
        }
        return dp[number];
    }
};
