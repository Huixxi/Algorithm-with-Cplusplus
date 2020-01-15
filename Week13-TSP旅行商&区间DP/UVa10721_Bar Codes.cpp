#include <bits/stdc++.h>
using namespace std;

long long dp[55][55];  // dp[i][j]: use i bars to compose j units

int main(){
    int n, k, m;
    while(cin >> n >> k >> m) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= k; ++i)
            for(int j = 1; j <= n; ++j)
                for(int t = 1; t <= m && t <= j; ++t)
                    dp[i][j] += dp[i-1][j-t];
        cout << dp[k][n] << endl;
    }
    return 0;
}
