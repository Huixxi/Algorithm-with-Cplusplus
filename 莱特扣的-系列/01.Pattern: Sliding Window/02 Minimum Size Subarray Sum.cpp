#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int i = 0, j = 0, sum = 0, l = 10000;
    if(nums.size() == 0)
        return 0;
    while(j < nums.size()) {
        while(sum < s && j < nums.size()) 
            sum += nums[j++];
        if(sum < s && l == 10000)
            return 0;
        while(sum >= s) 
            sum -= nums[i++];
        l = min(l, j - i + 1);
    }
    return l;
}
