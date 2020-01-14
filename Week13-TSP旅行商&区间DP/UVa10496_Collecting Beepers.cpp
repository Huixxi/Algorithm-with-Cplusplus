#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1<<11][11];  // space complexity: 2^n * n
int dist[11][11];  // distance between each points pair
int ans;
struct coords {
    int x, y;
} xy[11];

void TSP(int s, int i, int s_size) {
    // s_size = 0, 1, 2, ..., n
    if(s_size == N) {
        ans = min(dp[s][i] + dist[i][0], ans);
        return;
    }
    for(int j = 1; j <= N; ++j) {  // 只走除0点以外的点
        if(!(s & (1 << j))) {
            // ss = s + {j}, bottom-up
            int ss = s | (1 << j);
            if(!dp[ss][j] || dp[s][i] + dist[i][j] < dp[ss][j]) {
                dp[ss][j] = dp[s][i] + dist[i][j];
                TSP(ss, j, s_size+1);
            }
        }
    }
}

int main(){
    int T, X, Y;
    cin >> T;
    while(T--) {
        cin >> X >> Y >> xy[0].x >> xy[0].y >> N;  // N <= 10
        for(int i = 1; i <= N; ++i) {
            cin >> xy[i].x >> xy[i].y;
        }
        for(int i = 0; i < N; ++i) {
            for(int j = i+1; j <= N; ++j) {
                dist[i][j] = abs(xy[i].x - xy[j].x) + abs(xy[i].y - xy[j].y);
                dist[j][i] = dist[i][j];
            }
        }
        ans = int(1e9);
        TSP(0, 0, 0);
        cout << "The shortest path has length " << ans << endl;
    }

    return 0;
}
