#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    while(cin >> s1 >> s2) {
        int l1 = s1.length(), l2 = s2.length();
        int l = l1 + l2;
        /*  太尼玛难想了，艹！！！
                       <-- i
            l1_ _ _0_ _ _ _-l2+1_____ (s1)
              (s2) 0_______l2-1
                   j -->
        */
        for(int i = -l2+1; i <= l1; ++i) {
            int flag = 0;
            for(int j = 0; j < l2; ++j) {
                if(i + j >= 0 && i + j < l1) {
                    if((s1[i + j] - '0') + (s2[j] - '0') > 3) {
                        flag = 1;
                        break;
                    }
                }
            }
            if(!flag) {
                 l = min(l, max(l1, i + l2) - min(i, 0));
            }
        }
        cout << l << endl;
    }
    return 0;
}
