#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, j;
    cin >> t;
    while(t--) {
        cin >> n;
        int digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 1; i <= n; ++i) {
            j = i;
            while(j >= 10) {
                ++digits[j%10];
                j /= 10;
            }
            ++digits[j];
        }
        for(int k = 0; k < 9; ++k) {
            cout << digits[k] << " ";
        }
        cout << digits[9] << endl;
    }
    return 0;
}
