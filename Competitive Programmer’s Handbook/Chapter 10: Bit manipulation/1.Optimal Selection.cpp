/*
input.txt
3 8
6 9 5 2 8 9 1 6
8 2 6 2 7 5 7 2
5 3 9 7 3 5 1 4
The time complexity of the algorithm is O(nk2^k)
*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

int main() {
    auto r = freopen("input.txt", "r", stdin);
    int k, n;
    cin >> k >> n;
    int price[k][n];
    for(int i = 0; i < k; ++i) 
        for(int j = 0; j < n; ++j)
            cin >> price[i][j];

    vector<vector<int>> total(1<<k, vector<int>(n, MX));
    for(int d = 0; d < n; ++d)
        total[0][d] = 0;
    for(int x = 0; x < k; ++x)
        total[1<<x][0] = price[x][0];
    for(int d = 1; d < n; ++d) {
        for(int s = 0; s < (1<<k); ++s) {
            total[s][d] = total[s][d-1];
            for(int x = 0; x < k; ++x) {
                //we either do not buy any product on day d or buy a product x that belongs to S
                if(s&(1<<x))
                    total[s][d] = min(total[s][d], total[s^(1<<x)][d-1] + price[x][d]);
            }
        }
    }
    for(int i = 0; i < (1<<k); ++i) {
        for(int j = 0; j < n; ++j)
            cout << total[i][j] << " ";
        cout << endl;
    } 

    cout << total[(1<<k)-1][n-1] << endl;
    return 0;
}
