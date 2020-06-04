#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n && n != 0) {
        int sum = 0, cur = 0, mx = 0;
        while (n--) {
            cin >> cur;
            sum += cur;
            mx = max(sum, mx);
            if(sum < 0)
                sum = 0;
        }
        if (mx > 0)
            cout << "The maximum winning streak is " << mx << ".\n";
        else
            cout << "Losing streak.\n";
    }
}
