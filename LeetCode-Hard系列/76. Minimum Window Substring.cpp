class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        vector<int> mp(128, 0);
        int i = 0, j = 0, mi = INT_MAX, start = 0;
        
        for(auto& c : t) ++mp[c];
        
        int cnt = t.length();
        
        while(j < s.length()) {
            if(mp[s[j++]]-- > 0) --cnt;
            while(cnt <= 0) {
                if(j - i < mi)
                    mi = j - i, start = i;
                if(mp[s[i++]]++ == 0)
                    ++cnt;
            }
        }
        return mi == INT_MAX ? "" : s.substr(start, mi);
    }
};
