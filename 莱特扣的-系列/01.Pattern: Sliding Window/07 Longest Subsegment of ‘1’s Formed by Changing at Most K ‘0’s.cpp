#include <bits/stdc++.h>
using namespace std;

int findLen(vector<int>& nums, int k) {
    int i = 0, j = 0, l = 0, cnt = 0;
    while(j < nums.size()) {
        if(nums[j] != 1)
            ++cnt;
        while(cnt > k) {
            if(nums[i] != 1)
                --cnt;
            ++i;
        }
        l = max(l, j - i + 1);
        ++j;
    }
    return l;
}
