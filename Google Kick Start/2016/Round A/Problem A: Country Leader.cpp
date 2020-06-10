#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca) {
        int n;
        cin >> n;

        string tarStr;
        string str;
        getline(cin, str);
        int cnt = 0;
        vector<int> nums(27, 0);
        for(int i = 0; i < n; ++i) {
            getline(cin, str);
            for(auto c : str) {
                if(c != ' ' && nums[c - 'A'] == 0) {
                    nums[c - 'A'] = 1;
                    ++nums[26];
                }
            }
            if(nums[26] > cnt || (nums[26] == cnt && str < tarStr)) {
                tarStr = str;
                cnt = nums[26];
            }
            fill(nums.begin(), nums.end(), 0);
        }
        cout << "Case #" << ca << ": " << tarStr << endl;
    }
}
