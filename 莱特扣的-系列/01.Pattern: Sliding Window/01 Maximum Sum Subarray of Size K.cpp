#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> nums, int k) {
    if(k > nums.size())
        return -1;
    int j = k, msum = 0;
    for(int t = 0; t < k; ++t)
        msum += nums[t];
    while(j < nums.size()) {
        msum = max(msum, msum + (nums[j] - nums[j - k]));
        ++j;
    }
    return msum;
}
