#include <bits/stdc++.h>
using namespace std;
#define MODN 1000000

int dp[101][101];  // dp[k][n]

int main() {
    for(int k = 1; k <= 100; ++k) {
        dp[k][0] = 1;
        for(int n = 1; n <= 100; ++n) {
            dp[k][n] = (dp[k-1][n] + dp[k][n-1]) % MODN;
        }
    }

    int N, K;
    while(cin >> N >> K && N + K) {
        cout << dp[K][N] << endl;
    }
    return 0;
}
