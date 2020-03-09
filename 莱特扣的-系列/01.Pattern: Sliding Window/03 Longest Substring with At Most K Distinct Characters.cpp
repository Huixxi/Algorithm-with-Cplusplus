#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string &s, int k) {
    // Maybe you also should check whether the number of unique characters in s is larger than k.
    if(k <= 0)
        return 0;
    unordered_map<char, int> mm;
    int i = 0, j = 0, l = 0;
    while(j < s.length()) {
        if(mm.find(s[j]) == mm.end())
            mm[s[j]] = 1;
        else
            ++mm[s[j]];
        l = max(l, j - i);
        while(mm.size() > k) {
            if(mm[s[i]] > 1)
                --mm[s[i]];
            else
                mm.erase(s[i]);
            ++i;
        }
        ++j;
    }
    return max(l, j - i);
}
