class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> idx(96, -1);
        int i = 0, j = 0, l = 0;
        while(j < s.length()) {
            if(idx[s[j] - ' '] != -1) {
                l = max(l, j - i);
                i = max(i, idx[s[j] - ' '] + 1);
            }
            idx[s[j] - ' '] = j;
            ++j;
        }
        return max(l, j - i);
    }
};
