class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> mp;
        for(auto c : s) {
            ++mp[c];
        }
        int i = 0, n = s.length(), k = n/4, miLen = n;
        for(int j = 0; j < n; ++j) {
            --mp[s[j]];
            while(i < n && mp['Q'] <= k && mp['W'] <= k && mp['E'] <= k && mp['R'] <= k) {
                miLen = min(miLen, j - i + 1);
                ++mp[s[i++]];
            }
        }
        return miLen;
    }
};
