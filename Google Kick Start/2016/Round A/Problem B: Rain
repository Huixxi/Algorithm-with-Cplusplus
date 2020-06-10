/* The Same as LeetCode 407 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> heightMap(R, vector<int>(C, 0));
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                cin >> heightMap[i][j];
            }
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 右下左上
        vector<int> nstep{m, n-1};
        int i = 0, j = -1;
        int idir = 0;
        vector<vector<int>> vist(n, vector<int>(m, 0));
        // 将边缘的高度值先放入优先队列中，并打标签
        while(nstep[idir % 2]) {
            for(int c = 0; c < nstep[idir % 2]; ++c) {
                i += dirs[idir][0];
                j += dirs[idir][1];
                pq.push({heightMap[i][j], {i, j}});
                vist[i][j] = 1;
            }
            --nstep[idir % 2];
            ++idir;
            if(idir == 4)
                break;
        }
        int res = 0, mxheight = INT_MIN;
        // 对优先队列进行操作，每次取出队列中最小的高度，并扫描其相邻的四个节点。
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            i = tp.second.first, j = tp.second.second;
            mxheight = max(mxheight, tp.first);
            for(auto dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if(vist[ni][nj])
                        continue;
                    if(heightMap[ni][nj] < mxheight) {
                        res += mxheight - heightMap[ni][nj];
                    }
                    vist[ni][nj] = 1;
                    pq.push({heightMap[ni][nj], {ni, nj}});
                }
            }
        }
        cout << "Case #" << ca << ": " << res << endl;
    }
}
