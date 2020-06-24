/*
10 5
2 3 3 5 6

output: 2
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    auto r = freopen("input.txt", "r", stdin);
    int x, n;
    cin >> x >> n;
    int wt[n];
    for(int i = 0; i < n; ++i) {
        cin >> wt[i];
    }
    // rides(S): the minimum number of rides for a subset S 
    // last(S): the minimum weight of the last ride
    pair<int, int> best[1<<n];  // pair(rides(S), last(S))
    best[0] = {1, 0};
    for(int s = 1; s < (1<<n); ++s) {
        best[s] = {n+1, 0};
        for(int p = 0; p < n; ++p) {
            if(s&(1<<p)) {
                auto option = best[s^(1<<p)];
                if(option.second + wt[p] <= x) {
                    // add p to an existing ride
                    option.second += wt[p];
                }
                else {
                    // reserve a new ride for p
                    ++option.first;
                    option.second = wt[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }
    cout << best[(1<<n) - 1].first << endl;
    return 0;
}
